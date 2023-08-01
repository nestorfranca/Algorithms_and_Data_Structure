#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fp;
    fp = fopen("entrada.txt", "wt");  //Criar arquivo
    if(fp == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }else{ printf("Arquivo criado!\n ");}

    // fclose(fp); usado para fechar o arquivo
    if(!fclose(fp)){    //Fechar arquivo
        printf("Arquivo fechado!\n");
    } 

    return 0;
}
