// ***************************************************************************************************
// *  Arquivo da chamadas das páginas web para EEPROM                                                *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Maio/2021                                                                          *
// *                                                                                                 *
// ***************************************************************************************************

server.on("/LED01on", HTTP_GET, [](AsyncWebServerRequest * request) {
  LED01 = 1;
  Serial.print(LED01);
  EEPROM_update_web(LED01, LED_EEPROM_SAVE);
request->send(SPIFFS, "/memoria.html", String(), false, processor);
});
server.on("/LED01off", HTTP_GET, [](AsyncWebServerRequest * request) {
  LED01 = 0;
  EEPROM_update_web(LED01, LED_EEPROM_SAVE);
  request->send(SPIFFS, "/memoria.html", String(), false, processor);
});


server.on("/LED02on", HTTP_GET, [](AsyncWebServerRequest * request) {
  LED02 = 1;
  EEPROM_update_web(LED02, LED2_EEPROM_SAVE);
  request->send(SPIFFS, "/memoria.html", String(), false, processor);
});
server.on("/LED02off", HTTP_GET, [](AsyncWebServerRequest * request) {
  LED02 = 0;
  EEPROM_update_web(LED02, LED2_EEPROM_SAVE);
  request->send(SPIFFS, "/memoria.html", String(), false, processor);
});


server.on("/LED03on", HTTP_GET, [](AsyncWebServerRequest * request) {
  LED03 = 1;
  EEPROM_update_web(LED03, LEDON_EEPROM_SAVE);
  request->send(SPIFFS, "/memoria.html", String(), false, processor);
});
server.on("/LED03off", HTTP_GET, [](AsyncWebServerRequest * request) {
  LED03 = 0;
  EEPROM_update_web(LED03, LEDON_EEPROM_SAVE);
  request->send(SPIFFS, "/memoria.html", String(), false, processor);
});


server.on("/MQTT01on", HTTP_GET, [](AsyncWebServerRequest * request) {
  MQTT01 = 1;
  EEPROM_update_web(MQTT01, MQTT_EEPROM_SAVE);
  request->send(SPIFFS, "/memoria.html", String(), false, processor);
});
server.on("/MQTT01off", HTTP_GET, [](AsyncWebServerRequest * request) {
  MQTT01 = 0;
  EEPROM_update_web(MQTT01, MQTT_EEPROM_SAVE);
  request->send(SPIFFS, "/memoria.html", String(), false, processor);
});


server.on("/LOG01on", HTTP_GET, [](AsyncWebServerRequest * request) {
  LOG01 = 1;
//  Serial.print(LOG01);
  EEPROM_update_web(LOG01, PSW_EEPROM_SAVE);
request->send(SPIFFS, "/memoria.html", String(), false, processor);
});
server.on("/LOG01off", HTTP_GET, [](AsyncWebServerRequest * request) {
  LOG01 = 0;
  EEPROM_update_web(LOG01, PSW_EEPROM_SAVE);
  request->send(SPIFFS, "/memoria.html", String(), false, processor);
});

//
// ***************************************************************************************************
// *  Request: update1                                                                               *
// *  Descrição: Altera estado de salvameto da saída                                                 *
// ***************************************************************************************************
  server.on("/update1", HTTP_GET, [] (AsyncWebServerRequest *request)
  {
  String inputMessage1;
  String inputParam1;
  
  // GET input1 value on <ESP_IP>/update?state=<inputMessage>
  if (request->hasParam(PARAM_INPUT_eeled01))
  {
      inputMessage1 = request->getParam(PARAM_INPUT_eeled01)->value();
      inputParam1 = PARAM_INPUT_eeled01;
      LED01 = inputMessage1.toInt();
      Serial.print(LED01);
      EEPROM_update_web(LED01, LED_EEPROM_SAVE);
  //    LED01 = inputMessage1.toInt();
 //     Serial.println(inputMessage1.toInt());
 //    EEPROM_update_web(LED01, LED_EEPROM_SAVE);
 //     Serial.println("atualização eeprom");
 //   digitalWrite(ledPin, inputMessage1.toInt());
 //   led_status = !led_status;
//    EEPROM_update(ledPin, led_status, 0, LED01);
  }
  else
  {
    inputMessage1 = "No message sent";
    inputParam1 = "none";
    
 ///        inputMessage1 = request->getParam(PARAM_INPUT_eeled01)->value();
 ///     inputParam1 = PARAM_INPUT_eeled01;
 ///   Serial.println(inputMessage1.toInt());
 ///   Serial.println("atualização eeprom fail");
    
  }
  Serial.println(inputMessage1);
  request->send(200, "text/plain", "OK");


  //

  String inputMessage2;
  String inputParam2;
  
  // GET input1 value on <ESP_IP>/update?state=<inputMessage>
  if (request->hasParam(PARAM_INPUT_eeled02))
  {
    inputMessage2 = request->getParam(PARAM_INPUT_eeled02)->value();
    inputParam2 = PARAM_INPUT_eeled02;
    digitalWrite(ledPin, inputMessage2.toInt());
    led_status = !led_status;
//    EEPROM_update(ledPin, led_status, 0, LED01);
  }
  else
  {
    inputMessage2 = "No message sent";
    inputParam2 = "none";
  }
  Serial.println(inputMessage2);
  request->send(200, "text/plain", "OK");

//

String inputMessage3;
  String inputParam3;
  
  // GET input1 value on <ESP_IP>/update?state=<inputMessage>
  if (request->hasParam(PARAM_INPUT_eeled03))
  {
    inputMessage3 = request->getParam(PARAM_INPUT_eeled03)->value();
    inputParam3 = PARAM_INPUT_eeled03;
    digitalWrite(ledPin, inputMessage3.toInt());
    led_status = !led_status;
//    EEPROM_update(ledPin, led_status, 0, LED01);
  }
  else
  {
    inputMessage3 = "No message sent";
    inputParam3 = "none";
  }
  Serial.println(inputMessage3);
  request->send(200, "text/plain", "OK");

//

String inputMessage4;
  String inputParam4;
  
  // GET input1 value on <ESP_IP>/update?state=<inputMessage>
  if (request->hasParam(PARAM_INPUT_eemqtt01))
  {
    inputMessage4 = request->getParam(PARAM_INPUT_eemqtt01)->value();
    inputParam4 = PARAM_INPUT_eemqtt01;
    digitalWrite(ledPin, inputMessage4.toInt());
    led_status = !led_status;
//    EEPROM_update(ledPin, led_status, 0, LED01);
  }
  else
  {
    inputMessage4 = "No message sent";
    inputParam4 = "none";
  }
  Serial.println(inputMessage4);
  request->send(200, "text/plain", "OK");

//

String inputMessage5;
  String inputParam5;
  
  // GET input1 value on <ESP_IP>/update?state=<inputMessage>
  if (request->hasParam(PARAM_INPUT_eelog01))
  {
    inputMessage5 = request->getParam(PARAM_INPUT_eelog01)->value();
    inputParam5 = PARAM_INPUT_eelog01;
    digitalWrite(ledPin, inputMessage5.toInt());
    led_status = !led_status;
//    EEPROM_update(ledPin, led_status, 0, LED01);
  }
  else
  {
    inputMessage5 = "No message sent";
    inputParam5 = "none";
  }
  Serial.println(inputMessage5);
  request->send(200, "text/plain", "OK");


  });
