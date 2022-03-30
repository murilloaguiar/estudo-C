#include <stdio.h>

int main(void) {
  int chave, fator;
  
  for(int i = 0; i<20; i++){
    scanf("%d %d", &chave, &fator);
    if (chave == 0 && fator == 0) break;


    for(int i = 2; i<=chave; i++){
      if(i>=fator){
        printf("GOOD\n");
        break;
      }
      
      if(chave%i == 0 && i>=fator ){
        printf("GOOD\n");
        break;
      }else if(chave%i == 0 && i<=fator){
        printf("BAD %d\n", i);
        break;
      }
       
    }
  }

  return 0;
}