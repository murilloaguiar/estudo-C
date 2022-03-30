#include <stdio.h>

int main(void) {
  float nota1, nota2;
  int opcao;
  do{
    scanf("%f", &nota1);
    if(nota1<0 || nota1>10){
      while(nota1< 0 || nota1>10){
        printf("nota invalida\n");
        scanf("%f", &nota1);
      } 
    }
    
    scanf("%f", &nota2);
    if(nota2<0 || nota2>10){
      while(nota2< 0 || nota2>10){
        printf("nota invalida\n");
        scanf("%f", &nota2);
      } 
    }
  
    printf("media = %.2f\n", (nota1+nota2)/2);
    
    printf("novo calculo (1-sim 2-nao)\n");
    scanf("%d", &opcao);
    if(opcao>2 || opcao<0){
      while(opcao>2 || opcao<0){
        printf("novo calculo (1-sim 2-nao)\n");
        scanf("%d", &opcao);
      } 
    }
  }while(opcao==1);
  
  return 0;
}