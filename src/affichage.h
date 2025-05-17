/*
 * Nom de fichier 
 *      affichage.h
 * 
 * Sommaire
 *      Fichier .h pour l'affichage de l'écran
 *      Librarie: U8g2lib
 * Auteur 
 *      Sonia
 * 
 * Date de création
 *      13 mai 2025
 *  
 */

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <Arduino.h>
#include <U8g2lib.h>

//déclaration des fonctions
void startEcran(void);
void titres(void);
void line(void);
void afficher(int,int);

#endif // AFFICHAGE_H