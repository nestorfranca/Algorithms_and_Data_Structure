#include <stdio.h>
#include <stdlib.h>

/* TAD: pilha de valores reais */

typedef struct pilha Pilha;


/* Cria uma pulha e alica uma memoria inicial para a ela*/
Pilha *pilha_cria(void);

/* Insere um valor na pilha*/
void pilha_push(Pilha *p, float v);

/* Retira um valor da pilha*/
float pilha_pop(Pilha *p);

int pilha_vazia(Pilha *p);

void pilha_libera(Pilha *p);

void realoca_pilha(Pilha *p);
