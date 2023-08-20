#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"


struct conta{
    char titular[30];
    int num;
    float saldo;
};

ContaBancaria *cria_conta(char *titular, int numero){
    ContaBancaria *conta = (ContaBancaria*) malloc(sizeof(ContaBancaria));
    if(conta == NULL){
        printf("Erro na alocacao!\n\n");
        exit(1);
    }
    conta->num = numero;
    conta->saldo = 0.0;
    strcpy(conta->titular, titular);

    return conta;
}

void deposita(ContaBancaria *conta, float deposito){
    conta->saldo = deposito;
    if(conta->saldo == 0.0){
        printf("Falha ao realizar deposito!\n\n");
        exit(1);
    }else{
        printf("Deposito realizado com sucesso!\n\n");
    }
}

void saca(ContaBancaria *conta, float saque){
    if(conta->saldo >= saque){
        conta->saldo -=saque;
    }else{
        printf("Saldo insuficiente!\n\n");
    }
}

void transfere(ContaBancaria *conta1, ContaBancaria *conta2, float transferir){
    if(conta1->saldo >= transferir){
        conta2->saldo = conta1->saldo;
        conta1->saldo -= transferir;
    }else{
        printf("Saldo insuficiente!\n\n");
    }
}

float saldo(ContaBancaria *conta){
    return conta->saldo;
}

void excluir(ContaBancaria *conta){
    free(conta);
}
