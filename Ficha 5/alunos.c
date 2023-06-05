#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
}Aluno;

// 1 )

// 2 ) Procurar um aluno num array ordenado
int procuraNum (int num, Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        if (t[i].numero == num) {
            return i;
        }
    }
    return -1;
}

// 3) Ordenar um array de Alunos por numero de aluno
void ordenaPorNum(Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (t[i].numero < t[j].numero) {
                Aluno aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
}

// 4) 


// 5) imprime a turma em ordem númerica, alfabética e por notas
void imprimeTurma (int ind[], Aluno t[], int N){
    // ordena por numero de aluno
    ordenaPorNum(t, N);
    // ordenar por nome de aluno
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (strcmp(t[i].nome, t[j].nome) < 0) {
                Aluno aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
    // imprime a turma
    for (int i = 0; i < N; i++) {
        printf("%d %s %d %d %d %d %d %f\n", t[i].numero, t[i].nome, t[i].miniT[0], t[i].miniT[1], t[i].miniT[2], t[i].miniT[3], t[i].miniT[4], t[i].teste);
    }
    
}

int main() {
    Aluno t[] = {
         {4444, "Pedro", {2,1,0,2,2,2}, 10.5}
        ,{2222, "Luz", {2,2,2,1,0,0}, 14.5}
        ,{7777, "Rita", {2,2,2,2,2,1}, 18.5}
        ,{3333, "Bruno", {0,0,2,2,2,1}, 8.7}
    };

    int ind[] = {1, 3, 0, 2};

    imprimeTurma(ind, t, 4);



    return 0;
}