#include <stdio.h>
#include "circulo.h"

int main(void){

    Circulo* c = circ_cria(2.0, 3.4, 2);
    circ_area(c);
    circ_interior(c, 1.5);
    circ_libera(c);
}
