#include <stdio.h>
#include <stdlib.h>

int main(){
    int inteiro = 5, *pInteiro = &inteiro;
    char caractere = 'c', *pCaractere = &caractere;
    float flutuante = 5.5, *pFlutuante = &flutuante;
    
    printf("\n\nAntes da mudanca: %d, %.2f, %c", inteiro, flutuante, caractere);
    
    *pInteiro = 10;
   
    *pFlutuante = 10.5;

    *pCaractere = 's';

    printf("\n\nDepois da mudanca: %d, %.2f, %c \n", inteiro, flutuante, caractere);


    return 0;
}
