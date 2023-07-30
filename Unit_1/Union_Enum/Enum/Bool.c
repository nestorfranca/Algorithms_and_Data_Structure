#include <stdio.h>
#include <stdlib.h>

typedef enum bool{
    FALSE, TRUE
}Bool;

int main(void){

    int var;

    printf("Digite um 1 para verdadeiro ou 0 para falso: \n");
    scanf("%d", &var);
    
    if(var == TRUE){
        printf("Verdadeiro\n");
    } else if(var == FALSE){
        printf("Falso\n");
    } else{
        printf("Numero invalido!\n");
    }

    return 0;
}