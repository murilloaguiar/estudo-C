#include <stdio.h>
#include <math.h>

int main() {
  double valor, decimal;
  int notas[6] = {100,50,20,10,5,2}, moedas[6]= {100,50,25,10,5,1};
  
  while(1){
    scanf("%lf", &valor);
    if(valor==0) break;

    decimal = valor-(int)valor;
    printf("NOTAS: \n");
    for(int i = 0; i<6; i++ ){
      printf("%d nota(s) de R$ %.2lf\n", (int)valor/notas[i], (double)notas[i]);
      valor = (int)valor%notas[i];
    }

    valor=(valor+decimal)*100;

    printf("MOEDAS: \n");
    for(int i = 0; i<6; i++ ){
      printf("%d moedas(s) de R$ %.2lf\n", (int)valor/moedas[i], moedas[i]/100.00);
      valor = (int)valor%moedas[i];
    }

  }
  

  return 0;
}