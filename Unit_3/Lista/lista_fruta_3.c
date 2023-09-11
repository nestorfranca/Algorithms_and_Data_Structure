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

int main(void){

    ListaFrutas *lista = NULL;
    
    lista = insere(lista, "maca", 2.3);
    lista = insere(lista, "uva", 4.5);
    lista = insere(lista, "abacate", 6);

    imprime(lista);

    free(lista);

    return 0;
}
