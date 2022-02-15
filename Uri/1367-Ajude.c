#include <stdio.h>
#include <string.h>
int main(){
   int count, tempo, corretos = 0, incorretos = 0, tempo_total = 0;
   char codigo[10], status[20], ref = '1', ref_correct = '1';
   while (1){
      scanf("%d", &count);
      if(count==0) break;
      for (int i = 0; i < count; i++){
         scanf("%s %d %s", codigo, &tempo, status);
         if(strcmp(status,"incorrect")==0 && i==0){
            incorretos++;
            ref = codigo[0];
         }else if(strcmp(status,"correct")==0 && i==0){
            ref_correct = codigo[0];
            corretos++;
            tempo_total+=tempo;
         }else if(strcmp(status,"incorrect")==0 && codigo[0]==ref) incorretos++;
         else if(strcmp(status,"incorrect")==0 && codigo[0]!=ref){
            incorretos = 1;
            ref = codigo[0];
         } 
         else if(strcmp(status,"correct")==0 && codigo[0]==ref && codigo[0]!=ref_correct){
            corretos++;
            tempo_total += tempo+(incorretos)*20;
            ref_correct = codigo[0];
         }else if(strcmp(status,"correct")==0 && codigo[0]!=ref_correct){
            corretos++;
            tempo_total += tempo;
            ref_correct = codigo[0];
         }
      }
      printf("%d %d\n", corretos, tempo_total);
      ref = '1';
      ref_correct = '1';
      incorretos = 0;
      corretos = 0;
      tempo_total = 0;
   }
   return 0;
}