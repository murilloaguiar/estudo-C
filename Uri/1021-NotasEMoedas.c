#include <stdio.h>
#include <math.h>

int main()
{
   double valor, quociente, notas[12] = {100, 50, 20, 10, 5, 2, 1, 0.5, 0.25, 0.10, 0.05, 10/1000};

   while (1)
   {
      scanf("%lf", &valor);
      if (valor == 0)
         break;

      // decimal = valor-(int)valor;
      // printf("decimal: %lf\n", decimal);
      printf("NOTAS: \n");

      for (int i = 0; i < 6; i++)
      {
         quociente = floor(valor / notas[i]);
         printf("%.0lf nota(s) de R$ %.2lf\n", quociente, notas[i]);
         valor = fmod(valor, notas[i]);
         printf("valor: %lf\n", valor);
      }

      // printf("valor: %d\n", (int)valor);
      printf("MOEDAS: \n");

      for (int i = 6; i < 12; i++)
      {
         quociente = floor(valor / notas[i]);
         printf("%.0lf moedas(s) de R$ %.2lf\n", quociente, notas[i]);
         valor = fmod(valor, notas[i]);
         printf("valor: %lf\n", valor);
      }
   }

   // scanf("%lf", &valor);
   // decimal = fmod(valor, 100.00);
   // quociente = (valor / notas[3]);
   // printf("%lf", quociente);

   return 0;
}