#include <stdio.h>

int main(void) {
  int populacaoA, populacaoB, count, anos = 0;
  double taxaA, taxaB;
  
  scanf("%d", &count);
  for(int i = 0; i < count; i++){
    scanf("%d %d %lf %lf", &populacaoA, &populacaoB, &taxaA, &taxaB);
  
    while(populacaoA<=populacaoB){
      populacaoA += (int)(populacaoA * taxaA/100);
      
      if(taxaB>0) populacaoB += (int)(populacaoB * taxaB/100);
      anos++;
      
      if (anos>100){
        printf("Mais de 1 seculo.\n");
        break;
      }
    }
    if(anos<=100)printf("%d anos.\n", anos);
    anos = 0;
  }
  
  return 0;
}