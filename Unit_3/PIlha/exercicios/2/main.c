#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

float topo (Pilha* p);
void concatena_pilhas(Pilha* p1, Pilha* p2);

int main(void){
    int i;

    Pilha *pilha1 = pilha_cria();
    Pilha *pilha2 = pilha_cria();

    for(i = 0; i < 3; i++){
    pilha_push(pilha1, i+1);
    }

    pilha_imprime(pilha1);

    for(i = 0; i < 4; i++){
    pilha_push(pilha2, i+1);
    }

    pilha_imprime(pilha2);

    printf("\nValor do topo: %.2f\n\n", topo(pilha1));

    concatena_pilhas(pilha1, pilha2);

    pilha_imprime(pilha1);

    pilha_libera(pilha1);
    pilha_libera(pilha2);

    return 0;
}


float topo (Pilha* p){
    float valor_auxiliar;

    valor_auxiliar = pilha_pop(p);
    pilha_push(p, valor_auxiliar);
    return valor_auxiliar;
}

void concatena_pilhas(Pilha* p1, Pilha* p2){
    int i;
    while(!(pilha_vazia(p2))){
        pilha_push(p1, pilha_pop(p2));
    }
}
