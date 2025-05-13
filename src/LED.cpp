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

void GestionLED (bool Chargement, bool DarkMode)
{
  pixels.clear();

  uint8_t r = 0, g = 0, b = 0;

  if (Chargement) 
  {
    r = 150; g = 0; b = 0;  // Rouge
  } 
  else 
  {
    r = 150; g = 150; b = 0;  // Jaune
  }

  // Diminuer l'intensité si c'est sombre
  if (DarkMode) 
  {
    r /= 5; g /= 5; b /= 5;
  }
  for (int i = 0; i < NUMPIXELS; i++) 
  {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }

  pixels.show();

}