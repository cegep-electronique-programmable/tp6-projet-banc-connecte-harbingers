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
  setup_capteur();
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
  int valeur = analogRead(PIN_CHARGEUR); //Lecture de la tension d'entrée du chargeur

  bool Chargement = valeur < SEUIL_TENSION; //Déterminer si un téléphone est en train de charger

  //Si un nouveau chargement commence le compter
  if (Chargement && !ancienChargement) 
  {
    NbrChargement++;
  }

  //Mémoriser l'état actuel pour la prochaine itération
  ancienChargement = Chargement;

  //Activer le mode sombre si la luminosité ambiante est faible
  bool DarkMode = luminosity < 10.0;

  //Mettre à jour les LEDs selon l’état de charge et la luminosité ambiante
  GestionLED(Chargement, DarkMode);

  /*
  Fonction afficher pour l'écran
  premier nombre = variable en int du nombre de personne passé 
  deuxieme nombre = variable en int du nombre de telephone charge 
  */

  afficher(nbrPersonnes,NbrChargement);

  delay(100);
} 