#include <stdio.h>
int main(){
   int x, y,i = 1, ref, aux;
   scanf("%d %d", &x, &y);
   ref = y-x;
   aux = ref;
   while(ref<y){
      i++;
      ref+=aux;
   }
   printf("%d\n", i);
   return 0;
}