#include <stdio.h>

int main(void) {
  int horas, minutos, segundos, aux_inicial, aux_final, aux_resultado, dia_inicio, dia_final;
  

  scanf("Dia %d", &dia_inicio);
  
  scanf("%d : %d : %d\n", &horas, &minutos, &segundos);
  
  aux_inicial = horas*3600;
  aux_inicial+= minutos*60;
  aux_inicial+= segundos;
  
  scanf("Dia %d", &dia_final);
  
  scanf(" %d : %d : %d", &horas, &minutos, &segundos);

  aux_final = (dia_final-dia_inicio)*86400;
  aux_final+= horas*3600;
  aux_final+= minutos*60;
  aux_final+= segundos;

  aux_resultado = aux_final - aux_inicial;

  printf("%d dia(s)\n", aux_resultado/86400);
  aux_resultado = aux_resultado%86400;
  printf("%d hora(s)\n", aux_resultado/3600);
  aux_resultado = aux_resultado%3600;
  printf("%d minuto(s)\n",aux_resultado/60);
  aux_resultado = aux_resultado%60;
  printf("%d segundo(s)\n",aux_resultado);

  return 0;
}