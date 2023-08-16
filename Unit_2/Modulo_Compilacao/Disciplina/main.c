#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"
#include "aluno.h"

int main(void){

    char disciplina1[] = "Algoritmo";
    char aluno1[] = "Nestor";
    Disciplina *disciplina = cria_disciplina(disciplina1, 123);
    Aluno *aluno = cria_aluno(aluno1, 4567);
    matricula_displina(aluno, disciplina);

    return 0;
}
