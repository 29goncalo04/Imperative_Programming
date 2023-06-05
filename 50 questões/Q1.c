#include <stdio.h>
#include <limits.h>
int main () {
    int N=1, maior=INT_MIN;
    printf ("Digite uma sequência de números inteiros com um por linha (0 para terminar):\n");
    while (N!=0) {
        scanf ("%d", &N);
        if ((N>maior)&&(N!=0)){
            maior=N;
        }
    }
    printf ("O maior elemento da sequência é %d.\n", maior);
    return 0;
}