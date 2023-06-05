#include <stdio.h>
#include <string.h>
void strnoV (char s[]){
    int tamanho_s=strlen(s), i, j;
    for (i=0; i<tamanho_s; i++){
        if (s[i]!='a' && s[i]!='A' && s[i]!='e' && s[i]!='E' && s[i]!='i' && s[i]!='I' && s[i]!='o' && s[i]!='O' && s[i]!='u' && s[i]!='U') continue;
        else{
            for (j=i; j<tamanho_s; j++){
                s[j]=s[j+1];
            }
            tamanho_s--;
        }
    }
}

int main(){
    char palavra[100];
    printf("Escreva uma palavra:\n");
    scanf ("%s", palavra);
    strnoV (palavra);
    printf ("A palavra sem vogais é: %s\n", palavra);
}