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

    printf("\n\nValor retirado: %.2f\n\n", pilha_pop(pilha));
    printf("\n\nValor retirado: %.2f\n\n", pilha_pop(pilha));

    pilha_imprime(pilha);

    pilha_libera(pilha);

    return 0;
}
