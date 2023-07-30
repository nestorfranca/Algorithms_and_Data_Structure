#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina{
    char nome[30];
    float nota;
}Disciplina;

typedef struct aluno{
    char nome[20];
    int matricula;
    Disciplina s;
}ALUNO;

int main(void){

    ALUNO * aluno = (ALUNO *) malloc(sizeof(ALUNO));
    if(aluno == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    }

    printf("Digite o nome:\n");
    scanf(" %[^\n]", (*aluno).nome);
    printf("Digite a matricula:\n");
    scanf("%d", &(*aluno).matricula);
    printf("Digite o nome da discplina:\n");
    scanf(" %[^\n]", aluno->disciplina.nome);
    printf("Digite a nota:\n");
    scanf("%f", &aluno->disciplina.nota);
    printf("\n");
    printf("Dados:\nNome: %s\nMatricula: %d\nDisciplina: %s\nNota: %.2f", aluno->nome, aluno->matricula, aluno->disciplina.nome, aluno->disciplina.nota);

    free(aluno);

    return 0;
}