#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Declarando uma struct para armazenar os dados dos alunos
struct aluno{
    int mat;
    char nome[81];
    char end[121];
    char tel[21];
};

// Definindo Aluno como uma struct do tipo aluno
typedef struct aluno Aluno;

// Funcao que inicializa cada posicao do vetor com NULL
void inicializa (int n, Aluno ** tab){
    int i;
    for (i = 0; i < n; i++){
        tab[i] = NULL;
    }
}

// Funcao para preencher os dados dos usuarios
void preenche (int n, Aluno ** tab, int i){
    // Programa parar a execucao caso i seja menor que 0 ou seja maior ou igual n
    if (i < 0 || i >= n ){
        printf("Indice fora do limite do vetor. \n");
        exit(1);
    }
    // Ira alocar um espaco na memoria para cada parte do vetor tab que tiver em NULL
    if (tab[i] == NULL){
        tab[i] = (Aluno*) malloc(sizeof(Aluno));
    }

    // Socilita e receebe os dados dos usuarios
    printf("Entre com matricula: ");
    scanf("%d", &tab[i]->mat);   
    printf("Entre com o nome: ");
    scanf(" %80[^\n]", tab[i]->nome);
    printf("Entre com o enderenco: ");
    scanf(" %120[^\n]", tab[i]->end);
    printf("Entre com telefone: ");
    scanf(" %20[^\n]", tab[i]->tel);    
}

// Funcao para limpar o espaco na memoria
void retira (int n, Aluno ** tab, int i){
    // Programa parar a execucao caso i seja menor que 0 ou seja maior ou igual n
    if (i < 0 || i >= n){
        printf("Indice fora do limite do vetor. \n");
        exit(1);
    }
    // Caso o vetor tab na posicao i esteja diferente de NULL, o programa ira limpar o espaco na memoria e atribuir NULL novamente
    if (tab[i] != NULL){
        free(tab[i]);
        tab[i] = NULL;
    }
}

// Funcao para imprmir os dados 
void imprime (int n, Aluno ** tab, int i){
     // Programa parar a execucao caso i seja menor que 0 ou seja maior ou igual n
    if (i < 0 || i >= n){
        printf("Indice fora do limite do vetor. \n");
        exit(1);
    }
    // O program ira imprimir na tela os dados dos usuarios
    if (tab[i] != NULL){
        printf("Matricula: %d\n", tab[i]->mat);
        printf("Nome: %s\n", tab[i]->nome);
        printf("Endereco: %s\n", tab[i]->end);
        printf("Telefone: %s\n", tab[i]->tel);
    }
}

// Funcao que chama a funcao imprime
void imprme_todo (int n, Aluno ** tab){
    int i;
    // Ciclo que chama a funcao imprime n vezes
    for(i = 0; i < n; i++){
        imprime(n, tab, i);
    }
}

int main(void){
    Aluno * tab[MAX];// Declaraando um ponteiro para um vetor do tipo Aluno   
    inicializa(10, tab); // Chamando a funcao inicializa
    preenche(10, tab, 0); // Chamando a funcao preenche para a posicao 0
    preenche(10, tab, 1); // Chamando a funcao preenche para a posicao 1
    preenche(10, tab, 2); // Chamando a funcao preenche para a posicao 2
    imprme_todo(10, tab); // Chamando a funcao para imprmir os dados
    retira(10, tab, 0); // Chamando a funcao retira para a posicao 0
    retira(10, tab, 1); // Chamando a funcao retira para a posicao 1
    retira(10, tab, 2); // Chamando a funcao retira para a posicao 2
    
    return 0;
}