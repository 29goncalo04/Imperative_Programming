#include <stdio.h>
#include <string.h>
int contaVogais (char s[]){
    int contador=0, tamanho_frase=strlen(s);
    for (int i=0; i<tamanho_frase; i++){
        if (s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
            contador++;
        }
    }
return contador;
}

int main(){
    char frase[30];
    printf ("Escreva uma frase:\n");
    fgets(frase, 30, stdin);
    printf ("Existem %d vogais nessa frase.\n", contaVogais(frase));
return 0;
}