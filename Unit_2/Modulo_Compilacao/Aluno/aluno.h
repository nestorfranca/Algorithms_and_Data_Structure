/* Arquivo aluno.h */

#include <stdio.h>

/* Tipo exportado */
typedef struct aluno Aluno;

/* Funções exportadas */

/* Aloca dinamicamente memoria para um aluno */
Aluno *aluno_cria(char *nome, float nota);

/* Libera o espaço da struct que armazena os alunos */
void aluno_libera(Aluno *a);

/* Imprime na tela os dados de um aluno */
void aluno_imprime(Aluno *a);

/* Ordena os alunos em ordem alfabetica */
void aluno_ordena(int n, Aluno **v);

/* Salva os dados dos alunos em um arquivo texto */
void aluno_salva(FILE *fl, int n, Aluno **v);