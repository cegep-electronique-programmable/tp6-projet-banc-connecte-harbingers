/**
 * Tp6 Projet banc connecté
 * Auteur: Jeff Truong, Sonia Michaud, del Pozo Catalan César Antonio
 * Date: 13 Mai 2025
 * Desc: Le code principal
*/

#include <Arduino.h>
#include <LED.h>
#include "affichage.h"
#include <Adafruit_NeoPixel.h>

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  start_LED();
}

// the loop function runs over and over again forever
void loop() {
  GestionLED();
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for 1second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(100);                      // wait for 100ms
} 


