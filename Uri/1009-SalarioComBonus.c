#include <stdio.h>

int main(void) {
  char nome_vendedor[30];
  double salario_fixo, vendas_mes, montante;

  scanf("%s %lf %lf", nome_vendedor, &salario_fixo, &vendas_mes);

  montante = salario_fixo + (vendas_mes*0.15);

  printf("TOTAL = R$ %.2lf\n", montante);

  return 0;

}