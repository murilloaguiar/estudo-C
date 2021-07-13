### Programas: 
Combinação de algoritmos com estruturas de dados. Algoritmos sendo os passos para resolver o problema e estrutura de dados como um agrupamento de dados, dos diferentes tipos ou não

Quanto mais complexos os dados, quanto mais abstratos eles forem, mais difícil fica imaginar como eles são acessados.

## Mecanismos de dados
E ai existem os mecanismos para acessar e armazenar esses dados, cada um com uma forma de ordenar os dados na hora de acessar ou buscar.

### Fila
É um mecanismo em que as unidades de informação são armazenadas e recuperadas na mesma ordem que chegaram. _As unidades de informacao entram na fila e saem na mesma ordem que chegaram_
**FIRS IN FIRST OUT (FIFO)**

Existe um índice(ou ponteiro) que verifica a proxima posição livre para armazenar e um indice( ou ponteiro) que verifica a proxima posicao a ser buscada e recuperada, e este vai seguindo o que armazena quando é pedido para fazer a leitura. _O ponteiro de leitura persegue o ponteiro de escrita_

E a informação que já foi acessada não pode ser mais recuperada, os ponteiros não voltam para la(exceto em filar circular). Os novos dados são sempre colocados no final da fila

Não é permitido acesso aleatório.

exemplos (uma fila de impressão de um impressora de documentos)
### Pilha
As unidades de informação são empilhadas uma em cima da outra, sendo que a primeira unidade que chegou é a ultima a sair. _Os dados vão sendo empilhados_
### Lista
As unidades de informação são interligadas, cada bloco aponta para um outro. _Por um bloco você consegue acessar o próximo_
### Arvore
As unidades de informação são distribuidas de forma hierarquica onde um nó liga a outro

