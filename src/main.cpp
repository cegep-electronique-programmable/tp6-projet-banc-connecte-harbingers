/**
 * Tp6 Projet banc connecté
 * Auteur: Jeff Truong, Sonia Michaud, del Pozo Catalan César Antonio
 * Date: 22 Mai 2025
 * Desc: Le code principal
*/

#include <Arduino.h>
#include <LED.h>
#include "affichage.h"
#include "capteur.h"


#define PIN_CHARGEUR A0
#define SEUIL_TENSION 1000  // À ajuster

APDS9930 apds = APDS9930();



// the setup function runs once when you press reset or power the board
void setup() 
{
  pinMode(PIN_CHARGEUR, INPUT);
  Serial.begin(9600);
  start_LED();
  
  // Initialisation du capteur APDS-9930
  if (apds.init()) 
  {
    apds.setProximityGain(PGAIN_2X);
    apds.enableProximitySensor(false);
    apds.enableLightSensor(false);
    Serial.println("Capteur initialisé");
  }
  else
  {
    //Serial.println("Skill issue ma guy");
    Serial.println("Erreur d'initialisation du capteur APDS-9930");
  }
}

// the loop function runs over and over again forever
void loop()
{
  float ambient_light = 0;
  bool DarkMode = false;
  bool Chargement = false;

  // Lecture de la lumière ambiante
  if (apds.readAmbientLightLux(ambient_light)) 
  {
    DarkMode = ambient_light < 10.0;    // Seuil à ajuster
    Serial.print("Lumière ambiante: ");
    Serial.println(ambient_light);
  } 
  else 
  {
    Serial.println("Erreur lecture lumière");
  }

  // Lecture tension du chargeur
  int lecture = analogRead(PIN_CHARGEUR);
  Serial.print("Tension lue (chargeur): ");
  Serial.println(lecture);
  Chargement = lecture > SEUIL_TENSION;

  // Mise à jour des DEL
  GestionLED(Chargement, DarkMode);
  delay(500);                
} 


