#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

#define MAX_MATRIZ 10

int main(void){

    Matriz **matriz = (Matriz**) calloc(MAX_MATRIZ,sizeof(Matriz*));
    if(matriz == NULL) exit(1);
    int colunas, linhas, coluna, linha;
    float num;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);
    matriz[0] = mat_cria(linhas, colunas);

    printf("DIgite o numero da linha que deseja atribuir: ");
    scanf("%d", &linha);
    printf("Digite o numero da coluna que deseja atribuir: ");
    scanf("%d", &coluna);
    printf("Qual numero deseja atribuir: ");
    scanf("%f", &num);
    mat_atribui(matriz[0], linha, coluna, num);

    printf("\nDIgite o numero da linha que deseja acessar: ");
    scanf("%d", &linha);
    printf("Digite o numero da coluna que deseja acessar: ");
    scanf("%d", &coluna);
    num = mat_acessa(matriz[0], linha, coluna);
    printf("Numero acessado: %.2f", num);

    printf("\n\nNumero de linhas: %d", mat_linhas(matriz[0]));
    printf("\nNumero de colunas: %d\n", mat_colunas(matriz[0]));

    mat_libera(matriz[0]);

    return 0;
}