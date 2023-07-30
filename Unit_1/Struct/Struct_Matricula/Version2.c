#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 10
#define MAX_TURMAS 3

// Declaração de uma union que recebe o indice academico
typedef union ia{
    float IG;
    float IRA;
    float IRT;
}IA;

// Declaração de uma struct para armazenar os dados dos alunos
typedef struct alunos{
    int mat;
    char nome[81];
    float notas[3];
    float media;
    IA indice_academico;
}Aluno;

// Declaração de uma struct para armazenar os dados das turmas
typedef struct turma{
    char id;
    int vagas;
    Aluno * alunos[MAX_VAGAS];
}Turma;

// Declaração dos protótipos das funções
Turma * cria_turma(char id);
void listar_turmas(Turma ** turma, int contador);
void matricula_aluno(Turma* turma, int mat, char* nome);
void atualiza_vagas(Turma * turma);
void lanca_notas(Turma* turma);
void imprime_alunos(Turma* turma);
void imprime_turmas(Turma** turmas, int n);
Turma* procura_turma(Turma** turmas, int n, char id);

// Função para mostrar o menu e solicitar o qual opção o usuário quer
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
    fflush(stdin);

    return opcao;
}

// Função para inicializa um vetor para alunos 
void inicializa_alunos(int n, Turma * turma){
    int i;
    for(i = 0; i < n; i++){
        turma->alunos[i] = NULL;
    }
   // printf("Vetor inicializado\n");
}

// Função para inicializar as notas dos alunos com 0.0
void inicializa_nota(int n, Turma * turma){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < 3; j++){
            turma->alunos[i]->notas[j] = 0.0;
        }
    }
}

// Função para inicializar as vagas da turmas com MAX_VAGAS
void inicializar_vagas(Turma ** turma, int num_turma){

    turma[num_turma]->vagas = MAX_VAGAS;

}

// Função para alocar um espaço na memória para os alunos
Aluno * new_aluno(void){
    
    Aluno * new_aluno = (Aluno*) malloc(sizeof(Aluno));
    if(new_aluno == NULL)exit(1);

    return new_aluno;
}

// Função que cálcula a média dos alunos
float media_aluno(Aluno * alunos){
    float media = 0.0, soma = 0.0;
    int indice;

    for(indice = 0; indice < 3; indice++){
        soma += alunos->notas[indice];
    }

    media = soma/3;
    
    return media;
}

// Função que verifica se a matrícula do aluno já foi feita
int aluno_matriculado(Turma* turma, int mat){
    int indice;
    int indice_aluno = MAX_VAGAS - turma->vagas;

    for(indice = 0; indice < indice_aluno; indice++){
        if(mat == turma->alunos[indice]->mat){
            printf("Aluno ja esta matriculado!\n");
            return 0;
        }
    }
    return 1;
}

// Função que cálcula a média da turma
float media_turma(Turma * turma){
    int indice; 
    int indice_aluno = MAX_VAGAS - turma->vagas;
    float soma_media = 0.0;
    
    if(indice_aluno == 0){
        return 0.0;
    }else{
        for(indice = 0; indice < indice_aluno; indice++){
            if(turma->alunos[indice] != NULL){
                soma_media += turma->alunos[indice]->media;
            }
        }
    }

    return soma_media/indice_aluno; 
}

// Função que mostra opções dos indices e pede que o usuário escolha uma
void IA_aluno(Aluno * aluno){
    int opcao;
    printf("Indice do aluno...\n");
    printf("Opcoes:\n1 - IG\n2 - IRA\n3 - IRT\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Digite o IG do aluno: ");
        scanf("%f", &aluno->indice_academico.IG);
        break;

    case 2:
        printf("Digite o IRA do aluno: ");
        scanf("%f", &aluno->indice_academico.IRA);
        break;

    case 3:
        printf("Digite o IRT do aluno: ");
        scanf("%f", &aluno->indice_academico.IRT);
        break;
    
    }
}

int main(void){
    char id;
    int j;
    char id_turma;
    int opcao, vagas = MAX_VAGAS;
    int contador = 0; //Qunatidades de turmas criadas
    int indice, indice_turma, mat_aluno, indice_aluno = 0;
    char * nome_aluno = (char*) malloc(81*sizeof(char));
    int id_inexistente=0;

    Turma * turmas[MAX_TURMAS]; // Declarando um vetor estaticamente para as turmas
    Aluno * alunos[MAX_VAGAS];  // Declarando um vetor estaticamente para os alunos

    printf("Bem-vindo ao Programa de Gerenciamento de Turma!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    printf("Autor: Nestor Franca\tVersao: 1.3\n\n");

    // Inicio do ciclo 
    do{
 
    opcao = Menu();
    
    switch (opcao) 
    {
    case 1: // Opção para criar turma

        // verificando se ainda há vagas para cadastrar as turmas
        if(contador >= MAX_TURMAS){
        	printf("Maximo de turmas alcancado!\n");
        	break;
        }
		printf("\nCriando nova turma...\n");
        printf("Digite um id: ");
        scanf(" %c", &id);
        turmas[contador] = cria_turma(id); // Criando uma turma para a posição em que contador marcar
        if(contador < MAX_TURMAS){
            contador++;
            // Aumentando a posição de contador em 1
        }
        inicializar_vagas(turmas, contador-1); // Chamando a função para inicializar as vagas

        break;

    case 2: // Opção para listar as turmas
        
        if(contador == 0 ){
            printf("Nenhuma turma criada!\n");
        }else{
            listar_turmas(turmas, contador); // Chamando uma função para listar as turmas
        }

        break;

    case 3: // Opção para matrícular aluno
        
        printf("\nMatriculando aluno...\n");
        printf("Digte o id da turma: ");
        scanf(" %c", &id_turma);
        
        Turma * turma = procura_turma(turmas, id_turma, contador); // Chamando a função que procura a turma que tenha o id inserido
        
        if( turma != 0){
            printf("Digite a matricula: ");
            scanf("%d", &mat_aluno);
            int vaga_aluno = aluno_matriculado(turma, mat_aluno); // Chamando a função para verificar se a matrícula do inserida ja foi usada
            if(vaga_aluno){           
                printf("Digite o nome: ");
                scanf(" %80[^\n]", nome_aluno);
                matricula_aluno(turma, mat_aluno, nome_aluno); // Chamando a função para matrícular os alunos
                atualiza_vagas(turma); // Chamando a função para atualizar as vagas de cada turma
            }
           
        }else{
            printf("Turma nao existe!\n");
        }

        break;

    case 4: // Opção para lançar as notas dos alunos

        printf("\nLancando notas...\n");
        printf("Digte o id da turma: ");
        scanf(" %c", &id_turma);
    
        Turma * turma_notas = procura_turma(turmas, id_turma, contador); // Chamando a função para verificar se a matrícula do inserida ja foi usada
        if( turma_notas != 0){
            lanca_notas(turma_notas); // Chamando a função para lançar as notas
        }else{
            printf("Turma nao existe!\n");
        }

        break;

    case 5: // Opção para listar os alunos

        printf("\nListando alunos...\n");
        printf("Digte o id da turma: ");
        scanf(" %c", &id_turma);
    
        Turma * turma_alunos = procura_turma(turmas, id_turma, contador); // Chamando a função para verificar se a matrícula do inserida ja foi usada
        if( turma_alunos != 0){
            imprime_alunos(turma_alunos); // Chamando a função que lista os alunos
        }else{
            printf("Turma nao existe!\n");
        }

        break;

    case 6: // Opção para mostrar os dados especificos das turmas
        
        if(contador == 0){
            printf("Nenhuma turma foi criada!\n");
        }else{
            printf("Status das turmas...\n");
            imprime_turmas(turmas, contador); // Chamando a função que imprime os dados das turmas
        }
        break;

    case 7:
      
        // Limpando a memória 
        for(j = 0; j < MAX_TURMAS; j++){
            for(indice = 0; indice < MAX_VAGAS; indice++){
                free(turmas[j]->alunos[indice]);
            }
            free(turmas[j]);
        }
        //free(turmas);   Achamos que esta dando errado, pq o vetor turmas esta declarado estaticamente. Quando tentamos alocar dinamicamente, funcionou com o free(turmas) 
                          
        break;

    default:
      // Caso a não esteja entre 1 e 7, será imprimido "opcao invalida"
      if(!(opcao <= 7) || !(opcao >= 1)){
        printf("Opcao invalida!\n");
      }
        break;
    }
    }while(opcao != 7); 

    printf("\nObrigado por usar este programa!");

    return 0; 
}

// Declaração da função para criar uma turma
Turma * cria_turma(char id){
    
    Turma * turma = (Turma*) malloc(1 * sizeof(Turma));   
    if(turma == NULL)exit(1);
    turma->id = id;

    int i;
    for(i = 0; i < MAX_VAGAS; i++){
        inicializa_alunos(MAX_VAGAS, turma); // Chamando a função para inicializar aluno com NULL
    }
    
    printf("Turma %c criada com sucesso!\n", id);

    return turma;
}

// Declaração da função responsavel por listar os alunos
void listar_turmas(Turma ** turma, int contador){

    int indice;
    printf("\nListando turmas...\n");
    for(indice = 0; indice < contador; indice++){
        printf("Turma %c - %d vagas disponiveis\n", turma[indice]->id, turma[indice]->vagas);
    }
}

// Declaração da função para matrícular os alunos
void matricula_aluno(Turma* turma, int mat, char* nome){
    int indice_aluno = MAX_VAGAS - turma->vagas;

    if((indice_aluno < MAX_VAGAS)){
        turma->alunos[indice_aluno] = new_aluno(); // Chamando a função para alocar um espaçlo na memória para armazernar os dados do aluno
        strcpy(turma->alunos[indice_aluno]->nome, nome);
        turma->alunos[indice_aluno]->mat = mat;
        printf("Matricula realizada com sucesso!\n");
    }
}

// Função responsável por atualizar as vagas que tem na turma
void atualiza_vagas(Turma * turma){
    
    turma->vagas--;

}

// Função responsável por lançar as notas dos alunos
void lanca_notas(Turma* turma){
    int indice, num_notas;
    for(indice = 0; indice < MAX_VAGAS; indice++){
        if(turma->alunos[indice] != NULL){
            printf("Matricula: %d\tAluno: %s\n", turma->alunos[indice]->mat, turma->alunos[indice]->nome);
            for(num_notas = 0; num_notas < 3; num_notas++){
                printf("Digite a nota %d: ", num_notas+1);
                scanf("%f", &turma->alunos[indice]->notas[num_notas]);
            }
            turma->alunos[indice]->media = media_aluno(turma->alunos[indice]); //Função para calcular a média de cada aluno separadamente 
            IA_aluno(turma->alunos[indice]); // Chamando a função que da as possibilidades por usuário escolher qual indice acadêmico irá usar
        }else{
            indice = MAX_VAGAS+1;
        }
    }
}

// Declarando uma função que imprime os dados dos alunos na tela do usuário
void imprime_alunos(Turma* turma){
    int indice;
    int vagas_ocupadas = MAX_VAGAS - turma->vagas;
    for(indice = 0; indice < vagas_ocupadas; indice++){
        printf("Matricula: %d", turma->alunos[indice]->mat);
        printf("\nNome: %s", turma->alunos[indice]->nome);
        printf("\nMedia: %.2f", turma->alunos[indice]->media);
        printf("\nIndice academico: %.2f\n", turma->alunos[indice]->indice_academico.IG);
    }
}

// Declaração da função responsável imprimir os dados das turmas na tela
void imprime_turmas(Turma** turmas, int n){
    int indice;
    
    for(indice = 0; indice < n; indice++){
        printf("ID da turma: %c\n", turmas[indice]->id);
        printf("Alunos matriculados: %d\n", MAX_VAGAS - turmas[indice]->vagas);
        printf("Vagas na turma: %d\n", turmas[indice]->vagas);
        printf("Media da turma: %.2f\n", media_turma(turmas[indice]));
        // media_turma / função para calcular a mádia da turma 
    }
}

// Função para procurar uma turma específica
Turma* procura_turma(Turma** turmas, int n, char id){
    int indice;
    for(indice = 0; indice < n; indice++){
        if(turmas[indice]->id == n){
            return turmas[indice];        
        }
    }
    return 0;
}