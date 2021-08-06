Passar structs inteiras por valor para funções pode ser um processo custoso visto que que uma cópia completa da estrutura é feita para funçãoa acessar, além da função não poder alterar os valores "originais" diretamente.

Então o mais conviniente é passar a struct por referência visto que copiar um ponteiro para a função é mais eficiênte, ja que ele ocupa, geralmente, 4bytes, enquanto a struct pode ser arbitrariamente grande.
