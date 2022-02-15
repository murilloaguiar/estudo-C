#include <stdio.h>

int main(){
   int comprimento, varetas, vezes, pares = 0;

   while (1)
   {
      scanf("%d", &vezes);
      if(vezes==0) break;
      for (int i = 0; i < vezes; i++)
      {
         scanf("%d %d", &comprimento, &varetas);
         pares += varetas/2;  
      }
      
      printf("%d",pares/2);
      pares = 0;
   }
   return 0;
   
}