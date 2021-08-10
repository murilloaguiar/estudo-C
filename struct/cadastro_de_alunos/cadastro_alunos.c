#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>
#include <conio.h>
#define MAX 3 
#define NOME 60
#define CPF 12

void inicializa();
void cadastrarAluno();
//void verificarCPF();
//void buscarAluno();
void mostrarAprovados();
int posicao();
void cleanStdin();
void clear();

typedef struct notas{
  int nota1, nota2, nota3;
}Nota;


typedef struct cadastroAlunos{
  char nome[NOME], cpf[CPF];
  //unsigned long long int CPF;
  int matricula;
  Nota notas;
}Aluno;


int main(){
  setlocale(LC_ALL,"Portuguese");
  int option, matricula; 
  char cpf[CPF];
  Aluno *alunos[MAX];

  inicializa(alunos);

  do{
    clear();
    printf("---------MENU------------\n");
    printf("1-Cadastrar aluno\n"
        "2-Mostrar alunos aprovados\n"
        "3-Procurar aluno por CPF\n"
        "4-Procurar aluno por Matricula\n"
        "0-Encerrar programa\n");
  
    printf("\nDigite sua escolha: ");
    scanf("%d%*c", &option);
    switch (option){
      case 1:
        printf("Gravando na posicao: %d", posicao(alunos));
        printf("\nDigite a matricula do aluno: ");
        scanf("%d%*c", &matricula);
        if(!verificaMatricula(alunos, matricula)){
          break;
        }
        printf("\nDigite o cpf: ");
        fgets(cpf, CPF, stdin);
        //fgets coloca um \n (fim de linha) na string, então substituo isso por \0, que indica fim da string realmente
        cpf[strcspn(cpf,"\n")] = '\0';

        //limpar o buffer de entrada e não deixar a string passar da quantidade de caracteres
        if(strcspn(cpf, "\0") == (CPF-1)){
          cleanStdin();
        }

        if (!stringToInt(cpf)){
          break;
        }
          
        cadastrarAluno(alunos, posicao(alunos), matricula, cpf);
        
        break;
      case 2:
        mostrarAprovados(alunos);
        break;
      case 3:
        buscarAlunoCPF(alunos);
        break;
      case 4:
        buscarAlunoMatricula(alunos);
        break;
      case 0:
        exit(1);
        break;
      default:
        printf("digite um opção válida");
        break;
    }
  }while(option != 0);


  return 0;
}

//funcao para deixar a "tabela" vazia
void inicializa(Aluno *pAluno[]){
  for (int i = 0; i < MAX; i++){
    pAluno[i] = NULL;
  }
}

void cadastrarAluno(Aluno *pAluno[], int posicao, int matricula, char *cpf){
  pAluno[posicao] = malloc(sizeof(Aluno));

  if (!pAluno[posicao]){
    printf("\nNao foi possivel cadastrar alunos. Memoria nao alocada\n");
    return;
  }


  printf("\nDigite o nome do aluno: ");
  fgets(pAluno[posicao]->nome, NOME, stdin);
  //fgets coloca um \n (fim de linha) na string, então substituo isso por \0, que indica fim da string realmente
  pAluno[posicao]->nome[strcspn(pAluno[posicao]->nome,"\n")] = '\0';

  //limpar o buffer de entrada e não deixar a string passar da quantidade de caracteres
  if(strcspn(pAluno[posicao]->nome, "\0") == (NOME-1)){
    cleanStdin();
  }

  pAluno[posicao]->matricula = matricula;

  strcpy(pAluno[posicao]->cpf, cpf);
  printf("\nDigite a primeira nota: ");
  scanf("%d%*c", &pAluno[posicao]->notas.nota1);

  printf("\nDigite a seginda nota: ");
  scanf("%d%*c", &pAluno[posicao]->notas.nota2);

  printf("\nDigite a terceira nota: ");
  scanf("%d%*c", &pAluno[posicao]->notas.nota3);

  printf("\nPressione Enter para voltar: ");
  getchar();
  
}

//recupera uma posição livre para armazenar um aluno
int posicao(Aluno *pAluno[]){
  int posicao = 0;

  for (int i = 0; i < MAX; i++){
    if (pAluno[i] == NULL){
      return posicao;
    }
    posicao++;
  }
  return -1;
}

int verificaMatricula(Aluno *pAluno[], int matricula){
  int i = 0;
  while (pAluno[i]!=NULL){
    if (pAluno[i]->matricula==matricula){
      printf("\nMatricula já existe!");
      getchar();
      return 0;
    }
    i++;
  }
  return 1;
}

//mostra apenas alunos cuja a media das tres notas foi maior ou igual que 7
void mostrarAprovados(Aluno *pAlunos[]){
  int i = 0;
  float media;
  printf("--------APROVADOS-------------");
  while (pAlunos[i]!=NULL){
    media = (pAlunos[i]->notas.nota1 + pAlunos[i]->notas.nota2 + pAlunos[i]->notas.nota3) / 3;
    if (media>=7){
      printf("\nNome: %s", pAlunos[i]->nome);
      printf("\nCPF: %s", pAlunos[i]->cpf);
      printf("\nMatricula: %d", pAlunos[i]->matricula);
      printf("\nNota 1: %d", pAlunos[i]->notas.nota1);
      printf("\nNota 2: %d", pAlunos[i]->notas.nota2);
      printf("\nNota 3: %d", pAlunos[i]->notas.nota3);
      printf("\nMedia: %.2f", media);
    }
    i++;
  }

  printf("\nPressione Enter para voltar: ");
  getchar();
}

//mostra os dados de um aluno que corresponda ao cpf passado como parametro
void buscarAlunoCPF(Aluno *pAlunos[]){
  int i=0;
  char cpf[CPF];
  printf("\nDigite o cpf: ");
  fgets(cpf, CPF, stdin);
  //fgets coloca um \n (fim de linha) na string, então substituo isso por \0, que indica fim da string realmente
  cpf[strcspn(cpf,"\n")] = '\0';

  //limpar o buffer de entrada e não deixar a string passar da quantidade de caracteres
  if(strcspn(cpf, "\0") == (CPF-1)){
    cleanStdin();
  }

  while (pAlunos[i]!=NULL){ 
    if (!strcoll(pAlunos[i]->cpf,cpf)){
      printf("\nNome: %s", pAlunos[i]->nome);
      printf("\nCPF: %s", pAlunos[i]->cpf);
      printf("\nMatricula: %d", pAlunos[i]->matricula);
      printf("\nNota 1: %d", pAlunos[i]->notas.nota1);
      printf("\nNota 2: %d", pAlunos[i]->notas.nota2);
      printf("\nNota 3: %d", pAlunos[i]->notas.nota3);
      printf("\nPressione Enter para voltar: ");
      getchar();
      return;
    }
    i++;
  }
  printf("\nNão encontrado ");
  getchar();
}

//mostra os dados de um aluno que corresponda a matricula passado como parametro
void buscarAlunoMatricula(Aluno *pAlunos[]){
  int i=0, matricula;
  printf("\nDigite a matricula: ");
  scanf("%d%*c", &matricula);
  while (pAlunos[i]!=NULL){ 
    if (pAlunos[i]->matricula==matricula){
      printf("\nNome: %s", pAlunos[i]->nome);
      printf("\nCPF: %s", pAlunos[i]->cpf);
      printf("\nMatricula: %d", pAlunos[i]->matricula);
      printf("\nNota 1: %d", pAlunos[i]->notas.nota1);
      printf("\nNota 2: %d", pAlunos[i]->notas.nota2);
      printf("\nNota 3: %d", pAlunos[i]->notas.nota3);
      printf("\nPressione Enter para voltar: ");
      getchar();
      return;
    }
    i++;
  }
  printf("\nNão encontrado ");
  getchar();
  
}

/* INCOMPLETA
int validaCPF(int *pCPF){
  int cpf_aux[11];
  int resultado = 0, j = 2;
  
  for (int i = 0; i < 9; i++){
    cpf_aux[i] = pCPF[i];
  }
  
  for (int i = 8; i <= 0; i--){
    resultado += pCPF[i] * j;
    j++;
  }
  j = 2;

  if ((resultado%11 > 2)){
    cpf_aux[10] = (11-(resultado%11));
  }else if ((resultado%11 > 2)){
    cpf_aux[10] = 0;
  }
  
  for (int i = 9; i <= 0; i--){
    resultado += pCPF[i] * j;
    j++;
  }

  if ((resultado%11 > 2)){
    cpf_aux[11] = (11-(resultado%11));
  }else if ((resultado%11 > 2)){
    cpf_aux[11] = 0;
  }

  for (int i = 0; i < 11; i++){
    if (cpf_aux[i]!=pCPF[i]){
      return 0;
    }
  }

  return 1;

}*/

int stringToInt(char *pCPF/*, int *cpf_aux*/){
  int i = 0;
  if (strlen(pCPF)!=11)
  {
    
    printf("\nCPF TEM MENOS CARACTERES QUE O DEVIDO");
    getchar();
    return 0;
  }
  /*
  while (*pCPF++)
  {
    cpf_aux[i] = (int)(pCPF[i]-'0');
    i++;

  }
  
  return 1;*/
}

//funcao para limpar o buffer do teclado, mais ideal do que setbuf ou fflush
void cleanStdin(){
  int c;
  do{
    c = getchar();
  }while (c != '\n' && c != EOF);
}

void clear(){
  #if defined(__linux__)||defined(__unix__)
    system("clear");
  #endif

  #if defined(__WIN32)||defined(__WIN64)
    system("cls");
  #endif
}