#include <stdio.h>
#include <stdlib.h>

typedef union ia{      //Declarando uma unum para os indices de rendimento academico 
    float IG, IRA, IRT;
}IA;

typedef struct aluno{     //Declarando uma struct para armazenar os dados dos alunos 
    char nome[20];
    int mat;
    char curso[20];
    IA indice;
}Aluno; 

int main(void){

    Aluno * aluno = (Aluno*) malloc(sizeof(Aluno));     //Alocando memoria para o vetor aluno
    if(aluno == NULL){exit(1);}
    int opcao;

    //Solicitando os dados do aluno
    printf("Digite o nome: ");
    scanf(" %[^\n]", aluno->nome);
    printf("Digite o mat: ");
    scanf("%d", &aluno->mat);
    printf("Digite o curso: ");
    scanf(" %[^\n]", aluno->curso);
    printf("1 - IG\n2 - IRA\n3 - IRT\n");
    printf("Escola uma opcao: ");
    scanf("%d", &opcao);

    //"switch" para o usuario escolher que das opcoes ele escolhera
    switch (opcao)
    {
    case 1:
        printf("Informe o IG: ");
        scanf("%f", &aluno->indice.IG);
        break;
    case 2:
        printf("Informe o IRA: ");
        scanf("%f", &aluno->indice.IRA);
        break;
    case 3:
        printf("Informe o IRT: ");
        scanf("%f", &aluno->indice.IRT);
        break;    
    }

    //Imprimindo os dados digitados
    printf("Aluno:\nNome: %s \nMatricula: %d \nCurso: %s \nIndice academico: %.2f", aluno->nome, aluno->mat, aluno->curso, aluno->indice.IG);

    return 0;
}