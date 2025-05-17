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
 #include <APDS9930.h>
 
void setup_capteur(void);
void GestionCapteur(void);
uint16_t GestionCapteurProximity(void);
float GestionCapteurLuminosity(void);
 
 #endif // CAPTEUR_H