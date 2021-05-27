// ***************************************************************************************************
// *  Arquivo de dados necessários para a comunicação MQTT                                           *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Abril/2021                                                                         *
// *                                                                                                 *
// ***************************************************************************************************

//Criacao dos objetos que serao resposaveis pela conexao ao servidor
WiFiClient cliente; //Objeto "cliente" para a biblioteca WiFi
PubSubClient MQTT(cliente); //Objeto "MQTT" para a biblioteca PubSubClient através do objeto "cliente"

//Declaracao do servidor e da sua porta
const char* SER = "mqtt.proiot.network";
const uint16_t PORTA = 1883;

//Declaracao das variaveis geradas na plataforma
//Henrique
const char* ID_DISPOSITIVO = "3c0f8085de70d508"; //ID Unico do Dispositivo
const char* TOKEN_API = "ZdqA2oohAKkLxAemxOFpaWMHo7Zlfjz"; //Token da Organizacao
//Arthur
//const char* ID_DISPOSITIVO = "707489dd9e4dfdb2"; //ID Unico do Dispositivo
//const char* TOKEN_API = "RE7P2R5JP0Wjyjxv8WJbHOitW6OS44"; //Token da Organizacao
//Altere as variaveis acima de acordo com os valores gerados na plataforma

//Declaracao da variavel que armazena a senha de conexao ao servidor
const char* SENHA_ID = ""; //Nao e necessario altera-la

//Declaracao das variaveis que armazenam os Aliases das variaveis da plataforma
const char ALIAS1[] = "1D";
const char ALIAS2[] = "2D";
const char ALIAS3[] = "3D";
const char ALIAS4[] = "4D";
//Altere as variaveis acima de acordo com o que foi configurado na plataforma

//Declaracao da variavel auxiliar para a criacao do topico para publish
char TOPICO[50] = "device/";

//Declaracao da variavel que armazena o intervalo de tempo entre mensagens
unsigned long espera; //Variavel para o envio de mensagens
unsigned long reconecta; //Variavel para a conexao com o servidor
const long INTERVALO = 12000; // 2 minutos
