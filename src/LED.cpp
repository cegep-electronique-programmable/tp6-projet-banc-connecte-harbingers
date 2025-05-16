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

  uint8_t g = 0, r = 0, b = 0;

  if (Chargement) 
  {
    g = 255; r = 0; b = 0;  // Rouge
  } 
  else 
  {
    g = 0; r = 0; b = 0;  // Jaune
  }
 /* 
  // Diminuer l'intensité si c'est sombre
  if (DarkMode) 
  {
    g = 5; r = 5; b = 5;
  }
  for (int i = 0; i < NUMPIXELS; i++) 
  {
    pixels.setPixelColor(i, pixels.Color(g, r, b));
  }
 */
  pixels.setPixelColor(0, pixels.Color(255, 0, 0)); 
  pixels.show();
 
}