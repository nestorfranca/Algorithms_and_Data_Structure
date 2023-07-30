#include <stdio.h>

int soma(int valor1, int valor2){

    int som = valor1 + valor2;
    return som;
}

int main(void){

    int (*ponteiro_soma)(int, int) = soma;
    
    int result = ponteiro_soma(2,3);
    printf("valor da soma: %d \n ", result);


    return 0;
}