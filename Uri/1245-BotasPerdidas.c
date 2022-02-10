#include <stdio.h>

int main(){

   int direito[61], esquerdo[61], botas, tamanho, pares=0;
   char lado[3];

   while (scanf("%d", &botas) != EOF){
      if (!botas) break;
      
      for (int i = 30; i < 61; i++){
         direito[i] = 0;
         esquerdo[i] = 0;
      }

      for (int j = 0; j < botas; j++){
         scanf("%d %s", &tamanho, lado);
         if(lado[0] == 'D') direito[tamanho]++;
         else if (lado[0] == 'E') esquerdo[tamanho]++;

      }

      for (int x = 30; x < 61; x++){
         if(direito[x] !=0 && esquerdo[x] !=0){
            if (direito[x] > esquerdo[x] || direito[x]== esquerdo[x]) pares+=esquerdo[x];
            else pares+=direito[x];
         }
      }

      printf("%d\n", pares);
      pares=0;
   }
   
}