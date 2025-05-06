/*!
 * @file capteur.h
 *
 * @author César Antonio Del Pozo Catalan
 * 
 * @date 6 Mai 2025
 * 
 * @brief Regarder et compter le nombre de personnes qui passent devant le banc
 *
 */

 #ifndef CAPTEUR_H
 #define CAPTEUR_H
 
 #include <Arduino.h>
 #include <Wire.h>
 
 
 void iniCapteur(void);
 
 void capteur(uint16_t levelLight, uint16_t nbrPersonnes);
 
 
 
 
 #endif // CAPTEUR_H