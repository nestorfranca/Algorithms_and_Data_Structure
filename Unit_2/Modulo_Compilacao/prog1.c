#include <stdio.h>
//#include "str.c"

int comprimento (char *str);
void copia (char *dest, char *orig);
void concatena (char* dest, char *orig);

int main(void){

    char str[100], str1[51], str2[51];
    printf("Digite uma sequencia de caracters: ");
    scanf(" %50[^\n]", str1);
    printf("Digite uma sequencia de caracters: ");
    scanf(" %50[^\n]", str2);
    copia(str, str1);
    concatena(str, str2);
    printf("Comprimento da concatenacao : %d\n", comprimento(str));

    return 0;
}
