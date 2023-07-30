#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[20];
    int matricula;
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

    free(aluno);
    
    return 0;
}