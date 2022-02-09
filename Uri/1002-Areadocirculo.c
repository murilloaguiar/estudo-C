#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double main(void) {
    double raio, area = 0, PI = 3.14159;

    scanf("%lf", &raio);

    area = pow(raio,2)*PI;

    printf("A=%.4lf", area);

    printf("\n");

    return 0;
}
