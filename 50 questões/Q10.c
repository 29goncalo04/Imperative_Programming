#include <stdio.h>
#include <string.h>
char *mystrstr (char s1[], char s2[]){
    int tamanho_s1=strlen(s1),tamanho_s2=strlen(s2), j=0, posicao;
    for (int i=0; i<tamanho_s1 && j<tamanho_s2; i++){
        if (s1[i]==s2[j]){
            j++;
            posicao=i;
        }
        return posicao + s1;
    }
    return NULL;
}
/*
char *mystrstr(char s1[], char s2[]) {
  int x, y, k;

  for (x = 0; s1[x] != '\0'; x++) {

    for (y = x, k = 0; s1[y] == s2[k] && s2[k] != '\0'; y++, k++) {
    }
    if (k == strlen(s2)) {
      return s1 + x;
    }
  }
  return NULL;
}
*/
int main(){
    char palavra1[30], palavra2[30]; 
    printf ("Escreva duas palavras:\n");
    scanf ("%s", palavra1);
    scanf ("%s", palavra2);
    printf ("%s\n", mystrstr(palavra1, palavra2)); 
return 0;    
}