#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    char frutas;

    char **fruta = (char**) malloc(4 * sizeof(char*));
    if(fruta == NULL){ exit(1);}
    int  count;
    for (count = 0; count < 4; count++){
        fruta[count] = (char*) malloc(10 * sizeof(char));
    }

    strcpy(fruta[0], "maca");
    strcpy(fruta[1], "abacate");
    strcpy(fruta[2], "uva");
    strcpy(fruta[3], "pera");

    for (count = 0; count < 4; count++){
        printf("%s\n", fruta[count]);
    }

    return 0;
}
