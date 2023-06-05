#include <stdio.h>
int menosFreq (int v[], int N){
    int resposta=v[0], frequencia=0;
    for (int i=0; i<N; i++){
        if(v[i]<v[i+1]){
            resposta=v[i];
            frequencia++;
        }
        if(v[i]==v[i+1]){
            frequencia++;
        }
    }
}