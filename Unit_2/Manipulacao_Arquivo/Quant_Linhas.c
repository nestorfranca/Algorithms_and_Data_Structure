#include <stdio.h>
#include <stdlib.h>

int main(void){
    int c;
    int nlinhas = 0;
    FILE *fp;
    
    fp = fopen("entrada.txt", "rt");     //Abrindo arquivo
    if(fp == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    while((c = fgetc(fp)) != EOF){  // Lê caracter a caracter
        if(c == '\n')
            nlinhas++;
        
    }
   
    fclose(fp);     //Fechar arquivo
    printf("Numero de linhas = %d", nlinhas);       //Imprimindo a quantidade de linhas
    
    return 0;
}
