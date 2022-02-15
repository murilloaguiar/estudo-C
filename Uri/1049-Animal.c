#include <stdio.h>
#include <string.h>

int main(void) {
  char no1[20], no2[20], no3[20];

  scanf("%s", no1);
  scanf("%s", no2);
  scanf("%s", no3);

  if(strcmp(no1,"vertebrado")==0){

    if(strcmp(no2,"ave")==0){
      if(strcmp(no3,"carnivoro")==0){
        printf("aguia\n");
      }else if(strcmp(no3,"onivoro")==0){
        printf("pomba\n");
      }

    }else if(strcmp(no2,"mamifero")==0){
      if(strcmp(no3,"onivoro")==0){
        printf("homem\n");
      }else if(strcmp(no3,"herbivoro")==0){
        printf("vaca\n");
      }
    }

  }else if(strcmp(no1,"invertebrado")==0){
    if(strcmp(no2,"inseto")==0){
      if(strcmp(no3,"hematofago")==0){
        printf("pulga\n");
      }else if(strcmp(no3,"herbivoro")==0){
        printf("lagarta\n");
      }

    }else if(strcmp(no2,"anelideo")==0){
      if(strcmp(no3,"hematofago")==0){
        printf("sanguessuga\n");
      }else if(strcmp(no3,"onivoro")==0){
        printf("minhoca\n");
      }
    }
  }
  return 0;
}