/**
 * Tp6 Projet banc connecté
 * Auteur: Jeff Truong
 * Date: 22 Mai 2025
 * Desc: Ce code indique si le chargeur par induction est présentement en utilisation
*/

#ifndef LED_H
#define LED_H
#endif

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
#include <avr/power.h>
#endif


#define PIN        1
#define NUMPIXELS 10
#define BRIGHTNESS 25 // Set BRIGHTNESS to about 1/5 (max = 255)
#define DELAYVAL   500

extern Adafruit_NeoPixel pixels;

void start_LED();
void GestionLED(bool Chargement, bool DarkMode);