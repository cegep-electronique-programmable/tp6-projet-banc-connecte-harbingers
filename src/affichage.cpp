/*
 * Nom de fichier 
 *      affichage.cpp
 * 
 * Sommaire
 *      Fichier .cpp pour l'affichage de l'écran
 *      Librarie: U8g2lib
 * Auteur 
 *      Sonia
 * 
 * Date de création
 *      13 mai 2025
 *  
 */

#include "affichage.h"
#include <U8g2lib.h>

/*
  Toutes les positions ont été trouvés en essai erreur pour l'affichage
*/

//set l'écran
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(SCL,SDA,U8X8_PIN_NONE);
//essai erreur pour tracer la ligne
uint8_t tiles[8] = {0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f};
//initialisation de l'écran
void startEcran(void) {
  u8x8.begin();
  titres();
  line();
}

/*
  Fonction titres
  Affiche les titres des catégories sur l'écran
*/
void titres(void){
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(0,0,"nb presence");
  delay(50);
  u8x8.drawString(0,5,"nb telephone");
  delay(50);
}

/*
  Fonction line
  Dessine la ligne de séparation au milieu
*/
void line(void){
  u8x8.drawTile(0, 4, 1, tiles);
  u8x8.drawTile(1,4, 1, tiles);
  u8x8.drawTile(2,4, 1, tiles);
  u8x8.drawTile(3,4, 1, tiles);
  u8x8.drawTile(4,4, 1, tiles);
  u8x8.drawTile(5,4, 1, tiles);
  u8x8.drawTile(6,4, 1, tiles);
  u8x8.drawTile(7,4, 1, tiles);
  u8x8.drawTile(8,4, 1, tiles);
  u8x8.drawTile(9,4, 1, tiles);
  u8x8.drawTile(10,4, 1, tiles);
  u8x8.drawTile(11,4, 1, tiles);
  u8x8.drawTile(12,4, 1, tiles);
  u8x8.drawTile(13,4, 1, tiles);
  u8x8.drawTile(14,4, 1, tiles);
  u8x8.drawTile(15,4, 1, tiles);
}

/*
  Fonction afficher
  Affiche les nombres de personnes passé et de téléphone charger
  p = le nombre de personnes passé en int
  t = le nombre de téléphone chargé en int
*/
void afficher(int p, int t){
  u8x8.setCursor(13, 1);
  u8x8.print(p);
  u8x8.setCursor(13,6);
  u8x8.print(t);
}