#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main(void){

    int i;
    Pilha *pilha = pilha_cria();

    for(i = 0; i < 100; i++){
    pilha_push(pilha, i+1);
    }

    pilha_imprime(pilha);

    float valor = pilha_pop(pilha);

    printf("\nValor retirado do topo: %.2f\n\n", valor);

    pilha_imprime(pilha);

    pilha_libera(pilha);

    return 0;

}
