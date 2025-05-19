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
  pixels.clear();
  pixels.show();
}

void Red() {
  pixels.clear();
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0)); //Rouge
  }
  pixels.show();
  
}

void Yellow() {
  pixels.clear();
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 255, 0)); //Jaune
  }
  pixels.show();
}

void GestionLED(bool Chargement, bool DarkMode) {
  if (DarkMode) 
  {
    pixels.setBrightness(BRIGHTNESS / 5);  // Atténuer si sombre
  }
  else 
  {
    pixels.setBrightness(BRIGHTNESS);      // Luminosité normale
  }

  if (Chargement) 
  {
    Red();    // Utilise ta fonction Red()
  } 
  else 
  {
    Yellow(); // Utilise ta fonction Yellow()
  }
}
