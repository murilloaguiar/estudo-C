#include <stdio.h>

int main(){
    float vetor_float[10] = {1.1, 2.2 , 3.3 ,4.4 , 5.5 , 6.6 , 7.7 , 8.8 , 9.9 , 10.1}, *pVetor = vetor_float;

    for (int i = 0; i < 10; i++){
        printf("%p, ", pVetor++);
    }
    
    return 0;

}