#include <stdio.h>
#include <string.h>
char *mystrcat(char s1[], char s2[]) {
    int tamanho_s1 = strlen(s1), tamanho_s2 = strlen(s2), i = 0, j = 0;
    for (i = tamanho_s1; i<=tamanho_s1+tamanho_s2; i++, j++){
        if (i == tamanho_s1 + tamanho_s2) s1[i] = '\0';
        else s1[i] =  s2[j];
    }
    return s1;
}


int main(){
char palavra1[100], palavra2[100];
    printf ("Escreva duas palavras, uma em cada linha:\n");
    scanf ("%s", palavra1);
    scanf ("%s", palavra2);
    printf ("Ao juntar as duas palavras, a palavra final é: %s\n", mystrcat(palavra1, palavra2));
return 0;    
}