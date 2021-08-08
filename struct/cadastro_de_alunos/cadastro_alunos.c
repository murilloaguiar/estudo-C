#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>
#include<conio.h>
#define MAX 3 
#define NOME 60

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
  char nome[NOME];
  unsigned long long int CPF;
  int matricula;
  Nota notas;
}Aluno;


int main(){
  setlocale(LC_ALL,"Portuguese");
  int option; 
  Aluno *alunos[MAX];

  inicializa(alunos);

  do{
    clear();
    printf("---------MENU------------\n");
    printf("1-Cadastrar aluno\n"
        "2-Mostrar alunos aprovados\n"
        "3-Procurar alunos\n"
        "0-Encerrar programa\n");
  
    printf("\nDigite sua escolha: ");
    scanf("%d%*c", &option);
    switch (option){
      case 1:
        printf("%d", posicao(alunos));
        cadastrarAluno(alunos, posicao(alunos));
        break;
      case 2:
        mostrarAprovados(alunos);
        break;
      case 3:
        //buscarAluno();
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

void cadastrarAluno(Aluno *pAluno[], int posicao){
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

  printf("\nDigite a matricula do aluno: ");
  scanf("%d%*c", &pAluno[posicao]->matricula);

  printf("\nDigite o CPF do aluno: ");
  scanf("%llu%*c", &pAluno[posicao]->CPF);
  
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

void mostrarAprovados(Aluno *pAlunos[]){
  int i = 0;
  while (pAlunos[i]!=NULL){
    printf("\n%s", pAlunos[i]->nome);
    printf("\n%llu", pAlunos[i]->CPF);
    printf("\n%d", pAlunos[i]->matricula);
    printf("\n%d", pAlunos[i]->notas.nota1);
    printf("\n%d", pAlunos[i]->notas.nota2);
    printf("\n%d", pAlunos[i]->notas.nota3);
    i++;
  }

  printf("\nPressione Enter para voltar: ");
  getchar();
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