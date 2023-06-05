#include <stdio.h>
#include <string.h>
int iguaisConsecutivos (char s[]){
    int tamanho_palavra=strlen(s), contador=0, contador_max=0;
    for (int i=0; i<tamanho_palavra-1; i++){
        if (s[i]==s[i+1]){
            if (contador==0) contador=1;
            contador++;
        }
        if (contador>contador_max) contador_max=contador;
        if (s[i]!=s[i+1]) contador=1;
    }
    return contador_max;
}

int main(){
    char palavra[20];
    printf ("Escreva uma palavra:\n");
    scanf ("%s", palavra);
    printf ("%d\n", iguaisConsecutivos(palavra));
return 0;
}