#include <stdio.h>

int main(void)
{

   int comandos, esquerda = 0, direita = 0;

   while (1)
   {
      scanf("%d", &comandos);
      if (comandos == 0)
         break;
      char lados[comandos + 1];

      scanf("%s", lados);

      for (int i = 0; i < comandos; i++)
      {
         if (lados[i] == 'E')
            esquerda++;
         else
            direita++;
      }
      printf("D %d - E %d\n", direita, esquerda);
      if(esquerda == direita || abs(direita-esquerda)%4==0) printf("N\n");
      else if(abs((esquerda-direita)+ 3)%4 == 0 || abs((direita-esquerda)+ 1)%4 == 0)printf("O\n");
      else if(abs(direita-esquerda-1)%4==0 || abs(esquerda-direita+1)%4==0  )printf("L\n");
      else printf("S\n");
      
      direita = 0;
      esquerda = 0;
   }

   return 0;
}