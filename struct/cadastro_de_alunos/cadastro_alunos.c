#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#define MAX 3 

void inicializa();
void cadastrarAluno();
void verificarCPF();
void buscarAluno();
void mostrarAprovados();
void cleanStdin();
void clear();

typedef struct cadastroAlunos{
  char nome[60];
  unsigned long long int CPF;
  int matricula;
  int nota1, nota2, nota3;
}Aluno;


int main(){
  setlocale(LC_ALL,"Portuguese");
  int option; 
  Aluno *alunos[MAX];

  void inicializa(alunos);

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
        cadastrarAluno(alunos, posicao(alunos));
        break;
      case 2:
        mostrarAprovados();
        break;
      case 3:
        buscarAluno();
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
  
}

int posicao(Aluno *pAluno[]){
  int posicao = 0;

  for (int i = 0; i < MAX; i++){
    if (pAluno[i] != NULL){
      return posicao;
    }
    posicao++;
  }
  return -1;
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