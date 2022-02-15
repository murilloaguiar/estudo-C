#include <stdio.h>

int main(){

   int numero_cartas, i = 0, posicao = 1;

   scanf("%d", &numero_cartas);

   do{
      i++;
      posicao = posicao * 2;
      if(posicao > numero_cartas){
         posicao = posicao - (numero_cartas + 1);
         
      }
  
   } while (posicao!=1);
   
   printf("%d\n", i);

   return 0;
}