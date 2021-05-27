// ***************************************************************************************************
// *  Arquivo da comparação dados login                                                              *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Maio/2021                                                                          *
// *                                                                                                 *
// ***************************************************************************************************

if (nome == "USERNAME" && dado == USER){
     logstate = 1;
     Serial.println("logstate antes");
    Serial.println(logstate);
    EEPROM_update_web(logstate, LOG_EEPROM);
}
else{
  logstate = 0;
 // testlogin = 1;
 // delay(500);
 // testlogin = 0;
  Serial.println("nome errado");
  Serial.println(logstate);
  EEPROM_update_web(logstate, LOG_EEPROM);
}
