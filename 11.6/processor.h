// ***************************************************************************************************
// *  Arquivo da função do processos dos arquivos HTML                                               *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Abril/2021                                                                         *
// *                                                                                                 *
// ***************************************************************************************************

// ***************************************************************************************************
// *  Função: outputstate                                                                            *
// *  Descrição: Verifica se o status dos botões foram alterados                                     *
// *  Argumentos: nenhum                                                                             *
// *  Retorno: texto se verificado alteração                                                         *
// ***************************************************************************************************

String outputState()
{
  if(digitalRead(ledPin))
  {
    return "checked";
  }
  else
  {
    return "";
  }
  return "";
}

String outputStateon()
{
  if(digitalRead(ledon))
  {
    return "checked";
    }
  else
    {
    return "";
  }
  return "";
}

//
String outputState1()
{
  if(LED01)
  {
    return "checked";
  }
  else
  {
    return "";
  }
  return "";
}
String outputState2()
{
  if(LED02)
  {
    return "checked";
  }
  else
  {
    return "";
  }
  return "";
}
String outputState3()
{
  if(LED03)
  {
    return "checked";
  }
  else
  {
    return "";
  }
  return "";
}
String outputState4()
{
  if(LOG01)
  {
    return "checked";
  }
  else
  {
    return "";
  }
  return "";
}
String outputState5()
{
  if(MQTT01)
  {
    return "checked";
  }
  else
  {
    return "";
  }
  return "";
}

// ***************************************************************************************************
// *  Função: processor                                                                              *
// *  Descrição: Substitua o placeholder pela seleção de botão em sua página da web                  *
// *  Argumentos: var                                                                                *
// *  Retorno: texto com o hmtl do botão (String)                                                    *
// ***************************************************************************************************

bool _getFile(AsyncWebServerRequest *request);
  // Replaces placeholder with LED state value
  String processor(const String& var){
  Serial.println();
  Serial.println(var);
  if(var == "STATE"){
    if(digitalRead(ledPin2)){
      ledState = "ON";
      //ledState_int = 1;
    }
    else{
      ledState = "OFF";
      //ledState_int = 0;
    }
    Serial.println(ledState);
    return ledState;
  }
   if(LED01 == 1){
    SLED01 = "ON";
   }
   else{
    SLED01 = "OFF";
   }
      if(LED02 == 1){
    SLED02 = "ON";
   }
   else{
    SLED02 = "OFF";
   }
      if(LED03 == 1){
    SLED03 = "ON";
   }
   else{
    SLED03 = "OFF";
   }
      if(LOG01 == 1){
    SLOG01 = "ON";
   }
   else{
    SLOG01 = "OFF";
   }
      if(MQTT01 == 1){
    SMQTT01 = "ON";
   }
   else{
    SMQTT01 = "OFF";
   }
    if(var == "BUTTONPLACEHOLDER")
  {
    String buttons1 ="";
    String outputStateValue = outputState();
    buttons1+= "<h4>Device 1 - Status <span id=\"outputState\"><span></h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"output\" " + outputStateValue + "><span class=\"slider\"></span></label>";
    return buttons1;
  return String();
  }
    if(var == "BUTTONPLACEHOLDERON")
  {
    String buttonson ="";
    String outputStateValueon = outputStateon();
    buttonson+= "<h4>Device on - Status <span id=\"outputStateon\"><span></h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckboxon(this)\" id=\"outputon\" " + outputStateValueon + "><span class=\"slider\"></span></label>";
    return buttonson;
  }
      if(var == "BUTTONPLACEHOLDER1")
  {
    String buttons2 ="";
    String outputStateValue1 = outputState1();
    buttons2+= "<h4>led - Status <span id=\"outputState1\"><span></h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox1(this)\" id=\"output1\" " + outputStateValue1 + "><span class=\"slider\"></span></label>";
    return buttons2;
  return String();
  }
      if(var == "BUTTONPLACEHOLDER2")
  {
    String buttons3 ="";
    String outputStateValue2 = outputState2();
    buttons3+= "<h4>led2 - Status <span id=\"outputState2\"><span></h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox2(this)\" id=\"output2\" " + outputStateValue2 + "><span class=\"slider\"></span></label>";
    return buttons3;
  return String();
  }
      if(var == "BUTTONPLACEHOLDER3")
  {
    String buttons4 ="";
    String outputStateValue3 = outputState3();
    buttons4+= "<h4>ledon - Status <span id=\"outputState3\"><span></h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox3(this)\" id=\"output3\" " + outputStateValue3 + "><span class=\"slider\"></span></label>";
    return buttons4;
  return String();
  }
      if(var == "BUTTONPLACEHOLDER4")
  {
    String buttons5 ="";
    String outputStateValue4 = outputState4();
    buttons5+= "<h4>log in - Status <span id=\"outputState4\"><span></h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox4(this)\" id=\"output4\" " + outputStateValue4 + "><span class=\"slider\"></span></label>";
    return buttons5;
  return String();
  }
      if(var == "BUTTONPLACEHOLDER5")
  {
    String buttons6 ="";
    String outputStateValue5 = outputState5();
    buttons6+= "<h4>MQTT - Status <span id=\"outputState5\"><span></h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox5(this)\" id=\"output5\" " + outputStateValue5 + "><span class=\"slider\"></span></label>";
    return buttons6;
  return String();
  }
  if (var == "ANALOG")
  {
    String analog = "";
    analog += map_potV;
    return analog;
  }
  /*                      Imprimir se a memoria esta ativa
  if (var == "MEMORIA")
  {
      if(digitalRead(ledPin2)){
      memstate = "ON";
    }
    else{
      memstate = "OFF";
    }
    return memstate;  
  }
  */
  /*                        imprimir se esta conectado
 if(var == "AQUI"){
    if (logstate == 1){
    logap = "Nome autenticado";
  }
    else{
     logap = "Favor inserir o nome";
  }
  return logap;
  } 
  */ 
}
