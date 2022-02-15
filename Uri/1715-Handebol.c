#include <stdio.h>
int main(){
   int count, partidas, gols, contador = 0, resultado=0;

   scanf("%d %d", &count, &partidas);
   for (int i = 0; i < count; i++){
      for (int j = 0; j < partidas; j++){
         scanf("%d", &gols);
         if(gols>0) contador++;
      }
      if(contador==partidas){
         resultado += contador/partidas;
      } 
      contador = 0;

   }

   printf("%d\n", resultado);
   return 0;
}