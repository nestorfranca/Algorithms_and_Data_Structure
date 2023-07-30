#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina{  //Declarando uma strcut para armazenar os dados das disciplinas
    char nome[30];
    float nota;
}Disciplina;

typedef struct aluno{   //Declarando uma strcut para armazenar os dados do aluno   
    char nome[20];
    int matricula;
    Disciplina disciplina;
}ALUNO;

int main(void){

    ALUNO * aluno = (ALUNO *) malloc(sizeof(ALUNO));    //Alocando memoria para o vetor aluno
    if(aluno == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    }

    //Solicitando e armazenando os dados
    printf("Digite o nome:\n");
    scanf(" %[^\n]", (*aluno).nome);
    printf("Digite a matricula:\n");
    scanf("%d", &(*aluno).matricula);
    printf("Digite o nome da discplina:\n");
    scanf(" %[^\n]", aluno->disciplina.nome);
    printf("Digite a nota:\n");
    scanf("%f", &aluno->disciplina.nota);
    printf("\n");
    //Imprimindo os dados
    printf("Dados:\nNome: %s\nMatricula: %d\nDisciplina: %s\nNota: %.2f", aluno->nome, aluno->matricula, aluno->disciplina.nome, aluno->disciplina.nota);

    //Limpando a memoria
    free(aluno);

    return 0;
}