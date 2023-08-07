#include <stdio.h>

int main(void){

    FILE *file;
    file = fopen("arquivo.txt", "w");
    if(!(file == NULL)){
        printf("Arquivo aberto com sucesso");
    }else{
        printf("Falha ao abrir o arquivo");
    }

    return 0;
}