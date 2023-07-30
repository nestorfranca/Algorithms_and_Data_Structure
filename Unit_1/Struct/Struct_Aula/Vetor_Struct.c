#include <stdio.h>

typedef struct pessoa{      //Declarando uma strcut para armazenar os dados da pessoa
    char nome[25];
    int idade;
    float altura;
    int Rg;
}Pessoa;

int main(void){

    Pessoa var_pessoa[3];   //Alocando memoria estaticamente para o vetor pessoa
    int i;

    //Laco "for" para solicitar os dados de todos od usuarios
    for(i=0; i < 3; i++){
        printf("Digite o nome:\n");
        scanf(" %[^\n]", var_pessoa[i].nome);

        printf("Digite a idade:\n");
        scanf("%d", &var_pessoa[i].idade);

        printf("Digite a altura:\n");
        scanf("%f", &var_pessoa[i].altura);

        printf("Digite o RG:\n");
        scanf("%d", &var_pessoa[i].Rg);
    }

    //Imprimindo os dados
    for(i=0; i < 3; i++){
        printf("Dados:\nNome:%s\tIdade:%d\tAltura:%.2f\tRG:%d", var_pessoa[i].nome, var_pessoa[i].idade, var_pessoa[i].altura, var_pessoa[i].Rg);
    }

    return 0;
}