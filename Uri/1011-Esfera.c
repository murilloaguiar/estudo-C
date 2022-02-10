#include <stdio.h>
#include <math.h>

int main(void) {
  float raio, volume;

  scanf("%f", &raio);

  raio = pow(raio, 3);
  volume=(4.0*3.1415*raio)/3;
  printf("VOLUME = %.3lf\n", volume);

  return 0;
}