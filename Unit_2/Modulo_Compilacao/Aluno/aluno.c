#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char nome[100];
    float nota;
};

Aluno *aluno_cria(char *nome, float nota){

    Aluno *aluno_ = (Aluno*) calloc(1,sizeof(Aluno));
    if(aluno_ == NULL) exit(1);

    strcpy(aluno_->nome, nome);
    aluno_->nota = nota;

    return aluno_;
}

void aluno_libera(Aluno *a){
    free(a);
}

void aluno_imprime(Aluno *a){
    printf("\nNome: %s, Nota: %.f", a->nome, a->nota);
}

void aluno_ordena(int n, Aluno **v){

    int i, j, armazena;
    Aluno *aluno;

    for(i = 0; i < n; i++){

        aluno = v[i];

        armazena = 1;
        for(j = i + 1; j < n; j++){
            if(strcmp(strupr(v[armazena]->nome), strupr(v[j]->nome)) == 1){
                armazena = j;
            }
        }

        if(armazena != i) {
            v[i] = v[armazena];
            v[armazena] = aluno;
        }       

    }
}

void aluno_salva(FILE *fl, int n, Aluno **v){

    fl = fopen("arquivo.txt", "wt");
    if(fl == NULL){
        printf("Nao foi possivel abrir o arquivo!");
        exit(1);
    }

    int i;
    for(i = 0; i < n; i++){
        fprintf(fl, "%d - Nome: %s\tNota: %.2f\n", i+1, v[i]->nome, v[i]->nota);
    }

    fclose(fl);
}