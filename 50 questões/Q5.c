#include <stdio.h>
int trailingZ (unsigned int n) {
    int contador = 0;
    if (n==0) return 32;
    while (n>0){
       if (n%2 == 0) contador++;
       n = n/2;
    }
    return contador;
}

/*int main (){
    int numero;
    printf ("Introduza um número:");
    scanf ("%d", &numero);
    printf ("O número introduzido tem %d bits iguais a 0 no final da palavra (em representação binária).\n", trailingZ(numero));
return 0;    
}*/