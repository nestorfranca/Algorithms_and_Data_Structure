#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_VAGAS 10
#define MAX_TURMAS 3

typedef struct alunos{
    int mat;
    char nome[81];
    float notas[3];
    float media;
}Aluno;

typedef struct turma{
    char id;
    int vagas;
    Aluno * alunos[MAX_VAGAS];
}Turma;

Turma * cria_turma(char id);
void listar_turmas(Turma ** turma, int contador);
void matricula_aluno(Turma* turma, int mat, char* nome);
void atualiza_vagas(Turma * turma);
void lanca_notas(Turma* turma);
void imprime_alunos(Turma* turma);
void imprime_turmas(Turma** turmas, int n);
Turma* procura_turma(Turma** turmas, int n, char id);

int Menu(){
    int opcao;

    printf("\nMENU:\n1 - Criar turma\n");
    printf("2 - LIstar turmas\n");
    printf("3 - Matricular aluno\n");
    printf("4 - Lancar notas\n");
    printf("5 - Listar alunos\n");
    printf("6 - Turmas\n");
    printf("7 - Sair\n\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

void inicializa_alunos(int n, Turma * turma){
    int i;
    for(i = 0; i < n; i++){
        turma->alunos[i] = NULL;
    }
   // printf("Vetor inicializado\n");
}

void inicializa_nota(int n, Turma * turma){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < 3; j++){
            turma->alunos[i]->notas[j] = 0.0;
        }
    }
}

void inicializar_vagas(Turma ** turma, int num_turma){

    turma[num_turma]->vagas = MAX_VAGAS;

}

Aluno * new_aluno(void){
    
    Aluno * new_aluno = (Aluno*) malloc(sizeof(Aluno));
    if(new_aluno == NULL)exit(1);

    return new_aluno;
}

float media_aluno(Aluno * alunos){
    float media = 0.0, soma = 0.0;
    int indice;

    for(indice = 0; indice < 3; indice++){
        soma += alunos->notas[indice];
    }

    media = soma/3;
    
    return media;
}

int aluno_matriculado(Turma* turma, int mat, char* nome){
    int indice, vaga_aluno;

    for(indice = 0; indice < MAX_VAGAS; indice++){
        if(mat != turma->alunos[indice]->mat){
            vaga_aluno = 1;
            printf("Aluno ja esta matriculado!");
        }else {
            vaga_aluno = 0;
        }
    }
    return vaga_aluno;
}

int main(void){
    char id;
    char id_turma;
    int opcao, vagas = MAX_VAGAS;
    int contador = 0; //Qunatidades de turmas criadas
    int indice, indice_turma, mat_aluno, indice_aluno = 0;
    char * nome_aluno = (char*) malloc(81*sizeof(char));
    int id_inexistente=0;

    Turma * turmas[MAX_TURMAS];
    Aluno * alunos[MAX_VAGAS];

    printf("Bem-vindo ao Programa de Gerenciamento de Turma!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    printf("Autor: Nestor Franca\tVersao: 1.0\n\n");

    do{
 
    opcao = Menu();
    
    switch (opcao)
    {
    case 1:

        if(contador >= MAX_TURMAS){
        	printf("Maximo de turmas alcancado!\n");
        	break;
        }
		printf("\nCriando nova turma...\n");
        printf("Digite um id: ");
        scanf(" %c", &id);
        turmas[contador] = cria_turma(id);
        if(contador < MAX_TURMAS){
            contador++;
        }
        inicializar_vagas(turmas, contador-1);

        break;

    case 2:

        if(contador == 0 ){
            printf("Nenhuma turma criada!\n");
        }else{
            listar_turmas(turmas, contador);
        }

        break;

    case 3:
        
        printf("\nMatriculando aluno...\n");
        printf("Digte o id da turma: ");
        scanf(" %c", &id_turma);
        
        Turma * turma = procura_turma(turmas, id_turma, contador);
        if( turma != 0){
            printf("Digite a matricula: ");
            scanf("%d", &mat_aluno);
            printf("Digite o nome: ");
            scanf(" %80[^\n]", nome_aluno);
            matricula_aluno(turma, mat_aluno, nome_aluno);

            atualiza_vagas(turma);

        }else{
            printf("Turma nao existe!\n");
        }

        break;

    case 4:

        printf("\nLancando notas...\n");
        printf("Digte o id da turma: ");
        scanf(" %c", &id_turma);
    
        Turma * turma_notas = procura_turma(turmas, id_turma, contador);
        if( turma_notas != 0){
            lanca_notas(turma_notas);
        }else{
            printf("Turma nao existe!\n");
        }

        break;

    case 5:

        printf("\nListando alunos...\n");
        printf("Digte o id da turma: ");
        scanf(" %c", &id_turma);
    
        Turma * turma_alunos = procura_turma(turmas, id_turma, contador);
        if( turma_alunos != 0){
            imprime_alunos(turma_alunos);
        }else{
            printf("Turma nao existe!\n");
        }

        break;

    case 6: 
        
        printf("Status das turmas...\n");
        imprime_turmas(turmas, contador);

        break;

    default:
      if(!(opcao <= 7) || !(opcao >= 1)){
        printf("Opcao invalida!\n");
       }
        break;
    }
    }while(opcao != 7); 

    printf("\nObrigado por usar este programa!");

    return 0; 
}

Turma * cria_turma(char id){
    
    Turma * turma = (Turma*) malloc(1 * sizeof(Turma));   
    if(turma == NULL)exit(1);
    turma->id = id;

    int i;
    for(i = 0; i < MAX_VAGAS; i++){
        inicializa_alunos(MAX_VAGAS, turma);
    }
    
    printf("Turma %c criada com sucesso!\n", id);

    return turma;
}

void listar_turmas(Turma ** turma, int contador){

    int indice;
    printf("\nListando turmas...\n");
    for(indice = 0; indice < contador; indice++){
        printf("Turma %c - %d vagas disponiveis\n", turma[indice]->id, turma[indice]->vagas);
    }
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    int indice_aluno = MAX_VAGAS - turma->vagas;
    
    int vaga_aluno = aluno_matriculado(turma, mat, nome);

    if((vaga_aluno != 0) && (indice_aluno < MAX_VAGAS)){
        turma->alunos[indice_aluno] = new_aluno();
        strcpy(turma->alunos[indice_aluno]->nome, nome);
        turma->alunos[indice_aluno]->mat = mat;
        printf("Matricula realizada com sucesso!\n");
    }
}

void atualiza_vagas(Turma * turma){
    
    turma->vagas--;

}

void lanca_notas(Turma* turma){
    int indice, num_notas;
    for(indice = 0; indice < MAX_VAGAS; indice++){
        if(turma->alunos[indice] != NULL){
            printf("Matricula: %d\tAluno: %s\n", turma->alunos[indice]->mat, turma->alunos[indice]->nome);
            for(num_notas = 0; num_notas < 3; num_notas++){
                printf("Digite a nota %d: ", num_notas+1);
                scanf("%f", &turma->alunos[indice]->notas[num_notas]);
            }
        }else{
            indice = MAX_VAGAS+1;
        }
    }
}

void imprime_alunos(Turma* turma){
    int indice;
    int vagas_ocupadas = MAX_VAGAS - turma->vagas;
    for(indice = 0; indice < vagas_ocupadas; indice++){
        printf("Matricula: %d", turma->alunos[indice]->mat);
        printf("\nNome: %s", turma->alunos[indice]->nome);
        printf("\nMedia: %.1f\n", media_aluno(turma->alunos[indice]));
    }
}

void imprime_turmas(Turma** turmas, int n){
    int indice;
    
    for(indice = 0; indice < n; indice++){
        printf("ID da turma: %c\n", turmas[indice]->id);
        printf("Alunos matriculados: %d\n", MAX_VAGAS - turmas[indice]->vagas);
        printf("Vagas na turma: %d\n", turmas[indice]->vagas);
        // Implementar funcao que diga qual a media da turma
    }
}

Turma* procura_turma(Turma** turmas, int n, char id){
    int indice;
    for(indice = 0; indice < n; indice++){
        if(turmas[indice]->id == n){
            return turmas[indice];        
        }
    }
    return 0;
}