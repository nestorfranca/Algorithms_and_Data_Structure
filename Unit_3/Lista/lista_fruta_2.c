#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct frutas{
    char nome[10];
    struct frutas *proximo;
}ListaFrutas;

ListaFrutas *insere(ListaFrutas *fruta, char*nome){
    ListaFrutas*novafruta=(ListaFrutas*) malloc(sizeof(ListaFrutas));
    strcpy(novafruta->nome, nome);
    novafruta->proximo = fruta;
    return novafruta;
}

int main(void){

    ListaFrutas *lista = NULL;
    
    lista = insere(lista, "maca");
    lista = insere(lista, "uva");
    lista = insere(lista, "abacate");

    ListaFrutas *P;
    for(P=lista; P!=NULL; P = P->proximo){
        printf("%s\n",P->nome);
    }

    free(lista);

    return 0;
}
