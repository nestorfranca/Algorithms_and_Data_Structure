/* TAD: fruta*/

/* Tipo exportado */
typedef struct fruta ListaFrutas;

/* Funções exportadas */

/* insere
Função que aloca memoria e insere o nome e preco das frutas
*/
ListaFrutas *insere(ListaFrutas *fruta, char*nome, float valor);

/* imprime
Função que imprime os dados das frutas
*/
void imprime(ListaFrutas* lista);

/* libera
Função que libera o espaço que esta armazenado
*/
void libera(ListaFrutas *lista);
