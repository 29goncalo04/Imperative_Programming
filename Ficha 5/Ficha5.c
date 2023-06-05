#include <stdio.h>
typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;
//-------1--------
int nota (Aluno a){
    float final=0, soma=0;
    for (int i=0; i<6; i++){
        soma+=a.miniT[i];
    }
    soma=soma/6;
    final=a.teste*0.8+soma*2;
    if (soma<0.5) return 0;
    else {
        if (final<9.5) return 0;
    }
    else return 1;
}
//-------2--------
int procuraNum (int num, Aluno t[], int N){
    int indice = 0;
    while (N>0){
        if (t[indice].numero == num) return indice;
        else{
            indice ++;
            N--;
        }
    }
    return -1;
}
//-------3--------
void ordenaPorNum (Aluno t[], int N){
    int i = 0, j = 0;
    for (i = 0; i<N; i++){
        for (j=i; j<N; j++){
            if (t[j].numero < t[i].numero){
                Aluno temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}
//-------4--------
/*
void criaIndPorNum (Aluno t[], int N, int ind[]){
    int i = 0, j = 0;
    for (int i = 0; i<N; i++){
        ind [i] = i;
    }
    for (i = 0; i<N ; i++){
        for (j = i; j<N; j++){
            if (t[j].numero < t[i].numero){
                Aluno aux = t[i];
                t[i] = t[j];
                t[j] = aux;
                ind[i] = j;
            }
        }
    }
}*/
//-------7--------
/*
void criaIndPorNome (Aluno t [], int N, int ind[]){

}*/