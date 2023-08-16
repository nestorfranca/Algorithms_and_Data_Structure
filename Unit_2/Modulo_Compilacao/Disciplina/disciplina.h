/* TAD: Diciplinas */

/* Tipo exportado */
typedef struct disciplina Disciplina;

/* Funções exportadas */

/* Aloca uma estrutura do tipo Disciplina */
Disciplina *cria_disciplina(char nome[], int codigo);
/* Função para liberar o espaço na memória */
void exclui_disciplina(Disciplina *disciplina);
