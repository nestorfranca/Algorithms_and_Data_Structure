/*2. Escreva um programa que implementa uma struct Produto com os campos nome, pre¸co e tipo. O tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto.*/

#include <stdio.h>
#include <stdlib.h>

typedef union tipo{ //Declarando uma union para o tipo do produto
    char ALIMENTO[20], BEBIDA[20], ELETRONICO[20];
}Tipo;

typedef struct produto{     //Declarando uma struct para armazenar os produtos
    char nome[80];
    float preco;
    Tipo tipo;
}Produto;

int main(void){

    Produto* produto = (Produto*) malloc(sizeof(Produto));     //Alocando memoria para o vetor produto
    if(produto == NULL){exit(1);}

    //Solicitando os dados dos produtos
    printf("Digite o nome: \n");
    scanf(" %79[^\n]", produto->nome);
    printf("Digite o preco do produto: \n");
    scanf("%f", &produto->preco);
    printf("1 - Alimento \n2 - Bebida\n3 - Eletronico\nDigite o tipo do produto: \n");
    scanf(" %19[^\n]", produto->tipo.BEBIDA);

    //Imprimindo os dados 
    printf("Dados do produto:\nNome: %s\nPreco: R$%.2f\nTipo: %s", produto->nome, produto->preco, produto->tipo.ALIMENTO);

    free(produto);  //Limpando memoria

    return 0;
}