/*1. Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e genero. O
genero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
deve ler os dados de uma pessoa e imprimir os dados da pessoa.*/

#include <stdio.h>
#include <stdlib.h>

typedef enum genero{
    MASCULINO, FEMININO
}Genero;

typedef struct pessoa{
    char nome[81];
    int idade;
    Genero genero;
}Pessoa;

int main(void){

    Pessoa* pessoa = (Pessoa*) malloc(sizeof(Pessoa));
    if(pessoa == NULL){exit(1);}
    

    printf("Digite o nome: \n");
    scanf(" %80[^\n]", pessoa->nome);
    printf("Digite a idade: \n");
    scanf("%d", &pessoa->idade);
    printf("0 - MAsculino \n1 - Feminino\nEscolha uma opcao: \n");
    scanf("%d", &pessoa->genero);

    if(pessoa->genero == MASCULINO){
        printf("Dados:\nNome: %s\nIdade: %d\nGenero: Masculino", pessoa->nome, pessoa->idade);
    }else if(pessoa->genero == FEMININO){
        printf("Dados:\nNome: %s\nIdade: %d\nGenero: Feminino", pessoa->nome, pessoa->idade);
    }else{
        printf("Opcao invalida para genero!");
    }

    free(pessoa);

    return 0;
}