#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"
// #include "contabancaria.c"

int main(void){

    // Criando duas contas 
    ContaBancaria *conta1 = cria_conta("Nestor", 123);
    ContaBancaria *conta2 = cria_conta("Franca", 321);

    // Depositando R$ 4000.00 na conta1
    deposita(conta1, 4000.00);

    // Saldo da conta1 e da conta2
    printf("Saldo da conta1: R$ %.2f\n\n", saldo(conta1));
    printf("Saldo da conta2: R$ %.2f\n", saldo(conta2));

    // Sacando 1456.50 da conta1 (saldo esperado : R$ 2543.50)
    saca(conta1, 1456.5);

    // Saldo da conta1
    printf("Saldo da conta1: R$ %.2f\n\n", saldo(conta1));

    // Transferindo 2530.00 da conta1 para a conta2 (saldo esperado na conta1: R$ 13.50)
    transfere(conta1, conta2, 2530.0);

    // Saldo da conta1 e da conta2
    printf("Saldo da conta1: R$ %.2f\n", saldo(conta1));
    printf("Saldo da conta2: R$ %.2f\n\n", saldo(conta2));


    // Limpando a memoria onde esta as duas contas
    excluir(conta2);
    excluir(conta1);

    return 0;
}