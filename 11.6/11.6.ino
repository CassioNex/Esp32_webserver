// ***************************************************************************************************
// *  Projeto Sensor de nível                                                                        *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Abril/2021                                                                         *
// *                                                                                                 *
// ***************************************************************************************************

#include "includes.h"

// Cria um objeto AsyncWebServer na porta 81
AsyncWebServer server(81);

// ***************************************************************************************************
// *  Função: Login                                                                                  *
// *  Descrição: Login utilizando POP UP                                                             *
// *  Argumentos: request,autenticate                                                                *
// *  Retorno: true/false                                                                            *
// ***************************************************************************************************
//POP UP**
/*
bool _webAuth(AsyncWebServerRequest *request){
    if(!request->authenticate("admin","admin",NULL,false)) {
      request->requestAuthentication(NULL,false); // force basic auth
      return false;
    }
    return true;
}
*/


// ***************************************************************************************************
// *  Função: setup (obrigatória)                                                                    *
// *  Descrição: Função de inicialização do sistema (após energização ou reset)                      *
// *  Argumentos: Nenhum                                                                             *
// *  Retorno: Nenhum                                                                                *
// ***************************************************************************************************

void setup() {
// Inicia a porta serial
  Serial.begin(115200);

// ***************************************************************************************************
// *  Definição dos pinos de entrada e saida                                                         *  
// ***************************************************************************************************

  #include "pinmode.h"
 
// ***************************************************************************************************
// *  Inicializa SPIFFS                                                                              *  
// ***************************************************************************************************

  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

// ***************************************************************************************************
// *  Inicializa a EEPROM com tamanho pré definido                                                   *  
// ***************************************************************************************************
 /* 
  EEPROM.begin(EEPROM_SIZE);
  led_status = EEPROM.read(LED_EEPROM);
  digitalWrite(ledPin, led_status);
  ledon_status = EEPROM.read(LEDON_EEPROM);
  digitalWrite(ledon, ledon_status);
  ledState_int = EEPROM.read(LED2_EEPROM);
  digitalWrite(ledPin2, ledState_int);
*/

// ***************************************************************************************************
// *  Conecta no MQTT                                                                                *  
// ***************************************************************************************************

  Serial.print("Servidor configurado: ");
  Serial.print(SER);
  Serial.print(" : ");
  Serial.println(PORTA);
  MQTT.setServer(SER,PORTA);

  //Concatena a variavel "TOPICO" com a variavel "ID_DISPOSITIVO"
  strcat(TOPICO,ID_DISPOSITIVO);




// ***************************************************************************************************
// *  Conecta no WIFI                                                                                *  
// ***************************************************************************************************
  
  WiFi.mode(WIFI_STA);
//   WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
//  WiFi. config( ip ); //PASSA OS PARÂMETROS PARA A FUNÇÃO QUE VAI SETAR O IP FIXO NO NODEMCU
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
// Imprime o indereço IP local do ESP32 
  Serial.println(WiFi.localIP());

// ***************************************************************************************************
// *  Arquivos de chamada das páginas HTML                                                           *  
// ***************************************************************************************************

  #include "server_on.h"

// ***************************************************************************************************

  // Start server
  server.begin();

// ***************************************************************************************************
// *  Conecta o fauxmo para a Alexa                                                                  *  
// ***************************************************************************************************

  #include "Alexa.h"
}

// ***************************************************************************************************
// *  Função: loop (obrigatória)                                                                     *
// *  Descrição: Função de looping principal                                                         *
// *  Argumentos: Nenhum                                                                             *
// *  Retorno: Nenhum                                                                                *
// ***************************************************************************************************

void loop() 
{
// ***************************************************************************************************
// *  Fauxmo para Alexa                                                                              *
// ***************************************************************************************************

  // fauxmoESP uses an async TCP server but a sync UDP server
  // Therefore, we have to manually poll for UDP packets
  fauxmo.handle();

// ***************************************************************************************************
// *  Chamada da função do MQTT                                                                      *
// ***************************************************************************************************

  //Mantem a conexao ativa com o servidor
  MQTT.loop();
  if (EEPROM.read(6) == 1){
    send_MQTT();
  }

// ***************************************************************************************************
// *  Liga o LED de saída com o botão físico                                                         *
// ***************************************************************************************************

  read_bton();
  read_bt();

// ***************************************************************************************************
// *  Leitura da entrada analógica                                                                   *
// ***************************************************************************************************

  valor_pot = Analog(potPin);

// ***************************************************************************************************
// *  Chamada da função da EEPROM                                                                    *
// ***************************************************************************************************
  if (digitalRead(ledPin)!= led_status) {  
    EEPROM_update(ledPin, led_status, 0, LED01);
  }
  if (digitalRead(ledon)!= ledon_status) {  
    EEPROM_update(ledon, ledon_status, 1, LED03);
  }
  if (digitalRead(ledPin2)!= ledState_int) {
    EEPROM_update(ledPin2, ledState_int, 2, LED02);
  }
if (LOG01 == 1 && pswstate != EEPROM.read(4)){
  EEPROM_update_web(pswstate, PSW_EEPROM);
  }
}
