#include <stdio.h>
#include <stdlib.h>

//Declarando uma strcut para armazenar os dados do aluno
typedef struct aluno{
    char nome[20];
    int matricula;
}ALUNO;

int main(void){

    ALUNO * aluno = (ALUNO *) malloc(sizeof(ALUNO));    //Alocando memoria para o vetor aluno
    if(aluno == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    }

    //Solicitando so dados
    printf("Digite o nome:\n");
    scanf(" %[^\n]", (*aluno).nome);
    printf("Digite a matricula:\n");
    scanf("%d", &(*aluno).matricula);

    free(aluno);    //Limpando memoria
    
    return 0;
}