#include <stdio.h>

int main(void) {
  int netos_portas;

  while(1){
    scanf("%d", &netos_portas);

    if(netos_portas==0) break;

    for(int i = 1; i*i<=netos_portas; i++){
      if((i+1)*(i+1)>netos_portas) printf("%d",i*i);
      else if(i*i!=netos_portas)printf("%d ",i*i);
    }
    printf("\n");

  }
  return 0;
}