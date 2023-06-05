#include <stdio.h>
#include <string.h>
int contida (char a[], char b[]){
    int tamanho_a=strlen(a), tamanho_b=strlen(b), verificador=0;
    for (int i=0, j=0; i<tamanho_a && j<tamanho_b;j++){
        verificador=0;
        if (a[i]==b[j]){
            i++;
            j=0;
            verificador=1;
        }
    }
    return verificador;
}


int main(){
    char a[20], b[20];
    printf ("Escreva uma palavra: ");
    fgets (a, 20, stdin);
    printf ("Escreva outra palavra: ");
    fgets (b, 20, stdin);
    printf ("%d\n", contida(a, b));
return 0;
}