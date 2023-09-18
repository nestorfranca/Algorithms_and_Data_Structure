#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main(void){

    Pilha *pilha = pilha_cria();

    pilha_push(pilha, 7);
    pilha_push(pilha, 5);
    pilha_push(pilha, 3);
    pilha_push(pilha, 1);

    pilha_imprime(pilha);

    float valor = pilha_pop(pilha);

    printf("\nValor retirado do topo: %.2f\n\n", valor);

    pilha_imprime(pilha);

    return 0;
}
