#include <stdio.h>>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
 
char *p[MAX]; //matriz(vetor) de ponteiros para as strings dos eventos
int spos = 0; //store position, indice para armazenar
int rpos = 0; //retreive position, indice para recuperar

char *qretrieve();
void enter();
void qstore(char *q);
void review();
void delete();

int main(){
    char choice;
    int t; 

    for (t = 0; t < MAX; t++)
    {
        p[t] = '\0'; //iniciando a matriz com nulos, dizer que inicialmente não existem eventos nela
    }

    for(;;){
        clear();
        printf("\nI. Inserir evento\nL. Listar evento\nR. Remover evento\nS. Sair\n");
        printf("\nOpcao");
        scanf("%c%*c", &choice);
        choice = toupper(choice);

        switch (choice){
        case 'I':
            enter();
            break;
        case 'L':
            review();
            getchar();
            break;
        case 'R':
            delete();
            break;
        case 'S':
            exit(0);
            break;
        default:
            printf("\nOpcao invalida");
            getchar();
            printf("\nPressione Enter para voltar\n");
            getchar();
        }
    }

  return 0;  
}

void enter(){
    char s[256];
    char *p;

    do{
        printf("Insira o evento %d: ", spos+1);
        fgets(s, 256, stdin);
        s[strcspn(s,"\n")] = '\0';
        if(!(*s)) break;

        p = malloc(strlen(s)+1); //alocando memoria para a string
        if(!p){
            printf ("Sem memória.\n");
            getchar();
            return;
        }
        strcpy(p, s);

        if(*s) qstore(p);

    }while(*s);
}

void qstore(char *q){
    if(spos == MAX){ //"fila está cheia?" 
        printf("Lista cheia\n");
        getchar();
        return;
    }

    p[spos] = q; //endereço da string
    spos++;
}

void review(){
    int t;

    for(t = rpos; t < spos; t++){ //faz enquanto houver eventos a serem lidos
        printf("%d. %s\n", t+1, p[t]);
        printf("Endereco Ox%p\n", p[t]);
    }
    if(rpos==spos){
        printf("\n Sem eventos para exibir\n");
        printf("\nspos: %p\n", spos);
        printf("\nrpos: %p\n", rpos);
    }
}

void delete(){
    char *p;
    if((p  = qretrieve()) == NULL) return;
    printf("%s\n", p);
}

char *qretrieve(){
    if(rpos == spos){
        printf("Sem eventos para remover\n");
        return NULL;
    }
    rpos++;
    return p[rpos-1];
}

void clear(){
    #if defined(__linux__) || defined(__unix__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}