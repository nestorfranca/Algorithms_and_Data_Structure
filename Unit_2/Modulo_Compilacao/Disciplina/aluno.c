#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"
#include "aluno.h"

#define MAX_DISCIPLINA 10

struct aluno{
    char nome[100];
    int matricula;
    Disciplina *disciplina[MAX_DISCIPLINA];
    int num_disciplina;
};

Aluno *cria_aluno(char nome[], int matricula){
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    if(aluno = NULL){
        printf("Erro na alocacao!\n");
        exit(1);
    }
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->num_disciplina = 0;
    return aluno;
}

void matricula_displina(Aluno *aluno, Disciplina *disciplina){
    int codigo;
    if(aluno->num_disciplina <= MAX_DISCIPLINA){
        printf("Digite o codigo da turma: \n");
        scanf("%d", &codigo);
        
        aluno->disciplina[aluno->num_disciplina] = cria_disciplina  (aluno->nome, codigo);
        aluno->num_disciplina++;
    }else{
        printf("Maximo de disciplinas alcancado!\n");
    }
}

void exclui_aluno(Aluno *aluno){
    free(aluno);
}
