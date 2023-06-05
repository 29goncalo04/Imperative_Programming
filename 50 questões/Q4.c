#include <stdio.h>
int bitsUm (unsigned int n){
int resto=0;    
    while (n!=0){
        if (n%2==1) resto++;
        n=n/2;
    }
return resto;
}

int main (){
    int numero;
    printf("Introduza um número:");
    scanf ("%d", &numero);
    printf ("O número de bits iguais a 1 que se encontram na representação binária do número escrito é:%d\n", bitsUm(numero));
    return 0;
}