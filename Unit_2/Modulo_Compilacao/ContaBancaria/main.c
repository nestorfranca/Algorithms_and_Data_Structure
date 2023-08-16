#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.c"

#define MAX_CONTAS 5

int opcoes(void);
int localiza(ContaBancaria *conta, int numero);

int main(void){
    int opcao, numero, contador_contas = 0, indice;
    int num_conta, num_conta2;
    float deposito, saque, transferir, saldo_conta;
    char titular[30];

    ContaBancaria **conta = (ContaBancaria**) malloc(MAX_CONTAS*sizeof(ContaBancaria*));
    if(conta == NULL){
        printf("Erro na alocacao!\n");
        exit(1);
    }
    for(indice =0; indice < MAX_CONTAS; indice++){
        conta[indice] = (ContaBancaria*) malloc(sizeof(ContaBancaria));
    }

    do
    {
      opcao = opcoes;

      switch (opcao)
      {
      case 1:
        if(contador_contas >= MAX_CONTAS){
            printf("MAximos de contas alcancados!\n");
            break;
        }

          printf("Digite o nome do titular\n:");
          scanf(" %[^\n]", titular);
          printf("Digite o numero da conta:\n");
          scanf("%d", &numero);
          conta[contador_contas] = cria_conta(titular, numero);
          contador_contas++;
          break;

        case 2:
          printf("Digite o numero da conta:");
          scanf("%d", &numero);
          printf("Digite o valor a ser depositado:\n");
          scanf("%f", &deposito);
          num_conta = localiza(*conta, numero);
          deposita(conta[num_conta], deposito);

          break;

        case 3:
          printf("Digite o numero da conta:");
          scanf("%d", &numero);
          printf("Digite o valor a ser depositado:\n");
          scanf("%f", &saque);
          num_conta = localiza(*conta, numero);
          saca(conta[num_conta], saque);

          break;

        case 4:
          printf("Digite o numero da conta:");
          scanf("%d", &numero);
          num_conta = localiza(*conta, numero);
          printf("Digite o numero da conta:");
          scanf("%d", &numero);
          num_conta2 = localiza(*conta, numero);
          printf("Digite o valor a ser depositado:\n");
          scanf("%f", &transferir);
          transfere(conta[num_conta], conta[num_conta2], transferir);

          break;

        case 5:
          printf("Digite o numero da conta:");
          scanf("%d", &numero);
          num_conta = localiza(*conta, numero);
          saldo_conta = saldo(conta[num_conta]);
          printf("Salso: R$", saldo_conta);

          break;

        case 6:
          printf("Digite o numero da conta:");
          scanf("%d", &numero);
          num_conta = localiza(*conta, numero);
          excluir(conta[num_conta]);

          break;

      default:
          break;
      }
    } while (opcao != 6);

    return 0;
}

int opcoes(void){
    int opcao;

    printf("1-Criar conta\n");
    printf("2-Depositar\n");
    printf("3-Sacar\n");
    printf("4-Transfere\n");
    printf("5-Saldo\n");
    printf("6-Excluir conta\n");
    scanf("%d", &opcao);

    return opcao;
}

int localiza(ContaBancaria *conta, int numero){
    int indice;

    for(indice = 0; indice <= MAX_CONTAS; indice++){
        if(conta[indice].num == numero){
           return indice;
        }
    }
}
