#include <stdio.h>
#include <stdlib.h>

int main(void){

    int ordem, linhas, colunas;
    int linha, coluna;

    printf("Informe a ordem da matriz:\n"); //Solicitando qual a ordem que a matriz vai ter 
    scanf("%d", &ordem);
    linhas = colunas = ordem;

    int ** matriz = (int**) malloc(linhas * sizeof(int*));   //Declarando o vetor de vetores
    if(matriz == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    } 
    for(linha=0; linha < linhas; linha++){
        matriz[linha] = (int*) malloc(colunas * sizeof(int));   //Declarando os vetores
    }
    
    //Armazenando valores aleatorios entre 1 e 100 na matriz
    for(linha=0; linha < linhas; linha++){
        for(coluna=0; coluna < colunas; coluna++){
            matriz[linha][coluna] = 1 + rand()%100;
        }
    }

    printf("\n");
    //Imprimindo a matriz
    for(linha=0; linha < linhas; linha++){
        for(coluna=0; coluna < colunas; coluna++){
           printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }

    //Limpando memoria
    for(linha=0; linha < linhas; linha++){
        free(matriz[linha]);
    }
    free(matriz);

    return 0;
}