#include <stdio.h>
void swapM (int *x, int *y){
int aux=*x;
*x=*y;
*y=aux;
}
//---------2--------
void swapM (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("%d %d\n", *x, *y);
}
//---------3--------
void swap (int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
//---------4--------
int soma (int v[], int N){
    int soma = 0, i = 0;
    for (i = 0; i<N; i++){
        soma+=v[i];
    }
    return soma;
}
//---------5--------
void inverteArray (int v[], int N){
    int i = 0;
    for (i = 0;N>i; N--, i++){
        int temp = v[i];
        v[i] = v[N-1];
        v[N-1] = temp;
    }
}
//---------6--------
int maximum (int v[], int N, int *m){
    if (N<=0) return 1;
    *m = v[0];
    int i = 0;
    for (i = 0; i<N-1; i++){
        if (v[i+1]>*m) *m = v[i+1];
    }
    return *m;
}
//---------7--------
void quadrados (int q[], int N){
    int i = 0;
    for (i = 0; i<N; i++){
        q[i] = q[i]*q[i];
    }
}
//---------8--------
/*void pascal (int v[], int N){
    if (N>0){
        for (int n=1; n<=N; n++){
            v[n-1]=1;
            for (int j=n-2; j>0; j--){
                v[j]+=v[j-1];
            }
        }
    }
}*/