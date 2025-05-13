/*
 * Nom de fichier 
 *      main.cpp
 * 
 * Sommaire
 *      Fichier du projet du banc connecter
 * 
 * Auteur 
 *      Jeff, Sonia, Cesar, Mark
 * 
 * Date de création
 *      13 mai 2025
 *  
 */
#include <Arduino.h>
#include "affichage.h"

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  startEcran();
}

// the loop function runs over and over again forever
void loop() {
  //À enlever? (del qui flash)
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for 1second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(100);                      // wait for 100ms
  /*
  Fonction afficher pour l'écran
  premier nombre = variable en int du nombre de personne passé (so from Cesar)
  deuxieme nombre = variable en int du nombre de telephone charge (so from Jeff)
  */
  afficher(0,1);
  delay(100);
}