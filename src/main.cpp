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
#define SEUIL_TENSION 805 // À ajuster

//Variables globales
uint16_t nbrPersonnes = 0;
bool memePersonne = 0;
bool ancienChargement = false;  
uint16_t NbrChargement = 0;     

// the setup function runs once when you press reset or power the board
void setup() 
{
  pinMode(PIN_CHARGEUR, INPUT);
  Serial.begin(9600);
  start_LED(); // Affiche rouge sur toutes les LED 
  startEcran(); 
}

// the loop function runs over and over again forever
void loop()
{

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
  
  Serial.println(luminosity);
  Serial.println(proximity);

  // Mise à jour des DEL
  bool Chargement = false;
  int valeur = analogRead(PIN_CHARGEUR);
  bool DarkMode = false;

  Chargement = valeur < SEUIL_TENSION;

  if (Chargement && !ancienChargement) {
    NbrChargement++;
  }

  ancienChargement = Chargement;
  
  float ambient_light = 0;
  if (apds.readAmbientLightLux(ambient_light)) 
  {
    DarkMode = ambient_light < 10.0;
  }

  GestionLED(Chargement, DarkMode);

  /*
  Fonction afficher pour l'écran
  premier nombre = variable en int du nombre de personne passé (so from Cesar)
  deuxieme nombre = variable en int du nombre de telephone charge (so from Jeff)
  */

  afficher(nbrPersonnes,NbrChargement);
} 