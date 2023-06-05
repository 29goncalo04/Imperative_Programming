#include <stdio.h>
#include <string.h>
int palindorome (char s[]){
    int tamanho_s=strlen(s);
    for (int i=0, j=tamanho_s-1; i<tamanho_s && j>=0;i++, j--){
        if (s[i]!=s[j]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char palavra[20];
    printf ("Escreva uma palavra: ");
    scanf ("%s", palavra);
    printf ("%d\n", palindorome(palavra));
return 0;
}