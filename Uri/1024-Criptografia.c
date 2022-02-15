#include <stdio.h>
#include <string.h>

int main(){
   int count, tamanho;
   char mensagem[1000], ref = 'a';

   scanf("%d",&count);
   if(count == 0) return 0;
   for (int i = 0; i < count; i++){
      scanf(" %[^\n]", mensagem);
      tamanho = strlen(mensagem);
      
      for (int i = 0; i < tamanho; i++){
         if (((int)mensagem[i]>=65 && (int)mensagem[i] <= 90) || ((int)mensagem[i]>=97 && (int)mensagem[i] <= 122)) mensagem[i] += 3; 
      }
      
      for (int i = 0;  i < tamanho; i++)
      {
         ref = mensagem[i];
         mensagem[i] = mensagem[tamanho-1];
         mensagem[tamanho-1] = ref;
         tamanho--;
      }
      
      tamanho = strlen(mensagem);
      for (int i = tamanho/2; i < tamanho; i++)
      {
         mensagem[i] -= 1; 
      }
      
      printf("%s\n", mensagem);
   }
   
   


   return 0;
}