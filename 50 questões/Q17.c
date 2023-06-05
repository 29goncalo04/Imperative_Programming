#include <stdio.h>
#include <string.h>
int maiorPrefixo (char s1 [], char s2 []){
    int tamanho_s1=strlen(s1), tamanho_s2=strlen(s2), contador=0;
    for (int i=0; i<tamanho_s1 && i<tamanho_s2 && s1[i]==s2[i]; i++){
        contador=i+1;
    }
return contador;
}

int main(){
    char palavra1[20], palavra2[20];
    printf ("Escreva uma palavra: ");
    scanf ("%s", palavra1);
    printf ("Escreva outra palavra: ");
    scanf ("%s", palavra2);
    printf ("%d\n", maiorPrefixo(palavra1, palavra2));
}