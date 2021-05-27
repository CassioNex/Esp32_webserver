// ***************************************************************************************************
// *  Arquivo da função de update da memória EEPROM                                                  *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 11 - Maio/2021                                                                          *
// *                                                                                                 *
// ***************************************************************************************************

#include "EEPROM.h"

void EEPROM_update(int pin, int pin_state, int mem, int save){
    Serial.println("State changed");
    // change the LED state
    digitalWrite(pin, pin_state);
    // save the LED state in flash memory
    if (save == 1){
      EEPROM.write(mem, pin_state);
      EEPROM.commit();
      Serial.println("State saved in flash memory");
    }
}

void EEPROM_update_web(int state, int mem){
  Serial.println("State EEPROM changed");
  EEPROM.write(mem, state);
  EEPROM.commit();
  Serial.println("State for EEPROM saved in flash memory");
}
