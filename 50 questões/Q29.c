#include <stdio.h>
int retiraNeg (int v[], int N){
    int res = 0, i = 0, j = i;
    for (i = 0; i<N;){
        if (v[i]<0){
            for (j = i; j<N; j++){
                v[j] = v[j+1];
            }
            N--;
        }
        else{
            res++;
            i++;
        }
    }
    return res;
}