/* Matriz */

/* Tipo exportado */
typedef struct matriz Matriz;

/* Funções exportadas */

/* Cria e aloca memoria para uma matriz de tamanho m por n*/
Matriz *mat_cria(int m, int n);

/* Libera o espaço */
void mat_libera(Matriz *mat);

/* Acessa um elemento especifico da matriz */
float mat_acessa(Matriz* mat, int i, int j);

/* Atribui um elemento em na linha e na coluna da matriz */
void mat_atribui(Matriz *mat, int i, int j, float v);

/* Retorna o numero de linhas da matriz */
int mat_linhas(Matriz* mat);

/* Retorna o numero de colunas da matriz */
int mat_colunas(Matriz* mat); 