#include <stdio.h>

int main(){

   int h1, h2, m1, m2, minutos_iniciais, minutos_finais;

   while (1){
      scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
      if(m1==0 && m2==0 && h1==0 && h2==0) break;
       
      if (h1<h2 || (h2==h1 && m1<m2)){
         minutos_iniciais = (h1*60+m1);
         minutos_finais = (h2*60+m2)-minutos_iniciais;
      }else if (h1>h2 || (h2==h1 && m1>m2)){
         minutos_iniciais = (h1*60+m1);
         minutos_finais = ((h2+24)*60+m2)-minutos_iniciais;
      }else minutos_finais = 1440;
      
      printf("%d\n", minutos_finais);
   }

   return 0;
}