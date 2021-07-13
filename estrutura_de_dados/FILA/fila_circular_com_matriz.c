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
        printf("\nOpcao");
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
            printf("\nPressione Enter para voltar\n");
            getchar();
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

    /*fila esta cheia em dois momentos:
        indice de recuperacao no inicio e de armazenamento no fim
        ou se spos(armazenamento) tem um a menos que rpos(recuperacao)*/

    if (spos+1 == rpos || (spos+1 == MAX && !rpos)){
        printf("Lista cheia\n");
        return;
    }
    p[spos] = q;
    spos++;
    if(spos == MAX) spos = 0;
}

void review(){
    int t;

    printf("\nspos: %p", spos);
    printf("\nrpos: %p\n", rpos);

    if(spos>rpos){
        printf("\n1 - spos maior que rpos");
        for (t = rpos; t < spos; t++){
            printf("\n[%d]: %c", t+1, p[t]);
        }
    }else if(rpos == spos){
        printf("\n2 - spos igual rpos\n");
        printf("\nSem eventos para exibir.\n");
    }else { //rpos > spos. rpos já deu uma volta
        for(t=rpos; t<MAX; t++){ //mostra de onde rpos está até o final da fila
            printf("\n[%d]: %c", t+1, p[t]);
        }
        for(t=0; t<=spos-1; t++){ //mostra de o inicio da fila até encontrar o spos
            printf("\n[%d]: %c", t+1, p[t]);
        }
    }
    
    getchar();
    printf("\nPressione Enter para voltar\n");
    getchar();
}

void delete(){
    char event;

    event = qretrieve(); //caractere lido da fila
    if(!event) return;
    printf("%c\n", event);

    getchar();
    printf("\nPressione Enter para voltar\n");
    getchar();

}

char qretrieve(){

    if(rpos == MAX) rpos = 0; //leitura no fim? volta para o inicio
    if(rpos == spos){ //lista vazia
        printf("Sem eventos para remover\n");
        getchar();
        return '\0';
    }

    rpos++;
    return p[rpos-1];


}