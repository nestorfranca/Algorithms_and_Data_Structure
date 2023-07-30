#include <stdio.h>

int main(void){
    
    int x, y, *ponteiro;
    y = 0;
    ponteiro = &y;
    x = *ponteiro;
    x = 4;
    (*ponteiro)++;
    --x;
    (*ponteiro) += x;

    printf("ponteiro = %p, x = %d, y = %d", ponteiro, x, y);

    //O valor do ponteiro foi o endereço de y (0060FEF4)
    //O valor de x foi 3
    //O valor de y foi 4

    return 0;
}