#include <stdio.h>
#include <stdlib.h>

double main(void){
    double A,B,MEDIA=0;

    scanf("%lf %lf", &A , &B);

    if(A>=0 && A<=10.0 && B>=0 && B<=10.0){
        MEDIA = (A*3.5 + B*7.5) / 11 ;
        printf("MEDIA = %.5lf\n", MEDIA);
    }else{
        printf("Digite uma nota valida (entre 0 e 10)");
    }

}
