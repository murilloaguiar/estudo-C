#include <stdio.h>

int main(){
    int vetor_int[5], *pVetor = vetor_int;

    for (int i = 0; i < 5; i++){
        printf("\nDigite o %d numero: ", i+1);
        scanf("%d", pVetor);
        pVetor++;
    }

    pVetor = &vetor_int[0];
    
    for (int i = 0; i < 5; i++){
        printf("%d, ", *pVetor * *pVetor);
        pVetor++;
    }
    
    
    return 0;
}
