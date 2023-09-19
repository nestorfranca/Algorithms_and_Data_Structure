#include <stdio.h>
#include "calc.c"

int main(void){
    char c;
    float v;
    Calc *calc;

    calc = calc_cria("%.2f\n");

    do
    {
        scanf(" %c", &c);

        if(c =='+' || c=='-'|| c=='*' || c=='/'){
            calc_operador(calc,c);
        }else{
            ungetc(c,stdin);
            if(scanf("%f", &v) == 1)
                calc_operando(calc,v);
        }
    } while (c != 'q');
    calc_libera(calc);
    return 0;
    
}
