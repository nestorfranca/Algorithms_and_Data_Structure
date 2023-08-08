#include <stdio.h>
#include <stdlib.h>

typedef struct notas{
    float nota1;
    float nota2;
    float nota3;
}Notas;

void Coleta_notas(Notas **notas, int N);
void escreve_notas(FILE *Arq,int N,Notas **notas);
Notas *new_aluno(void);

int main(void){

    int N;

    printf("Numero de alunos: \n");
    scanf("%d", &N);

    Notas **notas = (Notas**) calloc(N,sizeof(Notas*));
    FILE *Arq;

    Coleta_notas(notas, N);
    escreve_notas(Arq, N, notas);

    return 0;
}

void Coleta_notas(Notas **notas, int N){

    int index = 0;
    for(index; index < N; index++){
        notas[index] = new_aluno();
        
        printf("Digite a 1 do %d aluno: \n", index+1);
        scanf("%f", &notas[index]->nota1);
        printf("Digite a 2 do %d aluno: \n", index+1);
        scanf("%f", &notas[index]->nota2);
        printf("Digite a 3 do %d aluno: \n", index+1);
        scanf("%f", &notas[index]->nota3);
    }

}

Notas *new_aluno(void){
    Notas *nota = (Notas*) malloc(sizeof(Notas));
    if(nota == NULL){exit(1);}

    return nota;
}

void escreve_notas(FILE *Arq, int N, Notas **notas){

    Arq = fopen("Arquivo.txt", "wt");
    if(Arq == NULL){exit(1);}

    int index = 0;
    fprintf(Arq, "Notas dos alunos:\n");
    for(index; index < N; index++){
        fprintf(Arq, "Notas dos alunos %d:\n", index+1);
        fprintf(Arq, "Notas 1: %.2f\n", notas[index]->nota1);
        fprintf(Arq, "Notas 2: %.2f\n", notas[index]->nota2);
        fprintf(Arq, "Notas 3: %.2f\n\n", notas[index]->nota3);
    }

}
