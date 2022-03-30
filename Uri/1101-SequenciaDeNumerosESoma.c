#include <stdio.h>

int main(void) {
  int numero1, numero2, soma = 0, maior, menor;

  while(1){
    scanf("%d %d", &numero1, &numero2);
    if(numero1 <= 0 || numero2 <= 0) break;
    if(numero1>numero2){
      maior = numero1;
      menor = numero2;
    }else if(numero2>numero1){
      maior = numero2;
      menor = numero1;
    }

    for(int i = menor; i<=maior; i++){
      soma += i; 
      printf("%d ", i);
      if(i==maior) printf("Sum=%d\n", soma);
    }

    soma = 0;

  }
  return 0;
}