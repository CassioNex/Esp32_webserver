// ***************************************************************************************************
// *  Arquivo da função ddos botões físicos do sistema                                               *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Abril/2021                                                                         *
// *                                                                                                 *
// ***************************************************************************************************

void read_bton(){
  int readingon = digitalRead(bton);
  if (readingon != last_bton_status)
  {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (readingon != bton_status)
    {
      bton_status = readingon;
      if (bton_status == HIGH)
      {
        ledon_status = !ledon_status;
      }
    }
  }
  last_bton_status = readingon;
}

void read_bt(){
  int reading = digitalRead(btPin);
  if (ledon_status == LOW){
    if (reading != last_bt_status)
    {
    lastDebounceTime = millis(); // reseta o tempo de debouncing
    }
    if ((millis() - lastDebounceTime) > debounceDelay) 
    {
      if (reading != bt_status)
      {
        bt_status = reading;
        if (bt_status == HIGH)
        {
          led_status = !led_status;
        }
      }
    }
  }
  last_bt_status = reading;
}
