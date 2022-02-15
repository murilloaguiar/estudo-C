#include <stdio.h>
int main(){
   int count, notas, contador0 = 0, contador255 = 0, posicao;
   char alternativas[] = "ABCDE";

   while (1){
      scanf("%d", &count);
      if(count==0) break;

      for (int i = 0; i < count; i++){
         for (int j = 0; j < 5; j++){
            scanf("%d",&notas);
            if (notas<=127){
               contador0++;
               posicao = j;
            }else if (notas>127) contador255++;
         }
         if (contador0!=1 || contador255==5){
            printf("*\n");
         }else printf("%c\n", alternativas[posicao]);
         contador0 = 0;
         contador255 = 0;    
      }
   }
   return 0;
}