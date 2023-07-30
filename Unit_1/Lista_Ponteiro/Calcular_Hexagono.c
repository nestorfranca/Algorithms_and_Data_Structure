#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro){

    *area = (3*pow(l, 2)*sqrt(3))/2;
    *perimetro = 6*l;

}

int main(void){
    
    float l, area, perimetro;

    printf("Digite o valor do lado l:\n");
    scanf("%f", &l);

    calcula_hexagono(l, &area, &perimetro);
    printf("A area do hexagono e: %f, e o perimetro e: %f", area, perimetro);

    return 0;
}