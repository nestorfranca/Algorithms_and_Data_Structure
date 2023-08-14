/* TAD: Ponto (x,y) */

/* Tipo exportado */
typedef struct ponto Ponto;

/* Funções exportadas */

/* Função para criar */
Ponto *pto_cria (float x, float y);
/* Função para libera espaço na memória */
void pto_libera (Ponto* p);
/* Função para acessar a estrutura */
void pto_acessa (Ponto *p, float *x, float *y);
/* Função paraa atribuir valores */
void pto_atribui (Ponto *p, float x, float y);
/* Função para medir a distancia entre os pontos */
float pto_distancia (Ponto *pl, Ponto* p2);
