// ***************************************************************************************************
// *  Arquivo de pinagem e definição de variáveis                                                    *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 11 - Maio/2021                                                                          *
// *                                                                                                 *
// ***************************************************************************************************


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ! PINOS QUE NÃO PODEM SER UTILIZADOS: 23, 19, 18, 5, 0                                            !
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define Device_1 "Lampada"
#define Device_2 "LED ON"
fauxmoESP fauxmo;

long potValue = 0;
float valor_pot;
float map_potV;
float potV = 0;
float potVmax = 0;
float potVmin = 20;

const int potPin = 34;

// Set LED GPIO
const int ledPin = 15;
const int ledPin2 = 2;
const int btPin = 22;

const int bton = 13;
const int ledon = 12;//será trocado para 4

// Guarda estado LED
String ledState = "OFF";
int ledState_int = 0;

//Guarda o estado da memória
String memstate;

const char* PARAM_INPUT_bt = "state";
const char* PARAM_INPUT_on = "stateon";

const char* PARAM_INPUT_eeled01 = "state1";
const char* PARAM_INPUT_eeled02 = "state2";
const char* PARAM_INPUT_eeled03 = "state3";
const char* PARAM_INPUT_eemqtt01 = "state4";
const char* PARAM_INPUT_eelog01 = "state5";

int led_status = LOW; // Status atual do relay1
int bt_status; // Status atual do switch1
int last_bt_status = LOW; // Ultimo status do switch1


int ledon_status = LOW; // Status atual do relayon
int bton_status; // Status atual do switchon
int last_bton_status = LOW; // Ultimo status do switchon

int led1_status = LOW; // Status atual do relay1
int bt1_status; // Status atual do switch1
int last_bt1_status = LOW; // Ultimo status do switch1

int led2_status = LOW; // Status atual do relay2
int bt2_status; // Status atual do switch2
int last_bt2_status = LOW; // Ultimo status do switch2

int led3_status = LOW; // Status atual do relay3
int bt3_status; // Status atual do switch3
int last_bt3_status = LOW; // Ultimo status do switch3

int led4_status = LOW; // Status atual do relay4
int bt4_status; // Status atual do switch4
int last_bt4_status = LOW; // Ultimo status do switch4

int led5_status = LOW; // Status atual do relay5
int bt5_status; // Status atual do switch5
int last_bt5_status = LOW; // Ultimo status do switch5

int LED01 = 0;    // Status de envio do led
int LED02 = 0;   // Status de envio do led2
int LED03 = 0;   // Status de envio do ledon
int LOG01 = 0;   //Status de encio do Log in
int MQTT01 = 0;  // Status de envio do MQTT

String SLED01 = "ON";    // Status de envio do led
String SLED02 = "ON";   // Status de envio do led2
String SLED03 = "ON";   // Status de envio do ledon
String SLOG01 = "ON";   //Status de encio do Log in
String SMQTT01 = "ON";  // Status de envio do MQTT


// As variaveis a seguir são unsigned longs porque o tempo, medido em
// milisegundos, rapidamente se tornará um número maior do que pode ser armazenado em um int.
unsigned long lastDebounceTime = 0; // a última vez que o pino de saída foi alternado
unsigned long debounceDelay = 50; // o tempo de debounce; aumenta se a saída 

//login
String nome;
String dado;
String asenha;
String bsenha;

int n = 0;
// String  logap;

int logstate = 0;
int pswstate = 0;
