#include <stdio.h>
    
    //a) É uma advertência
    //b) Por causa dos erros no código, como a falta do return e não elencar o endereço da variavél corretamente
    //c) Não
    //d) 
int main(void) {
  
    int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p = %p\tValor de *p = %d", p, *p);
    
    return 0;
}
    //e) Sim 