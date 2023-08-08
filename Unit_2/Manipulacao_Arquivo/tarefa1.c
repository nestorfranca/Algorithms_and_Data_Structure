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

void copia_dados(FILE* fl, int n, Funcionario** pessoal);
void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto);

Funcionario *new_funcionario(void){

    Funcionario *new_funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    if(new_funcionario == NULL){exit(1);}

    return new_funcionario;
}

int main(void){

    int quant_funcionario, index = 0;
    FILE *file;
    file = fopen("Arquivo.txt", "r");
    if(file == NULL){
        printf("Deu errado");
        exit(1);
    }
    
    fscanf(file, "%d", &quant_funcionario);
    //printf("%d", quant_funcionario);
    Funcionario **funcionario = (Funcionario**) calloc(quant_funcionario+1,sizeof(Funcionario*));

    copia_dados(file, quant_funcionario, funcionario);
    imprime_folha_pagamento(quant_funcionario, funcionario, 'A');
    imprime_folha_pagamento(quant_funcionario, funcionario, 'B');
    imprime_folha_pagamento(quant_funcionario, funcionario, 'C');

    fclose(file);
    for(index; index < quant_funcionario; index++){
        free(funcionario[index]);
    }
    free(funcionario);

    return 0;
}

void copia_dados(FILE* fl, int n, Funcionario** pessoal){

    char linha[100];
    int index = 0;
              
    while(fgets(linha,100,fl) != NULL){
        pessoal[index] = new_funcionario();
        sscanf(linha, "%s\t%s\t%c\t%f", pessoal[index]->funcional, pessoal[index]->nome, &pessoal[index]->depto, &pessoal[index]->salario);
        //printf("%s", pessoal[index]->funcional);
        index++;
    }
}

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
