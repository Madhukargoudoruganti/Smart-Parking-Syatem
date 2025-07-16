#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 22
#define SS_PIN  21
#define BUTTON1  4 
#define BUTTON2  5
MFRC522 rfid(SS_PIN, RST_PIN);
const int MAX_CARDS = 10;
String registeredUIDs[MAX_CARDS];
unsigned long entryTimes[MAX_CARDS];
bool isRegistered[MAX_CARDS];
bool registrationMode = true;
int registeredCount = 0;
void setup() {
  Serial.begin(115200);
  SPI.begin(); 
  rfid.PCD_Init(); 
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  Serial.println("System Initialized. Ready for RFID scan...");
  Serial.println("Press BUTTON1 to stop registration");
}
void loop() {
  if (digitalRead(BUTTON2) == LOW) {
    registrationMode = true;
    Serial.println("Entered Registration Mode. Scan RFID tags...");
    delay(500);
  }
  if (digitalRead(BUTTON1) == LOW) {
    registrationMode = false;
    Serial.println("Registration Complete. Waiting for entry/exit scans...");
    delay(500);
  }
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;
  String uid = getUIDString();
  if (registrationMode) {
    registerCard(uid);
  } else {
    int index = findCard(uid);
    if (index != -1) {
      handleEntryExit(index);
    } else {
      Serial.println("This RFID is not registered.");
    }
  }
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
String getUIDString() {
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();
  return uid;
}
void registerCard(String uid) {
  if (registeredCount < MAX_CARDS && findCard(uid) == -1) {
    registeredUIDs[registeredCount] = uid;
    isRegistered[registeredCount] = false;
    entryTimes[registeredCount] = 0;
    Serial.print("Registered RFID: ");
    Serial.println(uid);
    registeredCount++;
  } else {
    Serial.println("RFID already registered or storage full.");
  }
}
int findCard(String uid) {
  for (int i = 0; i < registeredCount; i++) {
    if (registeredUIDs[i] == uid) {
      return i;
    }
  }
  return -1;
}
void handleEntryExit(int index) {
  if (!isRegistered[index]) {
    entryTimes[index] = millis();
    isRegistered[index] = true;
    Serial.print("Entry recorded for ");
    Serial.println(registeredUIDs[index]);
  } else {
    unsigned long duration = (millis() - entryTimes[index]) / 60000; 
    duration = duration == 0 ? 1 : duration;  
    int fee = duration * 10;
    Serial.print("Exit recorded for ");
    Serial.println(registeredUIDs[index]);
    Serial.print("Duration (minutes): ");
    Serial.println(duration);
    Serial.print("Parking Fee: ₹");
    Serial.println(fee);
    isRegistered[index] = false;
  }
}