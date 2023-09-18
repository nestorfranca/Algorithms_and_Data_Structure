/* TAD: Pilha */

/* Tipo exportado */
typedef struct pilha Pilha;

/* Funções exportadas */

/*  Criar Pilha

*/
Pilha *pilha_cria(void);

/* Função push

*/
void pilha_push(Pilha *p, float v);

/* Função pop
 
*/
float pilha_pop(Pilha *p);

/* Função vazio

*/
int pilha_vazia(Pilha *p);

/* Função libera

*/
void pilha_libera(Pilha *p);

/* Função imprime

*/
void pilha_imprime(Pilha *p);
