#include <stdio.h>
#include <string.h>
#include <string.h>
char charMaisfreq (char s[]) {
    int tamanho_s=strlen(s), contador=0, max=0, i, j;
    char maior;
    for (i=0; i<tamanho_s; i++){
        contador=0;
        for (j=i; j<tamanho_s; j++){
            if (s[j]==s[i]) contador++;
        }
        if (contador>max){
            maior=s[i];
            max=contador;
        }
    }
    return maior;
}
int main(){
    char palavra[20];
    printf ("Escreva uma palavra:\n");
    scanf ("%s", palavra);
    printf ("%c\n", charMaisfreq(palavra));
return 0;
}