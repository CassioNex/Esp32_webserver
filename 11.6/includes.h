// ***************************************************************************************************
// *  Arquivo de chamada de bibliotecas                                                              *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Maio/2021                                                                         *
// *                                                                                                 *
// ***************************************************************************************************

//Bibliotecas
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include <EEPROM.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "fauxmoESP.h"

//Bibliotecas de dados
#include "credenciais.h"
#include "pinagem.h"
#include "dados_mqtt.h"

// ***************************************************************************************************
// *  Função: processor                                                                              *
// *  Descrição: Substitua o placeholder pela seleção de botão em sua página da web                  *
// *  Argumentos: var                                                                                *
// *  Retorno: texto com o hmtl do botão (String)                                                    *
// ***************************************************************************************************

#include "processor.h"

// ***************************************************************************************************
// *  Função: map float                                                                               *
// *  Descrição: Remapeia um numero de um intervalo para outro                                       *
// *  Argumentos: Variável de entrada, intervalor anterior e intervalo novo                          *
// *  Retorno: Novo intervalo                                                                        *
// ***************************************************************************************************

#include "mapfloat.h"

// ***************************************************************************************************
// *  Função: EEPROM_update                                                                          *
// *  Descrição: altera o valor da saida e escreve na EEPROM                                         *
// *  Argumentos: Pino de saída, estado do pino e endereço da memória                                *
// *  Retorno: texto se verificado alteração                                                         *
// ***************************************************************************************************

#include "EEPROM_update.h"

// ***************************************************************************************************
// *  Função: Analog                                                                                 *
// *  Descrição: Faz a leitura do valor do potenciometro                                             *
// *  Argumentos: Pino de entrada analógica                                                          *
// *  Retorno: O valor lido                                                                          *
// ***************************************************************************************************

#include "analog.h"

// ***************************************************************************************************
// *  Função: BT                                                                                     *
// *  Descrição: Faz a leitura do valor dos botões                                                   *
// *  Argumentos:                                                                                    *
// *  Retorno:                                                                                       *
// ***************************************************************************************************

#include "bt.h"


// ***************************************************************************************************
// *  Função: MQTT                                                                                   *
// *  Descrição: Envia os dados coletados para a plataforma da ProIOT                                *
// *  Argumentos:                                                                                    *
// *  Retorno:                                                                                       *
// ***************************************************************************************************

#include "MQTT.h"
