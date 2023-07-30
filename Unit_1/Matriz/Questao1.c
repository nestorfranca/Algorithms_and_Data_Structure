#include <stdio.h>
#include <stdlib.h>

int main(void){

    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    int * vetor = (int*) malloc(tamanho*sizeof(int));
    if(vetor == NULL){
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    } 
    else{
        printf("Alocacao realizada com sucesso!\n");
    }

    int contador;
    printf("Digite os valores do vetor:\n");
    for(contador=0; contador<tamanho; contador++){
        scanf("%d", &vetor[contador]);        
    }

    for(contador=tamanho-1; contador >= 0; contador--){
        printf("%d\n", vetor[contador]);
    }
    free(vetor);

    return 0;
}