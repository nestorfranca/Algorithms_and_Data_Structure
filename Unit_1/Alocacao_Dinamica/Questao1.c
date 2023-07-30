#include <stdio.h>
#include <stdlib.h>

int main(void){

    char *vetor_sexo, *vetor_feedback;
    float porcent_F, porcent_M;
    int pessoas;
    float Mulher, Homem;

    pessoas =0;
    Mulher = Homem = 0.0;    
    printf("Quantas pessoas realizaram a entrevista:\n");
    scanf("%d", &pessoas);

    //Alocando memoria para o vetor que armazena o sexo 
    vetor_sexo = (char*) malloc(pessoas *sizeof(char));
    if (vetor_sexo == NULL){
        printf("Erro na alocacao de memoria!");
        exit(1);
    }
    //Alocando memoria para o vetor que armazena o feedback 
    vetor_feedback = (char*) malloc(pessoas *sizeof(char));
    if (vetor_feedback == NULL){
        printf("Erro na alocacao de memoria!");
        exit(1);
    }

    int contador;
    //Laço "for" para solicitar o sexo e o feedback
    for(contador=0; contador < pessoas; contador++){
        printf("Digite 'F' se for mulher ou 'M' se for homem:\n");
        scanf("%s", &vetor_sexo[contador]);
        if(vetor_sexo[contador] == 'F'){
            Mulher++;
        }else{
            Homem++;
        }
        printf("Digite 'S' se tiver gostado do produto ou 'N' se nao tiver gostado do produto:\n");
        scanf("%s", &vetor_feedback[contador]);
    }
   
    porcent_F = porcent_M = 0.0;
    for(contador=0; contador < pessoas; contador++){
        if((vetor_sexo[contador] == 'F') && (vetor_feedback[contador] == 'S')){
            porcent_F++;
        }
        if ((vetor_sexo[contador] == 'M') && (vetor_feedback[contador] == 'N')){
            porcent_M++;
        }
    }
   
    //Calculando a porcentagem das mulheres que gostaram e dos homens que nao gostaram
    porcent_F=(porcent_F/Mulher)*100;
    porcent_M=(porcent_M/Homem)*100;

    printf("%.2f das mulheres gostaram do produto\n", porcent_F);
    printf("%.2f dos homens nao gostaram do produto", porcent_M);

    //Limpando a memoria
    free(vetor_sexo);
    free(vetor_feedback);

    return 0;
}