#include <stdio.h>
#include <stdlib.h>

int main(void){

    float num_ques, nota, porcent = 0.0, aprovados=0.0;
    int alunos=10, contador; // lembrar de trocar o valor
    char *gabarito, **respostas;

    printf("Quantas questao tem a prova?\n");
    scanf("%f", &num_ques); 

    float peso = 10.0/num_ques;

    //Declarando o vetor para armazenar as respostas certas
    printf("\n");
    gabarito = (char*) malloc(num_ques * sizeof(char));
    if(gabarito == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    }

    //Recebendo o gabarito da prova 
    for(contador=0; contador < num_ques; contador++){
        printf("Qual a resposta da %dª questao:\n", contador+1);
        scanf("%s", &gabarito[contador]);
    }
    printf("\n");

    //Declarando uma matriz para receber as respostas de cada alunos
    respostas = (char**) malloc(alunos * num_ques * sizeof(char*)); 
    if(respostas == NULL){
        printf("Falha na alocacao de memoria!\n");
        exit(1);
    }
    for(contador=0; contador < alunos; contador++){
        respostas[contador] = (char*) malloc(num_ques * sizeof(char));
    }

    //Recebendo as respostas dos alunos
    int i, j;
    for(i=0; i < alunos; i++){
        for(j=0; j < num_ques; j++){
            printf("Qual foi a resposta  do %dª aluno na %dª questao:\n", i+1, j+1);
            scanf("%s", &respostas[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    //imprimindo a nota de cada aluno
    for(i=0; i < alunos; i++){
        nota = 0.0;
        for(j=0; j < num_ques; j++){
            if(respostas[i][j] == gabarito[j]){
                nota += peso; 
            }     
        }
        if(nota >= 6.00){
             aprovados++;
        }
        printf("A nota do %dª aluno foi: %.2f\n", i+1 , nota);
    }
    
    porcent = (aprovados/10)*100;

    printf("A porcetagem de aprovados foi: %.2f\n", porcent);

    //Limpando a memoria 
    for(contador=0; contador < alunos; contador++){
        free(respostas[contador]);
    }
    free(respostas);
    free(gabarito);

    return 0; 
}