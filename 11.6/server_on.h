// ***************************************************************************************************
// *  Arquivo das chamadas das páginas web localizadas na memória FLASH                              *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Abril/2021                                                                         *
// *                                                                                                 *
// ***************************************************************************************************

// ***************************************************************************************************
// *  Request: update                                                                                *
// *  Descrição: Altera o estado da saída                                                            *
// ***************************************************************************************************

#include"checkbox.h"

server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request)
  {
  String inputMessage;
  String inputParam;
  
  // GET input1 value on <ESP_IP>/update?state=<inputMessage>
  if (request->hasParam(PARAM_INPUT_bt))
  {
    inputMessage = request->getParam(PARAM_INPUT_bt)->value();
    inputParam = PARAM_INPUT_bt;
    digitalWrite(ledPin, inputMessage.toInt());
    led_status = !led_status;
    EEPROM_update(ledPin, led_status, LED_EEPROM, LED01);
  }
  else
  {
    inputMessage = "No message sent";
    inputParam = "none";
  }
  Serial.println(inputMessage);
  request->send(200, "text/plain", "OK");

  String inputMessageon;
  String inputParamon;
  
  if (request->hasParam(PARAM_INPUT_on))
  {
    inputMessageon = request->getParam(PARAM_INPUT_on)->value() + "\n";
    inputParamon = PARAM_INPUT_on;
    digitalWrite(ledon, inputMessageon.toInt());
    ledon_status = !ledon_status;
    EEPROM_update(ledon, ledon_status, LEDON_EEPROM, LED03);
  }
  else
  {
    inputMessageon = "No message sent\n";
    inputParamon = "none";
  }
  Serial.println(inputMessageon);
  request->send(200, "text/plain", "OK");
  });
  //


// ***************************************************************************************************
// *  Request: state                                                                                 *
// *  Descrição: Imprime o valor de estado na saida                                                  *
// ***************************************************************************************************
  
    server.on("/state", HTTP_GET, [] (AsyncWebServerRequest *request)
  {
    request->send(200, "text/plain", String(digitalRead(ledPin)).c_str());
  });

    server.on("/stateon", HTTP_GET, [] (AsyncWebServerRequest *request)
  {
    request->send(200, "text/plain", String(digitalRead(ledon)).c_str());
  });
      server.on("/state1", HTTP_GET, [] (AsyncWebServerRequest *request)
  {
    request->send(200, "text/plain", String(SLED01).c_str());
  });
      server.on("/state2", HTTP_GET, [] (AsyncWebServerRequest *request)
  {
    request->send(200, "text/plain", String(SLED02).c_str());
  });
      server.on("/state3", HTTP_GET, [] (AsyncWebServerRequest *request)
  {
    request->send(200, "text/plain", String(SLED03).c_str());
  });
      server.on("/state4", HTTP_GET, [] (AsyncWebServerRequest *request)
  {
    request->send(200, "text/plain", String(SLOG01).c_str());
  });
      server.on("/state5", HTTP_GET, [] (AsyncWebServerRequest *request)
  {
    request->send(200, "text/plain", String(SMQTT01).c_str());
  });

// ***************************************************************************************************
// *  Request: readADC                                                                               *
// *  Descrição: Salva o valor lido pela entrada analógica                                           *
// ***************************************************************************************************

  server.on("/readADC", HTTP_GET, [] (AsyncWebServerRequest *request)
  {
    request->send(200, "text/plain", String(valor_pot));
  });
  
// ***************************************************************************************************
// *  Request: /                                                                                     *
// *  Descrição: Envia a página "página principa" quando entra no URL sem complemento                *
// ***************************************************************************************************

 server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){           
    request->send(SPIFFS, "/pp.html", String(), false, processor);
 });

// ***************************************************************************************************
// *  Request: login                                                                                 *
// *  Descrição: Envia a página login e imprime os parametros no monitor serial                      *
// ***************************************************************************************************

  server.on("/login", HTTP_GET, [](AsyncWebServerRequest *request){ 
  if(n == 0){
     Serial.print("valor de n if"); 
      Serial.print(n); 
    request->send(SPIFFS, "/redirectsenha.html", String(), false, processor);
  }
//  if(logstate == 1){
//     request->send(SPIFFS, "/redirectsenha.html", String(), false, processor);
//  }
 else {
   Serial.print("valor de n else");
    Serial.print(n);  
//   if (testlogin == 1){
//      request->send(SPIFFS, "/enviatestelogin.html", String(), false, processor);
   
    request->send(SPIFFS, "/login.html", String(), false, processor);
    
    int paramsNr = request->params();
//    Serial.println(paramsNr);
 
    for(int i=0;i<paramsNr;i++){


        
        AsyncWebParameter* p = request->getParam(i);

   nome = p->name();

   dado = p->value();

       
        Serial.print("Param name: ");
        Serial.println(p->name());
        Serial.print("Param value: ");
        Serial.println(p->value());
        Serial.println("------");
       #include "login.h"  
       n = 0;
       Serial.println("n verificou");
        Serial.print(n); 

    }

 }
});

// ***************************************************************************************************
// *  Request: senha                                                                                 *
// *  Descrição: Envia a página login e imprime os parametros no monitor serial                      *
// ***************************************************************************************************

  server.on("/senha", HTTP_GET, [](AsyncWebServerRequest *request){           //editado
if (logstate == 1){
  request->send(SPIFFS, "/senha.html", String(), false, processor);
}
else if(pswstate == 1){
  request->send(SPIFFS, "/pp.html", String(), false, processor);
}
else{
   Serial.print("valor de n senha"); 
    Serial.print(n); 
  request->send(SPIFFS, "/viraum.html", String(), false, processor);
}
    int paramsNr = request->params();
//    Serial.println(paramsNr);
 
    for(int i=0;i<paramsNr;i++){


        
        AsyncWebParameter* p = request->getParam(i);

   asenha = p->name();

   bsenha = p->value();

       
        Serial.print("Param name: ");
        Serial.println(p->name());
        Serial.print("Param value: ");
        Serial.println(p->value());
        Serial.println("------");
       #include "senha.h"   
    }

});
 
// ***************************************************************************************************
// *  Request: /index                                                                                *
// *  Descrição: Envia a página "index" quando entra no URL /index                                   *
// ***************************************************************************************************

  server.on("/index", HTTP_GET, [](AsyncWebServerRequest * request) { ///login anterior
//POP UP**    if(!_webAuth(request)) return;

if (pswstate == 1){
  request->send(SPIFFS, "/index.html", String(), false, processor);
}
else{
  request->send(SPIFFS, "/redirectlogin.html", String(), false, processor);
}
  });

// ***************************************************************************************************
// *  Request: /unlog                                                                                *
// *  Descrição: Envia a página "unlog" quando entra no URL /unlog                                   *
// ***************************************************************************************************

  server.on("/unlog", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/unlog.html", String(), false, processor);
  });

// ***************************************************************************************************
// *  Request: /inova                                                                                *
// *  Descrição: Envia a imagem "inova" quando solicita o URL /inova                                 *
// ***************************************************************************************************

    server.on("/inova", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/inova.png", "image/png");
  });

// ***************************************************************************************************
// *  Request: /noimg                                                                                *
// *  Descrição: Envia a imagem "noimg" quando solicita o URL /noimg                                 *
// ***************************************************************************************************

      server.on("/noimg", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/noimg.png", "image/png");
  });
  
// ***************************************************************************************************
// *  Request: /on                                                                                   *
// *  Descrição: Envia a página "on" quando entra no URL /on                                         *
// ***************************************************************************************************
  server.on("/on", HTTP_GET, [](AsyncWebServerRequest * request) {
// ativa a verificação por pop up p acessar a página on
//POP UP**    if(!_webAuth(request)) return;

if (pswstate == 1){
      //digitalWrite(ledPin2, HIGH);
    //ledState = "ON";
    ledState_int = 1;
    delay(200);
  request->send(SPIFFS, "/index.html", String(), false, processor);
}
else{
  
  request->send(SPIFFS, "/redirectlogin.html", String(), false, processor);
}
  });

// ***************************************************************************************************
// *  Request: /off                                                                                  *
// *  Descrição: Envia a página "off" quando entra no URL/off                                        *
// ***************************************************************************************************

  // Route to set GPIO to LOW
  server.on("/off", HTTP_GET, [](AsyncWebServerRequest * request) {
// ativa a verificação por pop up p acessar a página off
//POP UP**    if(!_webAuth(request)) return;

if (pswstate == 1){
      //digitalWrite(ledPin2, LOW);
    //ledState = "OFF";
    ledState_int = 0;
    delay(200);
  request->send(SPIFFS, "/index.html", String(), false, processor);
}
else{
  request->send(SPIFFS, "/redirectlogin.html", String(), false, processor);
}
  });

// ***************************************************************************************************
// *  Request: /sobre                                                                                *
// *  Descrição: Envia a página "sobre" quando entra no URL/sobre                                    *
// ***************************************************************************************************

   server.on("/sobre", HTTP_GET, [](AsyncWebServerRequest *request){           
    request->send(SPIFFS, "/sobre.html", String(), false, processor);
 });

// ***************************************************************************************************
// *  Request: /duvidas                                                                              *
// *  Descrição: Envia a página "duvidas" quando entra no URL /duvidadas                             *
// ***************************************************************************************************

   server.on("/duvidas", HTTP_GET, [](AsyncWebServerRequest *request){           
    request->send(SPIFFS, "/duvidas.html", String(), false, processor);
 });

// ***************************************************************************************************
// *  Request: /sisconniv                                                                            *
// *  Descrição: Envia a página "Sistema com sensor de nivel" quando entra no URL /sisconiv          *
// ***************************************************************************************************

   server.on("/sisconniv", HTTP_GET, [](AsyncWebServerRequest *request){           
    request->send(SPIFFS, "/sisconniv.html", String(), false, processor);
 });

// ***************************************************************************************************
// *  Request: /gravblue                                                                             *
// *  Descrição: Envia a página "Gravador bluethoot" quando entra no URL /gravblue                   *
// ***************************************************************************************************

    server.on("/gravblue", HTTP_GET, [](AsyncWebServerRequest *request){           
    request->send(SPIFFS, "/gravblue.html", String(), false, processor);
 });

// ***************************************************************************************************
// *  Request: /gravcab                                                                              *
// *  Descrição: Envia a página "Gravador à cabo" quando entra no URL /gravcab                       *
// ***************************************************************************************************

    server.on("/gravcab", HTTP_GET, [](AsyncWebServerRequest *request){           
    request->send(SPIFFS, "/gravcab.html", String(), false, processor);
 });

// ***************************************************************************************************
// *  Request: /botao2                                                                               *
// *  Descrição: Envia a página "Com botões deslizantes" quando entra no URL /botao2                 *
// ***************************************************************************************************

     server.on("/botao2", HTTP_GET, [](AsyncWebServerRequest *request){ 
//POP UP**      if(!_webAuth(request)) return;          
if (pswstate == 1){
  request->send(SPIFFS, "/botao2.html", String(), false, processor);
}
else{
  request->send(SPIFFS, "/redirectlogin.html", String(), false, processor);
}
 });

// ***************************************************************************************************
// *  Request: /contato                                                                              *
// *  Descrição: Envia a página "contato" quando entra no URL /contato                               *
// ***************************************************************************************************

   server.on("/contato", HTTP_GET, [](AsyncWebServerRequest *request){           
    request->send(SPIFFS, "/contato.html", String(), false, processor);
 });

// ***************************************************************************************************
// *  Request: /produtos                                                                             *
// *  Descrição: Envia a página "produtos" quando entra no URL /produtos                             *
// ***************************************************************************************************

  server.on("/produtos", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/produtos.html", String(), false, processor);
  });

// ***************************************************************************************************
// *  Request: /memoria                                                                              *
// *  Descrição: Envia a página "memoria" quando entra no URL /memoria                               *
// ***************************************************************************************************

  server.on("/memoria", HTTP_GET, [](AsyncWebServerRequest *request){
//POP UP**    if(!_webAuth(request)) return;
if (pswstate == 1){
  request->send(SPIFFS, "/memoria.html", String(), false, processor);
}
else{
  request->send(SPIFFS, "/redirectlogin.html", String(), false, processor);
}
  });

// ***************************************************************************************************
// *  Request: /logout                                                                             *
// *  Descrição: Envia a página "produtos" quando entra no URL /produtos                             *
// ***************************************************************************************************

  server.on("/logout", HTTP_GET, [](AsyncWebServerRequest *request){
    pswstate = 0;
    logstate = 0;
    EEPROM_update_web(pswstate, PSW_EEPROM);
    EEPROM_update_web(logstate, LOG_EEPROM);
  request->send(SPIFFS, "/redirectlogin.html", String(), false, processor);
  });

// ***************************************************************************************************
// *  Request: /sisconniv                                                                            *
// *  Descrição: Envia a página "Sistema com sensor de nivel" quando entra no URL /sisconiv          *
// ***************************************************************************************************

   server.on("/viraum", HTTP_GET, [](AsyncWebServerRequest *request){ 
   n = 1;  
   Serial.print("valor de n");
    Serial.print(n);       
    request->send(SPIFFS, "/redirectlogin.html", String(), false, processor);
 });

// ***************************************************************************************************
// *  Request: /style                                                                                *
// *  Descrição: Envia o css para todas as páginas                                                   *
// ***************************************************************************************************

  // Route to load style.css file
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/style.css", "text/css");
  });
