/**
 * Tp6 Projet banc connecté
 * Auteur: Jeff Truong
 * Date: 13 Mai 2025
 * Desc: Ce code indique si le chargeur par induction est présentement en utilisation
*/

#include <LED.h>
#include <Adafruit_NeoPixel.h>

void start_LED() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
 // clock_prescale_set(clock_div_1);
#endif

  pixels.setPin(1);
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
}

void GestionLED ()
{
   pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(150, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  }
}