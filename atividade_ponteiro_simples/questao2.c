#include <stdio.h>

int main(){
    int numero1, numero2, *pNumero1 = &numero1,* pNumero2 = &numero2;

    //printf("\n\nEndereco de numero1 %p", &numero1);
    //printf("\n\nEndereco de numero2 %p", &numero2);
    printf("\n\nEndereco de numero1 %p", pNumero1);
    printf("\n\nEndereco de numero2 %p", pNumero2);

    if (pNumero1>pNumero2) //(&numero1 > &numero2)
        printf("\n\nEndereco de numero1 e maior");
    else 
        printf("\n\nEndereco de numero2 e maior");


    return 0;
    
}