#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../pilha-lista/pilha.c"
#include "calc.h"

struct calc{
    char f[21];
    Pilha *p;
};

Calc *calc_cria(char *formato){
    Calc *c = (Calc*) malloc(sizeof(Calc));
    strcpy(c->f, formato);
    c->p = pilha_cria();
    return c;
}

void calc_operando(Calc *c, float v){
    pilha_push(c->p, v);
    printf(c->f, v);
}

void calc_operador(Calc *c, char op){
    float v1, v2, v;

    if(pilha_vazia(c->p))
        v2 = 0.0;
    else
        v2 = pilha_pop(c->p);
    if(pilha_vazia(c->p))
        v1 = 0.0;
    else
        v1 = pilha_pop(c->p);

    switch (op)
    {
    case '+':
        v=v1+2;
        break;
    case '-':
        v=v1-v2;
        break;
    case '*':
        v=v1*v2;
        break;
    case '/':
        v=v1/v2;
        break;
    }

    pilha_push(c->p,v);
    printf(c->f,v);
}

void calc_libera(Calc *c){
    pilha_libera(c->p);
    free(c);
}
