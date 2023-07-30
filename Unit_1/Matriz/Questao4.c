#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
     
    int pessoas, caracter, contador;

    printf("Quantas pessoas deseja armazenar:\n");
    scanf("%d", &pessoas);

    //Declaracao do vetor que armazenara as idades 
    int * vetor_idade = (int*) malloc(pessoas * sizeof(int));
    if(vetor_idade == NULL){
        printf("Falha na alocao de memoria!");
        exit(1);
    }

    //Declaracao da matriz que armazenara os nomes dos usuarios 
    char ** matriz_nomes = (char**) malloc(pessoas * sizeof(char*));    
    if(matriz_nomes == NULL){
        printf("Falha na alocao de memoria!");
        exit(1);
    }
    for(contador=0; contador < pessoas; contador++){
        matriz_nomes[contador] = (char*) malloc(100 * sizeof(char));
    }       

    //Recebendo os nomes e as idades dos usuarios
    for(contador=0; contador < pessoas; contador++){
        printf("Digite o nome completo do usuario:\n");
        scanf("%s", &matriz_nomes[contador][0]);
    
        //Realocando o tamanho da memoria
        caracter = 1 + strlen(matriz_nomes[contador]);
        matriz_nomes[contador] = (char*) realloc(matriz_nomes[contador], caracter * sizeof(char));
        
        printf("Digite a idade do usuario:\n");
        scanf("%d", &vetor_idade[contador]);
    }

    for(contador=0; contador < pessoas; contador++){
        printf("Nome: %s, idade: %d.\n", matriz_nomes[contador], vetor_idade[contador]);
    }

    for(contador=0; contador < pessoas; contador++){
        free(matriz_nomes[contador]);
    }
    free(matriz_nomes);
    free(vetor_idade);

    return 0;
}