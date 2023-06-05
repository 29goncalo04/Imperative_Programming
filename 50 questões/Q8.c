#include <stdio.h>
#include <string.h>
char *mystrcpy (char *dest, char source[]){
    int tamanho_palavra=strlen(source);
    for (int i=0;i<tamanho_palavra ;i++){
        dest[i]=source[i];
    }
return dest;
}

int main(){
    char palavra_nova[200], palavra[200];
    printf ("Escreva uma palavra:\n");
    scanf ("%s", palavra);
    printf ("A palavra escrita foi: %s\n", mystrcpy(palavra_nova, palavra));
return 0;    
}