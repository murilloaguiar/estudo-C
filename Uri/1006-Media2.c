#include <stdio.h>

int main(){
   double A=0,B=0,C=0;

   do{
      scanf("%lf %lf %lf",&A,&B,&C);
   } while (A<0 || A>10.0 || B<0 || B>10.0 || C<0 || C>10.0);
   

   printf("MEDIA = %.1lf\n", (A*2+B*3+C*5)/10);

   return 0;
}