#include <stdio.h>
#include <stdlib.h>

typedef struct disciplina{
    char nome[30];
    float nota;
}Disciplina;

typedef struct aluno{
    char nome[20];
    int matricula;
    Disciplina * disciplina;
}ALUNO;

ALUNO * cadastro_aluno(void);
void imprime(ALUNO * aluno);

int main(void){

    ALUNO * aluno = cadastro_aluno();

    imprime (aluno);

    free(aluno->disciplina);
    free(aluno);

    return 0;
}

ALUNO * cadastro_aluno(void){

    ALUNO * aluno = (ALUNO *) malloc(sizeof(ALUNO));
        if(aluno == NULL){
            printf("Falha na alocacao de memoria!");
            exit(1);
        }
        aluno->disciplina = (Disciplina *) malloc(2*sizeof(Disciplina));
        if(aluno->disciplina == NULL){
            printf("Falha na alocacao de memoria!");
            exit(1);
        }

        printf("Digite o nome:\n");
        scanf(" %[^\n]", (*aluno).nome);
        printf("Digite a matricula:\n");
        scanf("%d", &(*aluno).matricula);
        printf("Digite o nome da dicplina 1:\n");
        scanf(" %[^\n]", aluno->disciplina[0].nome);
        printf("Digite a nota da disciplina 1:\n");
        scanf("%f", &aluno->disciplina[0].nota); 
        printf("Digite o nome da dicplina 2:\n");
        scanf(" %[^\n]", aluno->disciplina[1].nome);
        printf("Digite a nota da disciplina 2:\n");
        scanf("%f", &aluno->disciplina[1].nota);    
        printf("\n");

    return aluno;
}

void imprime(ALUNO * aluno){

   printf("Dados:\nNome: %s\nMatricula: %d\nDisciplina: %s\nNota: %.2f", aluno->nome, aluno->matricula, aluno->disciplina[0].nome, aluno->disciplina[0].nota);
   printf("\nDisciplina: %s\nNota: %.2f", aluno->disciplina[1].nome, aluno->disciplina[1].nota); 

    return 0;
}