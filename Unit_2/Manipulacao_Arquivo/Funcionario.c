#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario{
    int id;
    char nome[50];
    float salario;
}Funcionario;

Funcionario *new_funcionario(void){

    Funcionario *new = (Funcionario*) malloc(sizeof(Funcionario));
    if(new == NULL){exit(1);}

    return new;
}

void coleta_dados(Funcionario **funcionarios){
    
    int index;

    for(index = 0; index < 2; index++){
        funcionarios[index] = new_funcionario();

        printf("Digite o nome do funcionario: \n");
        scanf(" %[^\n]", funcionarios[index]->nome);
        printf("Digite o id do funcionario: \n");
        scanf("%d", &funcionarios[index]->id);
        printf("Digite o salario do funcionario: \n");
        scanf("%f", &funcionarios[index]->salario);
    }

}

void escreve_dados(FILE *Arq, Funcionario **funcionarios){
    int index;

    Arq = fopen("Arquivo.txt", "wt");
    if(Arq == NULL){exit(1);}

    for(index = 0; index < 2; index++){
        fprintf(Arq, "Dados do %d funcionario:\n", index+1);
        fprintf(Arq, "Nome: %s\nId: %d\nSalario: %.2f\n", funcionarios[index]->nome, funcionarios[index]->id, funcionarios[index]->salario);  
    }
}

int main(void){

    Funcionario ** funcionarios = (Funcionario**) calloc(2,sizeof(Funcionario*));
    FILE *Arq;

    coleta_dados(funcionarios);
    escreve_dados(Arq, funcionarios);

    return 0;
}
