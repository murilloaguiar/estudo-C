#include <stdio.h>
#include <math.h>

int main() {
  double valor, decimal;
  int inteiro;
  scanf("%lf", &valor);
  inteiro = (int)valor;
  decimal = valor-inteiro;
  
  
  printf("%d nota(s) de R$ 100.00\n", inteiro/100);
  inteiro -=  (inteiro/100)*100;
  printf("%d nota(s) de R$ 50.00\n", inteiro/50);

  return 0;
}