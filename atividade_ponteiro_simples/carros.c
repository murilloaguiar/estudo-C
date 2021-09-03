#include <stdio.h>
#define MAX 5

typedef struct{
    int mes, ano, dia;
}Data;


typedef struct{
    int codigo;
    char nome_carro[30];
    int lote;
    Data data_fabricacao;
}Carro;

int cadastrarCarros(Carro *pCarro){

    for (int i = 0; i < MAX; i++){
        printf("\nDigite o codigo do carro: ");
        scanf("%d", &pCarro->codigo);

        printf("\nDigite o nome do carro: ");
        setbuf(stdin, NULL);
        fgets(pCarro->nome_carro, 30, stdin);

        printf("\nDigite o lote do carro: ");
        scanf("%d", &pCarro->lote);

        printf("\nDigite o dia de fabricao do carro: ");
        scanf("%d", &pCarro->data_fabricacao.dia);

        printf("\nDigite o mes de fabricao do carro: ");
        scanf("%d", &pCarro->data_fabricacao.mes);

        printf("\nDigite o ano de fabricao do carro: ");
        scanf("%d", &pCarro->data_fabricacao.ano);

        pCarro++;
    }
    
    return 0;
    

}

int mostrarCarro(Carro *pCarro){
    Carro *pCarro3;

    pCarro3 = &pCarro[2];

    printf("\ndata: %d\n",pCarro3->data_fabricacao.mes);
    printf("\ndata: %d\n",pCarro3->codigo);
    
    return 0;
}

int main(){
    Carro carros[MAX];

    cadastrarCarros(carros);
    
    mostrarCarro(carros);


    return 0;
}