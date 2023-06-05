#include <stdio.h>
#include <string.h>
int sufPref (char s1[], char s2[]){
    int tamanho_s1=strlen(s1), tamanho_s2=strlen(s2), contador=0;
    for (int i=0; i<tamanho_s1; i++){
        if (s1[i]==s2[contador]) contador++;
        else contador=0;
    }
return contador;
}

int main(){
    char s1[20], s2[20];
    printf ("Escreva uma palavra: ");
    scanf ("%s", s1);
    printf ("Escreva outra palavra: ");
    scanf ("%s", s2);
    printf ("%d\n", sufPref(s1, s2));
return 0;
}