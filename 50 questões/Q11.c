#include <stdio.h>
#include <string.h>
void strrev (char s[]){
    int tamanho_palavra=strlen(s);
    int j=tamanho_palavra-1;
    char temp;
    for (int i=0; i<j; i++){
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        j--;
    }
}

int main(){
    char palavra[100];
    printf("Escreva uma palavra:\n");
    scanf ("%s", palavra);
    strrev(palavra);
    printf ("A palavra invertida é: %s\n", palavra);
}
