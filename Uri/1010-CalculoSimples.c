#include <stdio.h>

int main(void) {
  int codigo_peca, quantidade_pecas;
  float valor_unitario, valor_total=0;
  for(int i = 0; i<2; i++){
    scanf("%d %d %f", &codigo_peca, &quantidade_pecas, &valor_unitario);
    valor_total += quantidade_pecas*valor_unitario;
  }
  printf("VALOR A PAGAR: R$ %.2f\n",valor_total);
  return 0;
}