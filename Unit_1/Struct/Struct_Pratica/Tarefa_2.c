#include <stdio.h>
#include <stdlib.h>

// Programa que cadastra funcionarios

#define QNT_FUNCIONARIO 3

//Passo 1- Definir a struct que representa o funcionario
typedef struct funcionario{
    char nome[30];
    char cargo[20];
    int idade;
    float salario;
}Funcionario;

Funcionario * CadastraFuncionario(void){
/*Funcao que cadastra funcionario*/

    int quant_funcionario;
    printf("Informe a quantidade de funcionarios que deseja ser cadastrado:\n");
    scanf("%d", &quant_funcionario);
    printf("\n");

    //Declaracao e verificacao do vetor
    Funcionario * vetor_funcionario = (Funcionario*) malloc(quant_funcionario * sizeof(Funcionario));
    if(vetor_funcionario == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    }

    int indice;
    for(indice = 0; indice < quant_funcionario; indice++){
        printf("Digite o nome:\n");
        scanf(" %[^\n]", vetor_funcionario[indice].nome);
        printf("Digite a idade:\n");
        scanf("%d", &vetor_funcionario[indice].idade);
        printf("Digite o salario:\n");
        scanf("%f", &vetor_funcionario[indice].salario);
        printf("Digite o cargo:\n");
        scanf(" %[^\n]", &vetor_funcionario[indice].cargo);
        printf("\n");
    }

    return vetor_funcionario;

}

void imprime(Funcionario * funcionario, int quant_funcionario);

int main(void){

    //Chamando a funcao que cadastra os funcionario 
    Funcionario * funcionario = CadastraFuncionario();

    //Chamando a funcao que imprime os dados
    imprime(funcionario, QNT_FUNCIONARIO);

    return 0;
}

void imprime( Funcionario * funcionario, int quant_funcionario){
    
    int indice;
    for(indice = 0; indice < quant_funcionario; indice++){
        printf("Dados do %d funcionario:\nNome: %s\nIdade: %d\nCargo: %s\nSalario: %.2f\n", indice+1, funcionario[indice].nome, funcionario[indice].idade, funcionario[indice].cargo, funcionario[indice].salario);
        printf("\n");
    }
}