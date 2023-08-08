#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declarando a struct para armazenar os dados dos funcionarios
typedef struct funcionario{
    char funcional[3];
    char nome[20];
    char depto;
    float salario;
}Funcionario;

//Prototipos das funcoes
void copia_dados(FILE* fl, int n, Funcionario** pessoal);
void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto);

//Funcao para alocar espaco na memoria para armazenar os dados dos funcionarios
Funcionario *new_funcionario(void){

    Funcionario *new_funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    if(new_funcionario == NULL){exit(1);}

    return new_funcionario;
}

int main(void){

    int quant_funcionario, index = 0;
    FILE *file;
    //Abrindo arquivo para leitura
    file = fopen("Arquivo.txt", "r");
    if(file == NULL){
        printf("Deu errado");
        exit(1);
    }

    //Lendo quantos funcionario estoa na pesquisa 
    fscanf(file, "%d", &quant_funcionario);
    //Alocando memoria para um vetor de vetores 
    Funcionario **funcionario = (Funcionario**) calloc(quant_funcionario+1,sizeof(Funcionario*));

    //Chamando a funcao para copiar os dados para um vetor
    copia_dados(file, quant_funcionario, funcionario);
    //Chamando as funcoes para imprimir os dados
    imprime_folha_pagamento(quant_funcionario, funcionario, 'A');
    imprime_folha_pagamento(quant_funcionario, funcionario, 'B');
    imprime_folha_pagamento(quant_funcionario, funcionario, 'C');

    //Fechando o arquivo
    fclose(file);
    //Limpando memoria dos vetores 
    for(index; index < quant_funcionario; index++){
        free(funcionario[index]);
    }
    free(funcionario);

    return 0;
}

//Funcao para copiar os dados
void copia_dados(FILE* fl, int n, Funcionario** pessoal){

    char linha[100];
    int index = 0;

    //Lendo os dados e armazenando em um vetor separadamente 
    while(fgets(linha,100,fl) != NULL){
        //Chamando a funcao para alocar memoria para os funcionarios separadamente 
        pessoal[index] = new_funcionario();
        sscanf(linha, "%s\t%s\t%c\t%f", pessoal[index]->funcional, pessoal[index]->nome, &pessoal[index]->depto, &pessoal[index]->salario);
        index++;
    }
}

//Funcao para imprimir os dados 
void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto){

    int index = 0;
    float soma_salario = 0.0;
    
    printf("FOLHA DE PAGAMENTO DEPTO %c\n", depto);
    printf("FUNCIONAL\tNOME\t\tDEPTO\t\tSALARIO\n");
    for(index; index < n+1; index++){
      if(depto == pessoal[index]->depto){
          printf("%-s\t\t%-s\t\t%-c\t\t%-.2f\n", pessoal[index]->funcional, pessoal[index]->nome, pessoal[index]->depto, pessoal[index]->salario);
          soma_salario += pessoal[index]->salario;
       }
    }
    printf("VALOR TOTAL: R$ %.2f\n\n", soma_salario); 
}
