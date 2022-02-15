#include <stdio.h>
int main(){
   int count, joao = 0, maria = 0, jogo;
   while (1){
      scanf("%d", &count);
      if (count==0)break;
      for (int i = 0; i < count; i++){
         scanf("%d", &jogo);
         if(jogo==0) maria++;
         else if(jogo==1) joao++;
      }
      printf("Mary won %d times and John won %d times\n", maria, joao);
      joao = 0;
      maria = 0; 
   }
   return 0;
}