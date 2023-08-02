#include <stdio.h>
#include <stdlib.h>

int main(void){

    char nome_arquivo[20];
    printf("Informe o nome do arquivo: \n");
    scanf(" %[^\n]", nome_arquivo);     //RECEBE O NOME DO ARQUIVO

    FILE * arquivo = fopen(nome_arquivo, "w");   //ABRI ARQUIVO 
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }else {
        printf("Aquivo criado com sucesso");
    }
    sclose(arquivo);  //FECHA ARQUIVO

    return 0;
}
