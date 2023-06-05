#include <stdio.h>
#include <string.h>
void truncW (char t[], int n){
int tamanho_palavra=strlen(t);
    for (int i=0; i<tamanho_palavra; i++){
        if (i==0){
            for (int j=i; j<i+n; j++){
                t[j]=t[j];
            }
        }
        if (t[i]!=' ' && t[i-1]==' '){
            for (int j=i; j<i+n; j++){
                t[i]=t[j];
            }
        }
    }
}

int main(){
    char palavra[100];
    int numero;
    printf ("Escreva uma palavra:\n");
    fgets (palavra, 100, stdin);
    printf ("Escreva o número:");
    scanf ("%d", &numero);
    truncW(palavra, numero);
    printf ("%s", palavra);
return 0; 
}