#include <stdio.h>
#include <stdlib.h>

int main(void){

    int tamanho;
    printf("Digite o tamanho do vetor: ");  //Solicitando o tamanho do vetor do pro usuario
    scanf("%d", &tamanho);
    
    int * vetor = (int*) malloc(tamanho*sizeof(int));   //Alocando memoria pro vetor
    if(vetor == NULL){
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    } 
    else{
        printf("Alocacao realizada com sucesso!\n");
    }

    int contador;
    //Solicitando valor para o vetor
    printf("Digite os valores do vetor:\n");
    for(contador=0; contador<tamanho; contador++){
        scanf("%d", &vetor[contador]);        
    }

    //Imprimindo os valores na ordem inversa
    for(contador=tamanho-1; contador >= 0; contador--){
        printf("%d\n", vetor[contador]);
    }
    free(vetor);    //Limpando memoria 

    return 0;
}