#include <stdio.h>
#include <stdlib.h>

int main(void){

    int linhas, colunas;
    printf("Digite a quantidade de linhas e colunas: ");    //Solicitando a quantidade de linhas e colunas 
    scanf("%d %d", &linhas, &colunas );

    int ** matriz = (int**) malloc(linhas * sizeof(int*));  //Declarando o vetor de vetores
    if(matriz == NULL){
        printf("Falha na alocacao de memoria!\n");
        exit(1);
    }
    else{
        printf("Alocacao feita com sucesso!\n");
    }
    int contador;
    for(contador=0; contador<linhas; contador++){
        matriz[contador] = (int*) malloc(colunas * sizeof(int));    //Declarando vetores 
    }

    int i, j;
    printf("Digite os elementos da matriz:\n"); //Solicitando os valores
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
   
    printf("\n");
    //Imprimindo os valos
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    //Imprimeindo os valores na ordem inversa
    for(i=linhas-1; i>=0; i--){
        for(j=colunas-1; j>=0; j--){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //Limpando memoria
    for(i=0; i<linhas; i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}