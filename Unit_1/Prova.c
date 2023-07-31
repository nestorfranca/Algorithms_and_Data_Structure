#include <stdio.h>
#include <stdlib.h>

typedef struct professor{
    char nome[100];
    char disciplina[80];
    int regime_de_trabalho;
}Professor;

void preenche_professor(Professor *professor){

    printf("Digite o nome: \n");
    scanf(" %[^\n]", professor->nome);
    printf("Digite o nome da disciplina: \n");
    scanf(" %[^\n]", professor->disciplina);
    printf("Digite o regime de trabalho: \n");
    scanf("%d", &professor->regime_de_trabalho);

}

void imprime_professor(const Professor *professor){

    puts("Dados do professor");
    printf("Nome: %s\n", professor->nome);
    printf("Disciplina: %s\n", professor->disciplina);
    printf("Regime de trabalho: %d\n", professor->regime_de_trabalho);

}

void Altera_regime(Professor *professor){

    printf("Digite o novo regime de trabalho: \n");
    scanf("%d", &professor->regime_de_trabalho);

}

int main(void){

    Professor *professor = (Professor*) malloc(1*sizeof(Professor));
    if(professor == NULL){
        printf("Falha na alocacao de memoria!");
        exit(1);
    }

    preenche_professor(professor);
    puts("");
    imprime_professor(professor);
    puts("");
    Altera_regime(professor);
    puts("");
    imprime_professor(professor);

    free(professor);

    return 0;
}
