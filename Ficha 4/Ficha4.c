#include <stdio.h>
#include <string.h>
//--------1--------
int contaVogais (char *s){
    int tamanho_s=strlen(s), contador=0;
    for (int i=0; i<tamanho_s; i++){
        if (s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
            contador++;
        }
    }
return contador;
}
//--------2--------
int retiraVogaisRep (char *s){
    int tamanho = strlen(s), i = 0, removidas = 0, j = 0;
    for (i = 0; i<tamanho;){
        if ((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') && s[i+1]==s[i]){
            removidas++;
            for (j = i+1; j<tamanho; j++){
                s[j] = s[j+1];
            }
        }
        else i++;
    }
    return removidas;
}   
//--------3--------
int duplicaVogais (char *s){
    int acrescentados = 0, i = 0, tamanho = strlen(s), j = 0;
    for (i = 0; s[i]!='\0';){
        if (s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U'){
            for (j = strlen(s) + 1; j>i; j--){
                s[j] = s[j-1];
            }
            i+=2;
            acrescentados++;
        }
        else i++;
    }
    return acrescentados;
}
//--------4--------
int ordenado (int a[], int N){
    int i = 0;
    if (N<=1) return 1;
    for (i = 0; i<N-1; i++){
        if (a[i]>a[i+1]) return 0;
    }
    return 1;
}
//--------5--------
void merge (int a[], int na, int b[], int nb, int r[]){
    int i_a=0, i_b=0;
    for (int i_r=0; i_r<na+nb; i_r++){
        if (i_a>=na){
            r[i_r]=r[i_b];
            i_b++;
        }
        else if (i_b>=nb){
            r[i_r]=r[i_a];
            i_a++;
        }
        else if (a[i_a]<=b[i_b]){
            r[i_r]=a[i_a];
            i_a++;
        }
        else {
            r[i_r]=b[i_b];
            i_b++;
        }
    }
}
//--------6--------
int partition (int v[], int N, int x){
    int aux[N], i = 0, contador = 0, j = 0;
    while (i<N){
        for (j = 0; j<N; j++){
            if (v[j]<=x){
                aux[i] = v[j];
                i++;
                contador++;
            }
        }
        for (j = 0; j<N; j++){
            if (v[j]>x){
                aux[i] = v[j];
                i++;
            }
        }
    }
    for (i = 0; i<N; i++){
        v[i] = aux[i];
    }
    return contador;
}






/*int main(){
    int questao, v[3]={1,0,3};
    char palavra[20], frase[100];
    printf ("Introduza o número da questão: ");
    scanf ("%d", &questao);
    getchar();
    if (questao==1){
        printf ("Escreva uma palavra:\n");
        scanf ("%s", palavra);
        printf ("Essa palavra tem %d vogais.\n", contaVogais(palavra));
    }
    if (questao==2){
        printf ("Escreva uma frase:\n");
        fgets (frase, 100, stdin);    ///////
        printf ("Essa frase tem %d vogais repetidas.\n", retiraVogaisRep(frase));
    }
    if (questao==3){
        printf ("Escreva uma palavra:\n");
        scanf ("%s", palavra);
        printf ("%d\n", duplicaVogais(palavra));
    }
    if (questao==4){
        printf ("%d\n", ordenado(v, 3));
    }  
return 0;
}*/