#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 7

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Replace with actual RFID UIDs from your cards
String registeredUID[] = {"A1B2C3D4", "E5F6G7H8"};

void setup() {
    Serial.begin(9600);
    SPI.begin();
    rfid.PCD_Init();
    lcd.begin();
    lcd.backlight();
    pinMode(LED_PIN, OUTPUT);
    lcd.setCursor(0, 0);
    lcd.print("Scan your card");
}

void loop() {
    if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
        return;
    }

    String uidString = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
        uidString += String(rfid.uid.uidByte[i], HEX);
    }
    
    Serial.print("Card UID: ");
    Serial.println(uidString);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Checking...");
    
    if (isRegistered(uidString)) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Attendance Marked");
        lcd.setCursor(0, 1);
        lcd.print(uidString);
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Attendance recorded");
        delay(2000);
        digitalWrite(LED_PIN, LOW);
    } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Denied");
        Serial.println("Unregistered Card");
        delay(2000);
    }
    
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Scan your card");
}

bool isRegistered(String uid) {
    for (int i = 0; i < 2; i++) {  // Change 2 to number of registered cards
        if (uid.equalsIgnoreCase(registeredUID[i])) {
            return true;
        }
    }
    return false;
}
