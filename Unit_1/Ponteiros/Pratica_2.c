#include <stdio.h>

int main(void){

    float var=2.5;

    float *p; 

    p = &var;

    printf("Var= %f\nponteiro= %p", var, p);

    *p = 3.8;
    
    printf("\nVar= %f\nponteiro= %p", var, p);

    return 0;
}