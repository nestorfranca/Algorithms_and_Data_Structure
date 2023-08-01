#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fp;
    fp = fopen("entrada.txt", "wt");
    if(fp == NULL){
        printf("Erro na abertura do arquivo!");
        exit(1);
    }

    return 0;
}
