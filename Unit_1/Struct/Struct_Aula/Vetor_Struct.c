#include <stdio.h>

typedef struct pessoa{
    char nome[25];
    int idade;
    float altura;
    int Rg;
}Pessoa;

int main(void){

    Pessoa var_pessoa[3];
    int i;

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

   //printf("Dados:\nNome:%s\tIdade:%d\tAltura:%.2f\tRG:%d", var_pessoa.nome, var_pessoa.idade, var_pessoa.altura, var_pessoa.Rg);

    return 0;
}