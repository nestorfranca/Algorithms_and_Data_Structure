#include <stdio.h>

//Declarando uma strcut para armazenar os dados do aluno
typedef struct aluno {
    char nome[20];
    int idade;
    int matricula;
}Aluno;

//typedef struct aluno Aluno;   [Outra maneira de mudar o nome da variavel]

int main(void){

    //struct aluno var_aluno;   [Outra maneira de declarar]
    Aluno var_aluno;
    
    //Solicitando os dados
    printf("Digite o nome:\n");
    scanf(" %[^\n]", var_aluno.nome);

    printf("Digite a idade:\n");
    scanf("%d", &var_aluno.idade);

    printf("Digite a matricula:\n");
    scanf("%d", &var_aluno.matricula);
    
    //Imprimindo os dados
    printf("Os dados informados:\nNome:%s \t idade:%d \t matricula:%d  ", var_aluno.nome, var_aluno.idade, var_aluno.matricula);

    return 0;
}