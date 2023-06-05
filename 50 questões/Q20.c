#include <stdio.h>
#include <string.h>
int contaPal (char s[]){
    int tamanho_frase=strlen (s), contador=0;
    for (int i=0; s[i]!='\n'; i++){
        if (i==0 && s[i]!=' ') contador++;
        if (s[i]!=' ' && s[i-1]==' ') contador++;
    }
    return contador;
}

int main(){
    char frase[30];
    printf ("Escreva uma frase:\n");
    fgets (frase, 30, stdin);
    printf ("%d\n", contaPal(frase));
return 0;
}