#define DUMP_REGS

#include "capteur.h"

extern APDS9930 apds;
uint16_t proximity_data = 0;
float ambient_light = 0; // can also be an unsigned long
uint16_t ch0 = 0;
uint16_t ch1 = 1;

void setup_capteur(void) 
{
  //analogReference(EXTERNAL);

  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("---------------------------"));
  Serial.println(F("APDS-9930 - ProximitySensor"));
  Serial.println(F("---------------------------"));
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("APDS-9930 - Ambient light sensor"));
  Serial.println(F("--------------------------------"));
  
  // Initialize APDS-9930 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9930 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9930 init!"));
  }
  
  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_2X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }
  
  // Start running the APDS-9930 proximity sensor (no interrupts)
  if ( apds.enableProximitySensor(false) ) {
    Serial.println(F("Proximity sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
  }

  // Start running the APDS-9930 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

#ifdef DUMP_REGS
  /* Register dump */
  uint8_t reg;
  uint8_t val;

  for(reg = 0x00; reg <= 0x19; reg++) {
    if( (reg != 0x10) && \
        (reg != 0x11) )
    {
      apds.wireReadDataByte(reg, val);
      Serial.print(reg, HEX);
      Serial.print(": 0x");
      Serial.println(val, HEX);
    }
  }
  apds.wireReadDataByte(0x1E, val);
  Serial.print(0x1E, HEX);
  Serial.print(": 0x");
  Serial.println(val, HEX);
#endif
}

uint16_t GestionCapteurProximity(void){
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");

    // Return 0 to main
    return 0;
  } else {
    Serial.print("Proximity: ");
    Serial.println(proximity_data);
    // Return the value of proximity data to main
    return proximity_data;
  }

  // Wait 1 second before next reading
  //delay(1000);
}

float GestionCapteurLuminosity(void){
  // Read the light levels (ambient, red, green, blue)
  if (  !apds.readAmbientLightLux(ambient_light) ||
        !apds.readCh0Light(ch0) || 
        !apds.readCh1Light(ch1) ) {
    Serial.println(F("Error reading light values"));

    // Return 0 to main
    return 0;
  } else {
    Serial.print(F("Ambient: "));
    Serial.print(ambient_light);
    Serial.print(F("  Ch0: "));
    Serial.print(ch0);
    Serial.print(F("  Ch1: "));
    Serial.println(ch1);

    // Return the value of ambient light to main
    return ambient_light;
  }

  // Wait 1 second before next reading
  //delay(1000);
}