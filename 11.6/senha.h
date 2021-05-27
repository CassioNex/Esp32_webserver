if (asenha == "SENHA" && bsenha == SENHA){
  Serial.println("oi");
  pswstate = 1;
  Serial.println("pswstate antes");
  Serial.println(pswstate);
    if(PSW_EEPROM != pswstate){
        EEPROM_update_web(pswstate, PSW_EEPROM);
    }
}
else{
  pswstate = 0;
  Serial.println("senha errada");
  Serial.println(pswstate);
  EEPROM_update_web(pswstate, PSW_EEPROM);
}

  
