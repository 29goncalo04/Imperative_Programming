#include <stdio.h>
#include <string.h>
int mystrcmp(char s1[], char s2[]) {
    int tamanho_s1=strlen(s1), tamanho_s2=strlen(s2), i;
    for(i=0; i<tamanho_s1 && i<tamanho_s2; i++){
        if (s1[i]==s2[i]) continue;
        else{
            if (s1[i]<s2[i]) return -1;
            if (s1[i]>s2[i]) return 1;
        }
    }
    if (tamanho_s1<tamanho_s2) return -1;
    if (tamanho_s1>tamanho_s2) return 1;
    return 0;
}


int main(){
    char palavra1[100], palavra2[100];
    printf ("Escreva duas palavras:\n");
    scanf ("%s", palavra1);
    scanf ("%s", palavra2);
    printf ("%d\n", mystrcmp(palavra1, palavra2));
return 0;    
}