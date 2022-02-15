#include <stdio.h>
#include <math.h>

int main(){

   int distancia, vf, vg, n;
   double dg;

   while (scanf("%d%d%d", &distancia, &vf, &vg) != EOF){
      dg = pow(distancia,2)+144;
      dg = sqrt(dg);
      
      if((dg/vg)<=(12.00/vf)) printf("S\n");
      else printf("N\n");
   }
   
   
   return 0;
}