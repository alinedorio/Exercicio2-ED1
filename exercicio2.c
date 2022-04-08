#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
};

typedef struct aluno Aluno;

void imprime_aprovados (int n, Aluno** turma);
float media_turma (int n, Aluno** turma);


int main(int argc, char const *argv[])
{
    int n = 0;
    int i;
    char aux[100];
    float Media;
    
    printf("quantos alunos a turma possui? ");
    scanf("%i", &n);

    Aluno** turma = (Aluno**) malloc (n * sizeof(Aluno*));

    for(i = 0; i < n; i++){
        Aluno* aluno = (Aluno*) malloc(n * sizeof(Aluno));

        printf("\nEscreva o nome do aluno %d: ", i+1);
        scanf("\n%[^\n]", aux);
        
        printf("Escreva a matricula do Aluno %d: ", i+1);
        scanf("%d", &aluno->matricula);

        printf("Escreva a nota da P1 do Aluno %d: ", i+1);
        scanf("%f", &aluno->p1);

        printf("Escreva a nota da P2 do Aluno %d: ", i+1);
        scanf("%f", &aluno->p2);

        printf("Escreva a nota da P3 do Aluno %d: ", i+1);
        scanf("%f", &aluno->p3);

        aluno->nome = (char*)malloc((strlen(aux)+1)* sizeof(char));
        strcpy(aluno->nome, aux);

        turma[i] = aluno;

    }

    printf("\n");

    for(i = 0; i < n; i++){
        printf("aluno %i = ", i);
        printf("%s, %i, ", turma[i]->nome, turma[i]->matricula);
        printf("%.2f, %.2f, %.2f\n", turma[i]->p1, turma[i]->p2, turma[i]->p3);
    }

    printf("\n");
    
    imprime_aprovados(n, turma);
    Media = media_turma(n, turma);

    printf("\n");
    printf("a media das notas da turma eh: %.2f", Media);

    for (i = 0; i < n; i++) {
        free(turma[i]->nome);
        free(turma[i]);
    }
    free(turma);
    
    return 0;
}


void imprime_aprovados (int n, Aluno** turma){
    int i;
    float resultado;
    for(i = 0; i < n; i++){
        resultado = (turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3;
        if (resultado >= 5){
            printf("%s -> aprovado\n", turma[i]->nome);
        }
    }
}

float media_turma (int n, Aluno** turma){
    float media = 0;
    int i;
    for (i = 0; i < n; i++){
        media += (turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3;
        //printf("media parcial: %.2f", media);
    }

    media = media/n;

    return media;

}