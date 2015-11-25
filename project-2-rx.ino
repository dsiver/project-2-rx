/*
 * Project 2 Receiver
 * Board: Arduino UNO or similar with ATmega328P
 * Relay: Parallax, Inc. Single Relay Board (#27115)
 *
 * David Siver
 * CS 4985
 * Fall 2015
 */

#include <VirtualWire.h>
#define RELAY_PIN 7
#define RELAY_NO_CLOSED HIGH
#define RELAY_NO_OPEN LOW
#define RELAY_LED_PIN 6
#define RX_PIN 3
#define RX_LED_PIN 2
#define OFF "off"
#define ON "on"
#define NONE "none"

String relayStatus;

void setup() {
  relayStatus = OFF;
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY_LED_PIN, OUTPUT);
  pinMode(RX_LED_PIN, OUTPUT);
  //toggleRelay(ON);
  toggleLED(ON, RELAY_LED_PIN);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_set_rx_pin(2);
  vw_rx_start();
  delay(2000);
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) {
    toggleLED(ON, RX_LED_PIN);
    Serial.print("Message: ");
    for (int i = 0; i < buflen; i++) {
      Serial.print(buf[i]);
    }
    Serial.println("");
  } else {
    toggleLED(OFF, RX_LED_PIN);
  }
}

void cycleRelay(int times) {
  for (int i = 0; i < times; i++) {
    //toggleRelay(OFF);
    toggleLED(OFF, RELAY_LED_PIN);
    delay(500);
    //toggleRelay(ON);
    toggleLED(ON, RELAY_LED_PIN);
    delay(500);
  }
}

void toggleLED(String mode, int pin) {
  if (mode == ON) {
    digitalWrite(pin, HIGH);
    //Serial.println("LED ON");
  }
  else if (mode == OFF) {
    digitalWrite(pin, LOW);
    //Serial.println("LED OFF");
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

void test() {
  for (int i = 0; i < 3; i++) {
    toggleLED(ON, RX_LED_PIN);
    toggleLED(OFF, RELAY_LED_PIN);
    toggleRelay(OFF);
    delay(500);
    toggleLED(OFF, RX_LED_PIN);
    toggleLED(ON, RELAY_LED_PIN);
    toggleRelay(ON);
    delay(500);
  }
}
