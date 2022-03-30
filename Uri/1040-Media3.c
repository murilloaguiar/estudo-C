#include <stdio.h>

int main(void) {
  float nota1, nota2, nota3, nota4, exame_final, media = 0;

  scanf("%f %f %f %f", &nota1,&nota2,&nota3,&nota4);

  media = (nota1*2)+(nota2*3)+(nota3*4)+nota4;
  media = media/10;
  printf("Media: %.1f\n", media);

  if(media<5.0) printf("Aluno reprovado.\n");
  else if(media >=5.0 && media<=6.9){
    printf("Aluno em exame.\n");
    scanf("%f", &exame_final);
    printf("Nota do exame: %.1f\n", exame_final);
    media = (media+exame_final)/2;
    if(media>=5.0) printf("Aluno aprovado.\n");
    else printf("Aluno reprovado.\n");
    printf("Media final: %.1f\n", media);
  }else printf("Aluno aprovado.\n");
  

  return 0;
}