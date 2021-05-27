// ***************************************************************************************************
// *  Arquivo da função da entrada analógica                                                         *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Abril/2021                                                                         *
// *                                                                                                 *
// ***************************************************************************************************

float Analog(int pot_Pin){
  potValue = 0;
  int f=0;
  // Reading potentiometer value
  for(f=0;f<20; f++){
    potValue += analogRead(pot_Pin);
    delay(10);
  }
  potV = potValue/20;
  map_potV = mapfloat(potV, 0, 4095, 0, 3.3);
  if (map_potV > potVmax){
    potVmax = map_potV;
  }
  if (map_potV<potVmin){
    potVmin = map_potV;
  }
  return map_potV;
}
