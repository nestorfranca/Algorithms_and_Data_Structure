#include "disciplina.h"
/* TAD: alunos */

/* Tipo exportado */
typedef struct aluno Aluno;

/* Funções exportadas */

/* Função para alocar memória para uma struct do tipo Aluno */ 
Aluno *cria_aluno(char nome[], int matricula);
/* Função para matricular o aluno em uma disciplina */
void matricula_displina(Aluno *aluno, Disciplina *disciplina);
/* Função para liberar espaço na memória */
void exclui_aluno(Aluno *aluno);
