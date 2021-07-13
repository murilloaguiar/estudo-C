#include <stdio.h>>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10

void clear(){
    #if defined(__linux__) || defined(__unix__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}


char p[MAX];
int spos = 0; //store position, indice para armazenar
int rpos = 0; //retreive position, indice para recuperar

char qretrieve();
void enter();
void qstore(char q);
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
        scanf("%c%*c", &choice);

        switch (choice){
        case 'I':
            enter();
            break;
        case 'L':
            review();
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
            break;
        }
    }

  return 0;  
}

//ler um evento
void enter(){
    char event; //caractere a ser armazenado 

    do{
        printf("Insira o evento [%d]: ", spos+1);
        scanf(" %c", &event);
        if (event == '0'){
            getchar();
            return;
        }else{
            qstore(event);
        }
        
    }while (event != '\0');
    
}

//armazena o evento
void qstore(char q){

    if (spos == MAX){
        printf("Lista cheia\n");
        return;
    }
    p[spos] = q;
    spos++;
}

void review(){
    int t;
    char temp;

    for (t = rpos; t < spos; t++){
        printf("\n[%d]: %c", t+1, p[t]);
    }
    
    if(rpos == spos){
        printf("\nSem eventos para exibir.\n");
        printf("\nspos: %p", spos);
        printf("\nrpos: %p", rpos);
    }

    scanf("%c", &temp);
    printf("\nPressione Enter para voltar\n");
    getchar();
}

void delete(){
    char event, temp;

    event = qretrieve(); //caractere lido da fila
    if(!event) return;
    printf("%c\n", event);

    scanf("%c", &temp);
    printf("\nPressione Enter para voltar\n");
    getchar();

}

char qretrieve(){

    if(rpos == spos){ //lista vazia
        printf("Sem eventos para remover\n");
        getchar();
        return '\0';
    }

    rpos++;
    return p[rpos-1];


}