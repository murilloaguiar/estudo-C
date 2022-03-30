#include <stdio.h>

int main(void) {
  int count, quantidade, sapo = 0, rato = 0, coelho = 0, total = 0;
  char tipo; 
  
  scanf("%d", &count);

  for(int i = 1; i<=count; i++){
    scanf("%d %c", &quantidade, &tipo);
    if(tipo=='C') coelho+= quantidade;
    else if(tipo=='R') rato+= quantidade;
    else if(tipo=='S') sapo+= quantidade;
    total +=quantidade;
  }
  printf("Total: %d cobaias\n", total);
  printf("Total de coelhos: %d\n", coelho);
  printf("Total de ratos: %d\n", rato);
  printf("Total de sapos: %d\n", sapo);
  printf("Percentual de coelhos: %.2f %\n", (float)coelho/total *100);
  printf("Percentual de ratos: %.2f %\n", (float)rato/total *100);
  printf("Percentual de sapos: %.2f %\n", (float)sapo/total *100);

  return 0;
}