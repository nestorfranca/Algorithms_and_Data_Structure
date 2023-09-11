#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct frutas{
    char nome[10];
    struct frutas *proximo;
}ListaFrutas;

int main(void){

    ListaFrutas * fruta1 = malloc(sizeof(ListaFrutas));
    ListaFrutas * fruta2 = malloc(sizeof(ListaFrutas));
    ListaFrutas * fruta3 = malloc(sizeof(ListaFrutas));
    
    strcpy(fruta1->nome, "maca");
    strcpy(fruta2->nome, "abacate");
    strcpy(fruta3->nome, "uva");

    fruta1->proximo = fruta2;
    fruta2->proximo = fruta3;
    fruta3->proximo = NULL;

    ListaFrutas *P;
    for(P=fruta1; P!=NULL; P = P->proximo){
        printf("%s\n",P->nome);
    }

    return 0;
}
