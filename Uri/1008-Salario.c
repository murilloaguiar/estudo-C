#include <stdio.h>

int main(void) {
  int funcionario, horas_trabalhadas;
  float  valor_hora, salario;

  scanf("%d %d %f", &funcionario, &horas_trabalhadas, &valor_hora);

  salario = horas_trabalhadas*valor_hora;

  printf("NUMBER = %d\n", funcionario);
  printf("SALARY = R$ %.2f\n", salario);

  return 0;
}