#include <stdio.h>

typedef struct pessoa{      //Declarando uma struct para armazenar os dados da pessoa
    char nome[25];
    int idade;
    float altura;
    int Rg;
}Pessoa;

int main(void){

    Pessoa var_pessoa;  //Alocando memoria estaticamente para o vetor var_pessoa

    //Solicitando e logo apos imprimindo os dados fornecidos
    printf("Digite o nome:\n");
    scanf(" %[^\n]", var_pessoa.nome);

    printf("Digite a idade:\n");
    scanf("%d", &var_pessoa.idade);

    printf("Digite a altura:\n");
    scanf("%f", &var_pessoa.altura);

    printf("Digite o RG:\n");
    scanf("%d", &var_pessoa.Rg);
 
    printf("Dados:\nNome:%s\tIdade:%d\tAltura:%.2f\tRG:%d", var_pessoa.nome, var_pessoa.idade, var_pessoa.altura, var_pessoa.Rg);

    return 0;
}