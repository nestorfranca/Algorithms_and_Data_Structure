#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz {
    int lin;
    int col;
    float **v;
};

Matriz *mat_cria(int m, int n){

    Matriz *matriz = (Matriz*) calloc(1,sizeof(Matriz));

    matriz->v = (float**) malloc(m*sizeof(float*));
    if(matriz->v == NULL) exit(1);
	// printf("..");
    
	int index;
    for(index = 0; index < m; index++){
        matriz->v[index] = (float*) calloc(1,sizeof(float));
    }
    
	printf("Matriz criada!\n\n");

	matriz->lin = m;
	matriz->col = n;

    return matriz;
}

void mat_libera(Matriz *mat){
    int index;
	for(index = 0; index < mat->col; index++){
		free(mat->v[index]);
	}
	free(mat->v);
}

float mat_acessa(Matriz *mat, int i, int j){
    return mat->v[i][j];
}

void mat_atribui(Matriz *mat, int i, int j, float v){
	mat->v[i][j] = v;
}

int mat_linhas(Matriz* mat){
	return mat->lin;
}

int mat_colunas(Matriz* mat){
	return mat->col;
}
