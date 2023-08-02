#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    char nome_arquivo[20];
    int c;
    float numero = 934;
     
    printf("Informe o nome do arquivo: \n");
    scanf(" %[^\n]", nome_arquivo);     //RECEBE O NOME DO ARQUIVO
    char ext[] = ".txt";        //CONCATENA ".TXT" NO FINAL
    strcat(nome_arquivo, ext);

    FILE * arquivo = fopen(nome_arquivo, "w");   //ABRI ARQUIVO 
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }else {
        printf("Aquivo criado com sucesso\n");
    }
    //fputs("Hello World!", arquivo);       //ESCREVE 'string' NO ARQUIVO CRIADO
    fprintf(arquivo, "\n Algoritmos e Estrutura de dados 1 : %f\n", numero);

    fclose(arquivo);  //FECHA ARQUIVO
    
    arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while (!feof(arquivo)){     //CHECA SE CHEGOU NO FNAL DO ARQUIVO
        c = fgetc(arquivo);     //COPIA O CARACTER
        printf("%c", c);    //IMPRIME O CARACTER
    }

    fclose(arquivo);  //FECHA ARQUIVO

    return 0;
}
