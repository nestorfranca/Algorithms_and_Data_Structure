#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fruta.h"

int main(void){

    ListaFrutas *lista = NULL;
    
    lista = insere(lista, "maca", 2.3);
    lista = insere(lista, "uva", 4.5);
    lista = insere(lista, "abacate", 6);

    imprime(lista);

    libera(lista);

    return 0;
}
