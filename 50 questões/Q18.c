#include <stdio.h>
#include <string.h>
int maiorSufixo (char s1 [], char s2 []){
    int tamanho_s1=strlen(s1), tamanho_s2=strlen(s2), contador=0;
    for (int i=tamanho_s1-1, j=tamanho_s2-1; i>=0 && j>=0; i--, j--){
        if (s1[i]==s2[j]){
            contador++;
        }
        else break;
    }
return contador;
}

int main(){
    char s1[20], s2[20];
    printf ("Escreva uma palavra: ");
    scanf ("%s", s1);
    printf ("Escreva outra palavra: ");
    scanf ("%s", s2);
    printf ("%d\n", maiorSufixo(s1, s2));
return 0;
}