// ***************************************************************************************************
// *  Arquivo das credenciais da rede                                                                *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Abril/2021                                                                         *
// *                                                                                                 *
// ***************************************************************************************************

//******Credenciais da rede************
const char* ssid = "DoNex";
const char* password = "inova137nex";

const char * USER = "admin";
const char * SENHA = "admin123";

//IPAddress ip(192,168,1,8); //COLOQUE UMA FAIXA DE IP DISPONÍVEL DO SEU ROTEADOR. EX: 192.168.1.110 **** ISSO VARIA, NO MEU CASO É: 192.168.0.175
IPAddress ip(192,168,1,25);
IPAddress gateway(192,168,1,1); //GATEWAY DE CONEXÃO (ALTERE PARA O GATEWAY DO SEU ROTEADOR)
IPAddress subnet(255,255,0,0); //MASCARA DE REDE
//************************************************
