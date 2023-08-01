#include <stdio.h>
#include <stdlib.h>

int main(void){
    char str[100];

    FILE *fp;
    fp = fopen("Arquivo.txt", "r");     //Abrindo arquivo
    if(fp == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    fscanf(fp, "%s", str);    //Copiando o texto do arquivo para a variavel "str"
    printf("%s", str);      //imprimindo o texto da variavel "str'
    fclose(fp);     //Fechando arquivo
    
    return 0;
}
