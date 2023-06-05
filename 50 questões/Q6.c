#include <stdio.h>
#include <stdlib.h>
int qDig (unsigned int n){
    int valor=10, k=1;
    for (int i=1; valor<=abs(n); i++){
        valor*=10;
        k++;
    }
return k;
}

int main(){
    int numero;
    printf ("Introduza um número:");
    scanf ("%d", &numero);
    printf ("São necessárias %d casas para representar esse número.\n", qDig(numero));
return 0;    
}