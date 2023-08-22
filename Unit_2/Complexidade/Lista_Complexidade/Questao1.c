#include <stdio.h>

void soma(int n){
    int i, soma = 0;  // c1
    for(i = n; i >= 0; i--){   // c2*n
        soma += i;  //c3*n  
    }
}

//T(n) = c1 + c2*n + c3*n
//T(n) = n*(c2 + c3) + c1
//a = c2 + c3
//b = c1
//T(n) = a*n + b

//O(n) 

int main(void){

    soma(8);

    return 0;
}
