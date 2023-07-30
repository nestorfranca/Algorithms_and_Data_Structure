#include <stdio.h>
#include <stdlib.h>

//Difinindo a struct dos dados
typedef struct banco{
    char nome[30];
    char senha[20];
    int num_conta;
    int agencia;
    float saldo;
}Banco;

// Declarando as funcoes 
Banco * vetor_banco(int qnt_contas);
void imprime(Banco * banco, int qnt_contas);

int main(void){

    //Recebenco a quantidade de contas
    int qnt_contas;
    printf("Quantas contas seram cadastradas:\n");
    scanf("%d", &qnt_contas);

    //Chamando as funcoes
    Banco * banco = vetor_banco(qnt_contas);
    imprime(banco, qnt_contas);

    return 0;
}

//Funcao que coleta os dados das contas
Banco * vetor_banco(int qnt_contas){

    Banco * banco = (Banco*) malloc(qnt_contas * sizeof(Banco));
    if(banco == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    }else {printf("Alocacao bem sucedida!\n");}

    int indice;
    for(indice = 0; indice < qnt_contas; indice++){
        printf("Digite o nome:\n");
        scanf(" %[^\n]", banco[indice].nome);
        printf("Digite o numero da conta:\n");
        scanf("%d", &banco[indice].num_conta);
        printf("Digite o numero da agencia:\n");
        scanf("%d", &banco[indice].agencia);
        printf("Digite o saldo:\n");
        scanf("%f", &banco[indice].saldo);
        printf("Digite a senha:\n");
        scanf(" %[^\n]", banco[indice].senha);
        printf("\n");
    }

    return banco;
}

//Funcao que imprime os dados de todas as contas
void imprime(Banco * banco, int qnt_contas){

    int indice;
    for(indice = 0; indice < qnt_contas; indice++){
        printf("Dados da %d contas:\nNome: %s\nConta: %d\nAgencia: %d\nSaldo: %.2f\nSenha: %s\n", indice+1, banco[indice].nome, banco[indice].num_conta, banco[indice].agencia, banco[indice].saldo, banco[indice].senha);
        printf("\n");
    }
}