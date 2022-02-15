#include <stdio.h>
int main(){
   int a,b;
   scanf("%d%d", &a, &b);
   if(a==b) printf("%d\n", a);
   else printf("%d\n", (a+b+abs(a-b))/2);
   return 0;
}