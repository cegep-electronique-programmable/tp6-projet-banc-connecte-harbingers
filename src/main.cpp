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

APDS9930 apds = APDS9930();

#define PIN_CHARGEUR A0
#define SEUIL_TENSION 1000  // À ajuster

//Variables globales
uint16_t nbrPersonnes = 0;
bool memePersonne = 0;

// the setup function runs once when you press reset or power the board
void setup() 
{
  pinMode(PIN_CHARGEUR, INPUT);
  Serial.begin(9600);
  start_LED();
  setup_capteur();
}

// the loop function runs over and over again forever
void loop()
{
  // float ambient_light = 0;
  bool DarkMode = false;
  bool Chargement = true;

  float luminosity = GestionCapteurLuminosity();
  uint16_t proximity = GestionCapteurProximity();

  // Ne pas augmenter le compte de personnesi c'est (en théorie) la même personne
  if(memePersonne){
    // Si la personne pars permettre de vérifier s'il y a une nouvelle personnes
    if(proximity < 600){
      memePersonne = 0;
    }
  }
  // S'il y a une personne qui est proche
  else if(proximity >= 600){
    // Augmenter la valeur du nombres de personnes passées
    nbrPersonnes++;
    memePersonne = 1;
  }
  
  //============= À effacer lorsque vous aurez utilisé les variables ==============
  /*
  Serial.println(luminosity);
  Serial.println(proximity);
  */
  
/*   // Lecture de la lumière ambiante
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
  Chargement = lecture > SEUIL_TENSION; */

  // Mise à jour des DEL
  GestionLED(Chargement, DarkMode);
  delay(500);                
} 


