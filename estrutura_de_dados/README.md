
# Mecanismos de dados
### Programas: 
Combinação de algoritmos com estruturas de dados. Algoritmos sendo os passos para resolver o problema e estrutura de dados como um agrupamento de dados, dos diferentes tipos ou não

Quanto mais complexos os dados, quanto mais abstratos eles forem, mais difícil fica imaginar como eles são acessados.

E ai existem os mecanismos para acessar e armazenar esses dados, cada um com uma forma de ordenar os dados na hora de acessar ou buscar.

***
## Fila
É um mecanismo em que as unidades de informação são armazenadas e recuperadas na mesma ordem que chegaram. _As unidades de informacao entram na fila e saem na mesma ordem que chegaram_
**FIRS IN FIRST OUT (FIFO)**

Existe um índice(ou ponteiro) que verifica a proxima posição livre para armazenar e um indice( ou ponteiro) que verifica a proxima posicao a ser buscada e recuperada, e este vai seguindo o que armazena quando é pedido para fazer a leitura. _O ponteiro de leitura persegue o ponteiro de escrita_

E a informação que já foi acessada não pode ser mais recuperada. Os novos dados são sempre colocados no final da fila

Não é permitido acesso aleatório.

exemplos (uma fila de impressão de um impressora de documentos)
***
## Pilha
As unidades de informação são empilhadas uma em cima da outra, sendo que a ultima unidade que chegou é a primeira a sair. 
**LAST IN FIRST OUT (LIFO)**

Inserir dados na pilha é chamado de push e remover dados é chamado de pop, mas isso só pode ser feito com a ultima posição da pilha. Pushs constantes pode causar o overflow da lista e pops constantes podem causar o underflow da lista.

Outras operações da pilha podem ser:
* size = retorna o numero de elementos presente na pilha
* peek = retorna o elemento mais ao topo sem remove-lo

***
## Lista
Sequência finita e ordenada de n elementos {a1, a2, a3, ..., an}. É uma solução adequada para arrays (ver Um pouco sobre arrays). Diferente do array a lista aloca memória para cada elemento separadamente e apenas quando necessário. E o elementos não precisam ser armazenados contiguamente.

As unidades de informação são interligadas, cada bloco aponta para um outro. _Por um bloco você consegue acessar o próximo_

Uma lista pode ser implementada de duas formas:
* com alocação sequencial
    * a lista é processada usando array
* com alocação ligada

Os tipos de listas são:
* Lista encadeada simples;
    * cada elemento(nó) possue um pointeiro como link para o próximo nó, ou para o valor NULL se for o nó final
* Lista encadeada circular;
    * semelhante a lista encadeada simples mas nesse caso o ultimo nó tem um ponteiro que aponta de volta para o inicio da fila
* Lista duplamente encadeada;
    * cada nó possue dois ponteiros como link: um para o nó anterior e um para o próximo nó, ou NULL se for o nó final.
* Lista circular duplamente encadeada.
    * semelhante a lista duplamente encadeada: mas o ponteiro de 'anterior' do primeiro nó aponta para o final da fila e o ponteiro 'proximo' do ultimo nó aponta para o inicio da fila.

### Lista encadeada simples
Cada elementou (ou nó) contém dois campos: _data_ (contém um valor de qualquer tipo) e _next_ (contém um ponteiro para o próximo nó) 

O começo da fila encadeada é armazenada em um ponteiro chamado _head_ (cabeça) que aponta para o primeiro nó. No ultimo nó o campo next é setado com NULL, indicando o fim da fila. 

Adicionar um elemento no fim da lista possui a dificuldade de ter que percorrer a lista inteira até o fim (tail) para armazenar. Para solucinar isso pode-se adicionar mais um nó com um ponteiro, chamado _tail_ por exemplo(semelhante ao _head_), para apontar para o ultimo nó da fila. 

Um nó de uma lista encadeada simples pode ser feita da seguinta maneira

```
struct no{
    int data;
    struct no *next;
};
```
O segundo campo é um ponteiro que aponta para o mesmo tipo de estrutura em que ele está inserido, e é ele que possibilita a lista ser encadeada. Ou seja, a lista encadeada é um conjunto de dados ordenados e que são ligados por esse ponteiro. E o campo data pode conter não só inteiro como qualquer tipo de dado, e quantidade também

```
struct no{
    char nome[50];
    int idade;
    struct no *next;
};
```
E pode ficar mais difícil, por exemplo:
```
typedef struct{
    char codigo[8];
    char nome[26];
    float valor;
    int status;
}produto;

struct no{
    produto data;
    struct node *next;
};
```

***
## Arvore
As unidades de informação são distribuidas de forma hierarquica onde um nó liga a outro

***
### Um pouco de array
Array é tipo de dado estruturado mais comum para armazenar grandes quantidades de dados do mesmo tipo. É fácil de declarar, armazenar e acessar (por seus índices). Mas algumas desvantagens são:
* tem tamanho limitado. Usando alocação dinâmica você pode definir um tamanho ideal, sem a necessidade de predefinir o tamanho na hora da declaração, contudo, após a alocação, o array fica com tamanho limitado do mesmo jeito. Você pode redimensionar com realloc, mas vai dar um trabalho a mais
* se o número de elementos num array for menor que o seu tamanho, ainda existiram espaços não usados na memória que não estarão livres para outras partes do processo. 
* como o array é alocado sequencialmente na memória, e se for precisso determinar um tamanho grande demais para ele, pode ser que não haja espaço e o programa quebre.
* se o processo demanda mais do que o tamanho do array pode acontecer um overflow e o programa também pode querbrar