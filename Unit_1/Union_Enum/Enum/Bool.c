#include <stdio.h>
#include <stdlib.h>

typedef enum bool{  //Enum para simular variaveis booleanas
    FALSE, TRUE
}Bool;

int main(void){

    int var;
    //Solicitando para o usuario digitar um numero
    printf("Digite um 1 para verdadeiro ou 0 para falso: \n");
    scanf("%d", &var);
    
    //Caso o usuario tenha digitado "1", sera imprimido "Verdadeiro" na tela
    //Caso o usuario tenha digitado "0", sera imprimido "Falso" na tela
    //Caso o usuario tenha digitado "Qualquer_numero_diferente" sera imprimido "Numero invalido!" na tela
    if(var == TRUE){
        printf("Verdadeiro\n");
    } else if(var == FALSE){
        printf("Falso\n");
    } else{
        printf("Numero invalido!\n");
    }

    return 0;
}