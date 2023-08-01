#include <stdio.h>
#include <stdlib.h>

int main(void){
    int c;
    
    FILE *fp;
    fp = fopen("Arquivo.txt", "r");     //Abrindo arquivo
    if(fp == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    c = fgetc(fp);    //Ler o primeiro caracter do arquivo
    printf("%c\n", c);      //imprimindo o caracter lido
    fclose(fp);     //Fechando arquivo
    
    return 0;
}
