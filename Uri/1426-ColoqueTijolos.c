#include <stdio.h>
#include <string.h>

int main(){
   int count, matriz[9][9];
   
   scanf("%d", &matriz[0][0]);
   scanf("%d %d", &matriz[2][0], &matriz[2][2]);
   scanf("%d %d %d", &matriz[4][0], &matriz[4][2], &matriz[4][4]);
   scanf("%d %d %d %d", &matriz[6][0], &matriz[6][2], &matriz[6][4], &matriz[6][6]);
   scanf("%d %d %d %d %d", &matriz[8][0], &matriz[8][2], &matriz[8][4], &matriz[8][6], &matriz[8][8]);
   
   
   
   //preenchendo a ultima coluna
   for (int i = 1; i < 8; i+=2)
   {
      matriz[8][i] = (matriz[6][i-1]-(matriz[8][i-1]+matriz[8][i+1]))/2;
   }


   for (int i = 0; i < 7; i++)
   {
      matriz[7][i] = (matriz[8][i]+matriz[8][i+1]);
   }

   for (int i = 6; i <=0 ; i--)
   {
      for (int j = 0; j <= i; j++)
      {
         matriz[i][j] = (matriz[i+1][j]+matriz[i+1][j+1]);
      }
      
      
   }

   printf("%d", matriz[6][1]);
   // for (int i = 0; i < 9; i++)
   // {
      
   //    for (int j = 0; j <=i; j++)
   //    {
   //       printf("%d ", matriz[i][j]);
         
   //    }
   //    printf("\n");
   // }

   // for (int i = 0, j = 0; i < 8; i++)
   // {
   //    printf("%d ", matriz[7][i]);
   // }
   // printf("\n");
   // for (int i = 0, j = 0; i < 9; i++)
   // {
   //    printf("%d ", matriz[8][i]);
   // }
   
   
   return 0;
}