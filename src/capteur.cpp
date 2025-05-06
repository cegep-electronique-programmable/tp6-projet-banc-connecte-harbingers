#include "capteur.h"

void iniCapteur(void){
    uint8 ATIME, PTIME, WTIME, PPULSE;
    ATIME = 0xff; // 2.7 ms – minimum ALS integration time
    WTIME = 0xff; // 2.7 ms – minimum Wait time
    PTIME = 0xff; // 2.7 ms – minimum Prox integration time
    PPULSE = 1; // Minimum prox pulse count

    WriteRegData(0, 0); //Disable and Powerdown
    WriteRegData (1, ATIME);
    WriteRegData (2, PTIME);
    WriteRegData (3, WTIME);
    WriteRegData (0xe, PPULSE); 
}   

void capteur(uint16_t levelLight, uint16_t nbrPersonnes){
  
}

void WriteRegData(uint8 reg, uint8 data)
{
    //m_I2CBus.WriteI2C(0x39, 0x80 | reg, 1, &data);
}