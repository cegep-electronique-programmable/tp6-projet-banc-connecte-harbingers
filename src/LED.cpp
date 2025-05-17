/**
 * Tp6 Projet banc connecté
 * Auteur: Jeff Truong
 * Date: 22 Mai 2025
 * Desc: Ce code indique si le chargeur par induction est présentement en utilisation
*/

#include <LED.h>

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void start_LED() 
{
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
  pixels.show();
}

void Red() {
  pixels.clear();
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0)); //Rouge
    delay(DELAYVAL);
  }
  pixels.show();
}

void Yellow() {
  pixels.clear();
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(250, 250, 0)); //Jaune
    delay(DELAYVAL);
  }
  pixels.show();
}
