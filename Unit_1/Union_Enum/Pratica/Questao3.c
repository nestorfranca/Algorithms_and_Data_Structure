/*3. Escreva um programa que implementa uma struct Data com os campos dia, mˆes e ano. O mˆes deve ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARC¸ O, ABRIL, MAIO, JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa deve ler a data e imprimir a data no formato dd/mm/aaaa.*/

#include <stdio.h>
#include <stdlib.h>

typedef enum mes{
    JANEIRO=1, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO
}Mes;

typedef struct data{
    int dia;
    Mes mes;
    int ano;
}Data;

int main(void){

    Data* data = (Data*) malloc(sizeof(Data));
    if(data == NULL){exit(1);}

    printf("Digite o dia: \n");
    scanf("%d", &data->dia);
    printf("1 - JANEIRO\n2 - FEVEREIRO\n3 - MARCO\n4 - ABRIL\n5 - MAIO\n6 - JUNHO\n7 - JULHO\n8 - AGOSTO\n9 - SETEMBRO\n10 - OUTUBRO\n11 - NOVEMBRO\n12 - DEZEMBRO\nEscolha uma opcao para o mes: \n");
    scanf("%d", &data->mes);
    printf("Digite o ano: \n");
    scanf("%d", &data->ano);

    if(data->mes == JANEIRO){
        printf("%d/01/%d", data->dia, data->ano);
    }else if(data->mes == FEVEREIRO){
        printf("%d/02/%d", data->dia, data->ano);
    }else if(data->mes ==  MARCO){
        printf("%d/03/%d", data->dia, data->ano);
    }else if(data->mes == ABRIL){
        printf("%d/04/%d", data->dia, data->ano);
    }else if(data->mes == MAIO){
        printf("%d/05/%d", data->dia, data->ano);
    }else if(data->mes == JUNHO){
        printf("%d/06/%d", data->dia, data->ano);
    }else if(data->mes == JULHO){
        printf("%d/07/%d", data->dia, data->ano);
    }else if(data->mes == AGOSTO){
        printf("%d/08/%d", data->dia, data->ano);
    }else if(data->mes == SETEMBRO){
        printf("%d/09/%d", data->dia, data->ano);
    }else if(data->mes == OUTUBRO){
        printf("%d/10/%d", data->dia, data->ano);
    }else if(data->mes == NOVEMBRO){
        printf("%d/11/%d", data->dia, data->ano);
    }else if(data->mes == DEZEMBRO){
        printf("%d/12/%d", data->dia, data->ano);
    }else{
        printf("Opcao invalida para o mes!");
    }

    free(data);

    return 0;
}