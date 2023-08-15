/* TAD: Conta Bancaria */

/* Tipo exportado */
typedef struct conta ContaBancaria;

/* Funcao exportadas */

/* Funcao para olocar memoria para uma conta */
ContaBancaria *cria_conta(char *titular, int numero);
/* Funcao para depositar dinherio na conta */
void deposita(ContaBancaria *conta, float deposito);
/* Funcao para sacar o dinheiro */
void saca(ContaBancaria *conta, float saque);
/* Funcao para transferir o dinheiro para outra conta */
void transfere(ContaBancaria *conta1, ContaBancaria *conta2, float transferir);
/* Funcao pata verificar o saldo */
float saldo(ContaBancaria *conta);
/* Funcao para excluir uma conta */
void excluir(ContaBancaria *conta);
