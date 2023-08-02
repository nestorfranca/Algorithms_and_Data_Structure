#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    char nome_arquivo[20];
    printf("Informe o nome do arquivo: \n");
    scanf(" %[^\n]", nome_arquivo);     //RECEBE O NOME DO ARQUIVO
    char ext[] = ".txt";        //CONCATENA ".TXT" NO FINAL
    strcat(nome_arquivo, ext);  // strcat(nome_arquivo, ".txt");

    FILE * arquivo = fopen(nome_arquivo, "w");   //ABRI ARQUIVO 
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }else {
        printf("Aquivo criado com sucesso");
    }
    fputc('A', arquivo);       //ESCREVE 'A' NO ARQUIVO CRIADO
    fclose(arquivo);  //FECHA ARQUIVO

    return 0;
}
