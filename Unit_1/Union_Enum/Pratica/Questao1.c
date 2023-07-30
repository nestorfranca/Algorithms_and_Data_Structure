/*1. Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e genero. O
genero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
deve ler os dados de uma pessoa e imprimir os dados da pessoa.*/

#include <stdio.h>
#include <stdlib.h>

typedef enum genero{    //Enum para os valores de MASCULINO E FEMININO
    MASCULINO, FEMININO
}Genero;

//Declarando uma struct para armazenar os dados de uma pessoa
typedef struct pessoa{
    char nome[81];
    int idade;
    Genero genero;
}Pessoa;

int main(void){

    Pessoa* pessoa = (Pessoa*) malloc(sizeof(Pessoa));  //Alocando memoria para o vetor pessoa
    if(pessoa == NULL){exit(1);}
    
    //Solicitando os dados
    printf("Digite o nome: \n");
    scanf(" %80[^\n]", pessoa->nome);
    printf("Digite a idade: \n");
    scanf("%d", &pessoa->idade);
    printf("0 - MAsculino \n1 - Feminino\nEscolha uma opcao: \n");
    scanf("%d", &pessoa->genero);

    //Caso o usuario tenha digitado "0", sera imprimido "Masculino" na tela
    //Caso o usuario tenha digitado "1", sera imprimido "Feminino" na tela
    //Caso o usuario tenha digitado "Qualquer_numero_diferente" sera imprimido "pcao invalido para o gereno"
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