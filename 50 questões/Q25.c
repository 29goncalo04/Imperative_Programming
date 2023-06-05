#include <stdio.h>
#include <string.h>
int limpaEspacos (char t[]){
    int tamanho_palavra=strlen(t), contador=0;
    for (int i=0; i<tamanho_palavra-1; i++){
        if (i==tamanho_palavra-1 && t[i]!=' ') contador++;
        if (t[i]==' ' && t[i+1]==' ') contador=contador; 
        else contador++;
    }
return contador;
}

int main(){
    char palavra[50];
    printf ("Escreva uma frase:\n");
    fgets(palavra, 50, stdin);
    printf ("Essa frase sem espaços repetidos tem %d de comprimento.\n", limpaEspacos(palavra));
}