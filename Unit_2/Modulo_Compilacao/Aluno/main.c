#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_ALUNO 5

int main(void){

    int index;
    char nome[100];
    float nota;
    FILE *arquivo;
    Aluno **aluno = (Aluno**) calloc(MAX_ALUNO,sizeof(Aluno*));
    if(aluno == NULL){ exit(1);}

    for(index = 0; index < MAX_ALUNO; index++){
        printf("\nNome: ");
        scanf(" %99[^\n]", nome);
        printf("Nota: ");
        scanf("%f", &nota);

        aluno[index] = aluno_cria(nome, nota);
    }

    aluno_ordena(MAX_ALUNO, aluno);

    for(index = 0; index < MAX_ALUNO; index++){
        aluno_imprime(aluno[index]);
    }

    aluno_salva(arquivo, MAX_ALUNO, aluno);

    for(index = 0; index < MAX_ALUNO; index++){
        aluno_libera(aluno[index]);
    }

    return 0;
}