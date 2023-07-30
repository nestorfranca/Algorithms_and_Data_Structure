#include <stdio.h>
#include <stdlib.h>

typedef struct conta{
    char nome[25];
    int agencia;
    int senha;
    int num_conta;
    float saldo;
}Conta;

int main(void){

    Conta * var_conta = (Conta *) malloc(5*sizeof(Conta));
    int i;

    for(i=0; i < 5; i++){
        printf("Digite o nome:\n");
        scanf(" %[^\n]", var_conta[i].nome);

        printf("Digite a senha:\n");
        scanf("%d", &var_conta[i].senha);

        printf("Digite a agencia:\n");
        scanf("%d", &var_conta[i].agencia);

        printf("Digite o numero da conta:\n");
        scanf("%d", &var_conta[i].num_conta);

        printf("Digite o saldo:\n");
        scanf("%f", &var_conta[i].saldo);

        prinf("\n");
    }

    for(i=0; i < 5; i++){
        printf("Conta:\nNome:%s\tSenha:%d\tAgencia:%d\tConta:%d\tSaldo:%.2f\n", var_conta[i].nome, var_conta[i].senha, var_conta[i].agencia, var_conta[i].num_conta, var_conta[i].saldo);
    }

    free(var_conta);

    return 0;
}