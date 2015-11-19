/*
 * Project 2 Receiver
 * Board: Arduino UNO or similar with ATmega328P
 * Relay: Parallax, Inc. Single Relay Board (#27115)
 *
 * David Siver
 * CS 4985
 * Fall 2015
 */

#define RELAY_PIN 14
#define RELAY_NO_CLOSED HIGH
#define RELAY_NO_OPEN LOW
#define RELAY_LED_PIN 13
#define OFF "off"
#define ON "on"
#define NONE "none"

String relayStatus;

void setup() {
  relayStatus = OFF;
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY_LED_PIN, OUTPUT);
}

void loop() {
  toggleLED(OFF, RELAY_LED_PIN);
  toggleRelay(OFF);
  delay(2000);
  toggleLED(ON, RELAY_LED_PIN);
  toggleRelay(ON);
  delay(2000);
}

void toggleLED(String mode, int pin) {
  if (mode == ON) {
    digitalWrite(pin, HIGH);
    Serial.println("LED ON");
  }
  else if (mode == OFF) {
    digitalWrite(pin, LOW);
    Serial.println("LED OFF");
  }
}

void toggleRelay(String mode) {
  if (mode == ON) {
    digitalWrite(RELAY_PIN, RELAY_NO_CLOSED);
    relayStatus = ON;
    Serial.println("RELAY_NO_CLOSED");
  }
  else if (mode == OFF) {
    digitalWrite(RELAY_PIN, RELAY_NO_OPEN);
    relayStatus = OFF;
    Serial.println("RELAY_NO_OPEN");
  }
}
