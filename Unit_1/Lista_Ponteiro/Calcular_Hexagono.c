#include <stdio.h>
#include <math.h>

//Função para calcular o valor do hexagono e envia para a função principal 
void calcula_hexagono(float l, float *area, float *perimetro){

    *area = (3*pow(l, 2)*sqrt(3))/2;
    *perimetro = 6*l;

}

int main(void){
    
    float l, area, perimetro;

    //Solicitando ao usuario o valor do lado do hexagono 
    printf("Digite o valor do lado l:\n");
    scanf("%f", &l);

    //Chamando a função para calcular 
    calcula_hexagono(l, &area, &perimetro);
    printf("A area do hexagono e: %f, e o perimetro e: %f", area, perimetro);   //Recebendo e imprimindo o valor do hexagono

    return 0;
}