#include <stdio.h>
#include <stdlib.h>

//Estrutura para armazemar os dados
typedef struct pessoa{
    char nome[30];
    int CPF;
    int idade;
}Pessoa;

//Declaracao dos funcoes
Pessoa * Dados(int quant_pessoas);
void imprima(Pessoa * pessoa, int quant_pessoas);
void velha_nova(Pessoa * pessoa, int quant_pessoas);

int main(void){
    int quant_pessoas;

    //Perguntando ao usuario quantas pessoas participaram da pesquisa
    printf("Quantas pessoas participaram da pesquisa:\n");
    scanf("%d", &quant_pessoas);
    printf("\n");
   
    Pessoa * pessoa = Dados(quant_pessoas); //Chamando a funcao Dados e armazenando seus resultados em um vetor 
    imprima(pessoa, quant_pessoas);     //Chamando a funcao para imprimir
    velha_nova(pessoa, quant_pessoas);      //Chamando a funcao para saber quem é a pessoa mais velha e nova

    //Limpando a memoria
    free(pessoa);
    
    return 0;
}

//Funcao que coleta os dados de cada pessoa
Pessoa * Dados(int quant_pessoas){
    int indice;

    Pessoa * pessoa = (Pessoa*) malloc(quant_pessoas * sizeof(Pessoa));
    if(pessoa == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    }

    for(indice = 0; indice < quant_pessoas; indice++){
        printf("Digite o nome:\n");
        scanf(" %[^\n]", pessoa[indice].nome);
        printf("Digite a idade:\n");
        scanf("%d", &pessoa[indice].idade);
        printf("Digite o CPF:\n");
        scanf("%d", &pessoa[indice].CPF);
        printf("\n");
    }

    return pessoa;
}

//Funcao que imprime os dados 
void imprima(Pessoa * pessoa, int quant_pessoas){
    int indice;

    for(indice = 0; indice < quant_pessoas; indice++){
        printf("Dados:\nNome: %s\nIdade: %d\nCPF: %d\n", pessoa[indice].nome, pessoa[indice].idade, pessoa[indice].CPF);
        printf("\n");
    }   

}

//Funcao para saber qual das pessoa tem a maior idade e qual tem a menor
void velha_nova(Pessoa * pessoa, int quant_pessoas){
    int indice, num_velha = 0, num_nova = 0;

    for(indice = 1; indice < quant_pessoas; indice++){
        if(pessoa[indice].idade > pessoa[0].idade){
            num_velha = indice;
        }else if (pessoa[indice].idade < pessoa[0].idade){
            num_nova = indice;
        }
    }
 
    printf("\nA pessoa mais velha é %s, ela tem %d anos\n", pessoa[num_velha].nome, pessoa[num_velha].idade);
    printf("A pessoa mais nova é %s, ela tem %d anos", pessoa[num_nova].nome, pessoa[num_nova].idade);

}