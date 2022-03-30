#include <stdio.h>
#include <string.h>

int main(void) {
  char aah[1000], aah_medico[1000];

  scanf("%s", aah);
  
  scanf("%s", aah_medico); 

  if(strlen(aah)>=strlen(aah_medico)) printf("go\n");
  else printf("no\n");
   
  return 0;
}