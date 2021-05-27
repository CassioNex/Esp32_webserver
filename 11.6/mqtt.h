// ***************************************************************************************************
// *  Arquivo da função da comunicação MQTT com a plataforma da ProIOT                               *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Abril/2021                                                                         *
// *                                                                                                 *
// ***************************************************************************************************
void send_MQTT(){  
  //Verifica a conexao com o servidor
  if(!MQTT.connected()){ //Se nao estiver conectado
    if(reconecta < millis()){ //Executa a solicitacao de conexao a cada 5 segundos
      Serial.println("");
      Serial.println("Conectando ao servidor...");
      //Solicita a conexao com o servidor utilizando os parametros "ID_DISPOSITIVO", "TOKEN_API" e "SENHA_ID" 
      if(!MQTT.connect(ID_DISPOSITIVO, TOKEN_API, SENHA_ID)){
        Serial.println("Falha na conexao com o servidor.");
      } else {
        Serial.println("Conectado!");
        Serial.print("Enviando publicacoes para ");
        Serial.println(TOPICO);  
      }
      reconecta = millis() + 5000; //Atualiza a contagem de tempo
    }
  } else { //Se estiver conectado
    //Executa o envio de mensagens de acordo com a variavel "intervalo"
    if(espera < millis()){ 
      
      //Realiza a leitura de temperatura e umidade do sensor
      //led = digitalRead(PINO_led);
  
      //Verifica se a leitura foi feita corretamente
  
       //Cria o objeto dinamico "json" com tamanho "2" para a biblioteca
       DynamicJsonDocument json(JSON_OBJECT_SIZE(4));
        
       //Atrela ao objeto "json" as leitura do sensor com os Aliases definidos
       json[ALIAS1] = led_status;
       json[ALIAS2] = ledon_status;
       json[ALIAS3] = valor_pot;
       json[ALIAS4] = ledState_int;
       //Mede o tamanho da mensagem "json" e atrela o valor somado em uma unidade ao objeto "tamanho_mensagem"
       size_t tamanho_mensagem = measureJson(json) + 1;
        
       //Cria a string "mensagem" de acordo com o tamanho do objeto "tamanho_mensagem"
       char mensagem[tamanho_mensagem];
       
       //Copia o objeto "json" para a variavel "mensagem" e com o "tamanho_mensagem"
       serializeJson(json, mensagem, tamanho_mensagem);
        
       //Publica a variavel "mensagem" no servidor utilizando a variavel "TOPICO"
       Serial.println("");
       Serial.print("Mensagem enviada: ");
       Serial.println(mensagem);
       MQTT.publish(TOPICO, mensagem);
        
      espera = millis() + INTERVALO; //Atualiza a contagem de tempo pela variavel "intervalo"
    }
  }
}
