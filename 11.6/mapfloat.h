// ***************************************************************************************************
// *  Arquivo da função do remapeio do intevalo da entrada analógica                                 *
// *                                                                                                 *
// *  Desenvolvido por Arthur Petenão de Oliveira e Henrique Romera Salvador - Instituto InovaNex    *
// *  Versão 10 - Abril/2021                                                                         *
// *                                                                                                 *
// ***************************************************************************************************

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
