#include <stdio.h>
#include <string.h>
int remRep (char x[]){
    int tamanho_x=strlen(x), contador=0;
    for (int i=0; i<tamanho_x-1; i++){
        if (x[i]!=x[i+1]) contador++;
        if (i==tamanho_x-2 && x[tamanho_x]!=x[tamanho_x-1]) contador++;
    }
return contador;
}

int main(){
    char palavra[20];
    printf ("Escreva uma palavra: ");
    scanf ("%s", palavra);
    printf ("A palavra sem letras repetidas consecutivas tem %d de comprimento.\n", remRep(palavra));
return 0;
}