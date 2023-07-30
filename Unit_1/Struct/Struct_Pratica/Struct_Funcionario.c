#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario{     //Declarando uma struct para armazenar os dados dos funcionarios
    char nome[30];
    float salario;
    int id;
    char cargo[20];
}Funcionario; 

//Declaracao das funcoes 
Funcionario * Dados_pessoais(int quant_funcionario);
void imprime(Funcionario * funcionario, int quant_funcionario);
//void new_salario(Funcionario * funcionario);
void maior_menor(Funcionario * funcionario, int quant_funcionario);

int main(void){
    int quant_funcionario;

    printf("Quantos funcionarios participaram da pesquisa: \n");
    scanf("%d", &quant_funcionario);
    printf("\n");

    //Chamando as funcoes
    Funcionario * funcionario = Dados_pessoais(quant_funcionario);
    imprime(funcionario, quant_funcionario);
   // new_salario(funcionario);
    maior_menor(funcionario, quant_funcionario);

    //Limpando a memoria
    free(funcionario);

    return 0;
}

//Funcao para colher os dados dos funcionarios
Funcionario * Dados_pessoais(int quant_funcionario){
    int indice;
    //Alocando menoria para o vetor funcionario
    Funcionario * funcionario = (Funcionario *) malloc(quant_funcionario * sizeof(Funcionario));
    if(funcionario == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    }

    //Solicitando os dados dos funcionario
    for(indice = 0; indice < quant_funcionario; indice++){
        printf("Digite o nome do %dª funcionario:\n", indice+1);
        scanf(" %[^\n]", funcionario[indice].nome);
        printf("Digite o id do %dª funcionario:\n", indice+1);
        scanf("%d", &funcionario[indice].id);
        printf("Digite o cargo do %dª funcionario:\n", indice+1);
        scanf(" %[^\n]", funcionario[indice].cargo);
        printf("Digite o salario do %dª funcionario:\n", indice+1);
        scanf("%f", &funcionario[indice].salario);
        printf("\n");
    }

    return funcionario; 
}

//Funcao que imprime os dados dos funcionarios
void imprime(Funcionario * funcionario, int quant_funcionario){
    int indice;
    
    //Imprimindo os dados
    for(indice = 0; indice < quant_funcionario; indice++){
        printf("\nDados do %dª funcionario:\nNome: %s\nID: %d\nCargo: %s\nSalario: %.2f\n", indice+1, funcionario[indice].nome, funcionario[indice].id, funcionario[indice].cargo, funcionario[indice].salario);
    }

}

/*void new_salario(Funcionario * funcionario){
    int final;
    
    while(final == 0){
        printf("Caso deseje mudar o salario de algum funcionario:")
            printf("\nDigite o novo salaraio: \n");
            scanf("%f", &funcionario->salario);
            printf("\nNovo salario: %.2f\n", funcionario->salario);
    }
}*/

//Funcao para saber qual dos funcionarios tem o maior e o menor salario
void maior_menor(Funcionario * funcionario, int quant_funcionario){
    int indice, num_maior_salario = 0, num_menor_salario = 0;

    //Laco "for" responsavel por correr todos os salario para saber qual é o menor e o maior
    for(indice = 1; indice < quant_funcionario; indice++){
        if(funcionario[indice].salario > funcionario[num_maior_salario].salario){
            num_maior_salario = indice;  
        }else if(funcionario[indice].salario < funcionario[num_menor_salario].salario){
            num_menor_salario = indice;
        }
    }

    //Imprimindo o menor e o maior salario
    printf("\n");
    printf("O funcionario que tem o maior salario é %s, com o salario de %.2f\n", funcionario[num_maior_salario].nome, funcionario[num_maior_salario].salario);
    printf("O funcionario que tem o menor salario é %s, com o salario de %.2f\n", funcionario[num_menor_salario].nome, funcionario[num_menor_salario].salario);

}
