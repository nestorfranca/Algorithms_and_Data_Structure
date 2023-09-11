#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct frutas{
    char nome[10];
    float preco;
    struct frutas *proximo;
}ListaFrutas;

ListaFrutas *insere(ListaFrutas *fruta, char*nome, float valor){
    ListaFrutas*novafruta=(ListaFrutas*) malloc(sizeof(ListaFrutas));
    strcpy(novafruta->nome, nome);
    novafruta->preco = valor;
    novafruta->proximo = fruta;
    return novafruta;
}

void imprime(ListaFrutas* lista){
    ListaFrutas *P;
    for(P=lista; P!=NULL; P = P->proximo){
        printf("Nome: %s\tPreco: R$ %.2f\n",P->nome, P->preco);
    }
}

void libera(ListaFrutas *lista){
    free(lista);
}
