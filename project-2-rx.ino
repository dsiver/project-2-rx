/*
 * Project 2 Receiver
 * Board: Arduino UNO or similar with ATmega328P
 * Relay: Parallax, Inc. Single Relay Board (#27115)
 *
 * David Siver
 * CS 4985
 * Fall 2015
 */

#define RELAY_PIN 7
#define RELAY_NO_CLOSED HIGH
#define RELAY_NO_OPEN LOW

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  delay(5000);
  digitalWrite(RELAY_PIN, RELAY_NO_CLOSED);
  Serial.println("RELAY_NO_CLOSED");
  delay(1000);
  digitalWrite(RELAY_PIN, RELAY_NO_OPEN);
  Serial.println("RELAY_NO_OPEN");
}

void loop() {
  // put your main code here, to run repeatedly:

}
