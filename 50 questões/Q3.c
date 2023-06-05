#include <stdio.h>
#include <limits.h>
int main () {
    int n, maior=INT_MIN+1, maior2=INT_MIN;
    printf ("Introduza os números da sequência e terminada com o número 0:\n");
    for (int i=1; i>0; i++){
        scanf ("%d", &n);
        if (n==0) break;
        if (n>=maior) {
            maior2=maior;
            maior=n;
        }
        if (n>=maior2 && n<maior) maior2=n;
    }
    printf ("O segundo maior elemento da sequência é o: %d.\n", maior2);
    return 0;
}