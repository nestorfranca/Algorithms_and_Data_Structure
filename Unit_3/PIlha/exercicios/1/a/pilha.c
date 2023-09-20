#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

static int N = 50;

struct pilha{
    int n;
    float *info;
};

Pilha *pilha_cria(void){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->info = (float*)malloc(N*sizeof(float));
    p->n = 0;
    return p;
}

void realoca_pilha(Pilha *p){
    p->info = (float*) realloc(p->info, 2*(p->n*sizeof(float)));
}

void pilha_push(Pilha *p, float v){
    if(p->n == N){ /*Capacidade esgotada */
        realoca_pilha(p);
        N = N*2;
    }
    /* insere elemento na próxima posição livre */
    p->info[p->n] = v;
    p->n++;
}

int pilha_vazia(Pilha *p){
    return (p->n == 0);
}

float pilha_pop(Pilha *p){
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1); /* abprta programa */
    }
    /* retira elemento do topo */
    v = p->info[p->n-1];
    p->n--;
    return v;
}

void pilha_libera(Pilha *p){
    free(p->info);
    free(p);
}

void pilha_imprime(Pilha *p){
    int i;
    for(i = (p->n-1); i >= 0; i--){
        printf("%.2f\n", p->info[i]);
    }
}
