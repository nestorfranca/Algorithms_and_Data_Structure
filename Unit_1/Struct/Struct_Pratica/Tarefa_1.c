#include <stdio.h>
#include <stdlib.h>
// Programa que cadastra funcionarios

//Passo 1- Definir a struct que representa o funcionario
typedef struct funcionario{
    char nome[30];
    char cargo[20];
    int idade;
    float salario;
}Funcionario;

void CadastraFuncionario(Funcionario * vetor_funcionario, int quant_funcionario){
/*Funcao que cadastra funcionario*/

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

}

int main(void){

    int quant_funcionario;
    printf("Informe a quantidade de funcionarios que deseja ser cadastrado:\n");
    scanf("%d", &quant_funcionario);
    printf("\n");

    //Declaracao e verificacao do vetor
    Funcionario * vetor = (Funcionario*) malloc(quant_funcionario * sizeof(Funcionario));
    if(vetor == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    }

    //Chamando a funcao que cadastra os funcionario 
    CadastraFuncionario(vetor, quant_funcionario);

    return 0;
}