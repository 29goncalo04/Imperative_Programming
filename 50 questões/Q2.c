#include <stdio.h>
int main () {
    int n, media=0, soma=0;
    printf ("Introduza uma sequência de números (um por linha) e terminada com o número 0 para calcular a respetiva média:\n");
    for (int r=1; r>0; r++){
        scanf ("%d", &n);
        if (n!=0) {
            soma+=n;
            media=soma/r;
        }
        else break;
    }
    printf ("A respetiva média é %d.\n", media);
    return 0;
}