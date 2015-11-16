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
#define LED_PIN 8
#define OFF "off"
#define ON "on"

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  test();
}

void test(){
  toggleRelay(ON);
  toggleLED(ON);
  delay(5000);
  toggleRelay(OFF);
  toggleLED(OFF);
  delay(5000);
}

void toggleLED(String mode){
  if(mode == ON){
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON");
  }
  else if(mode == OFF){
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");
  }
}

void toggleRelay(String mode){
  if(mode == ON){
    digitalWrite(RELAY_PIN, RELAY_NO_CLOSED);
    Serial.println("RELAY_NO_CLOSED");
  }
  else if(mode == OFF){
    digitalWrite(RELAY_PIN, RELAY_NO_OPEN);
    Serial.println("RELAY_NO_OPEN");
  }
}
