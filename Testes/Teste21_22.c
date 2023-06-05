#include <stdlib.h>
#include <string.h>
//-------1-------
int nesimo (int a[], int N, int i){
    int j = 0, k = 0, res = a[0];
    for (j = 0; j<N; j++){
        for (k = j; k<N; k++){
            if(a[k]<a[j]){
                int temp = a[j];
                a[j] = a[k];
                a[k] = temp;
            }
        }
    }
    return a[i-1];
}
//-------2-------
typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

LInt removeMaiores(LInt l, int x){
    LInt atual = l;
    LInt anterior = NULL;
    while (atual!=NULL && atual->valor<=x){
        anterior = atual;
        atual = atual->prox;
    }
    anterior->prox = NULL;
    free(atual);
    atual = anterior->prox;
    return l;
}
//-------3-------
typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo *esq, *dir;
} *ABin;

LInt caminho (ABin a, int x){
    if (a!=NULL){
        if (a->valor == x){
            LInt temp = malloc(sizeof(struct LInt_nodo));
            temp->valor = x;
            temp->prox = NULL;
            return temp;
        }
        else if (a->valor!=x && a->esq==NULL && a->dir==NULL) return NULL;
        else if (x<a->valor && caminho(a->esq, x)!=NULL){
            LInt temp = malloc(sizeof(struct LInt_nodo));
            temp->valor = a->valor;
            temp->prox = caminho(a->esq, x);
            return temp;
        }
        else if (x>a->valor && caminho(a->dir, x)!=NULL){
            LInt temp = malloc(sizeof(struct LInt_nodo));
            temp->valor = a->valor;
            temp->prox = caminho(a->dir, x);
            return temp;
        }
    }
    return NULL;
}
//-------4-------
void inc (char s[]){
    int tamanho = strlen(s), i = tamanho;
    for (i = tamanho-1; i>=0; i--){
        if (s[i] == '9') s[i] = '0';
        else{
            s[i]++; 
            return;
        }
    }
    s[0] = '1';
    for (i = 1; i<=tamanho; i++){
        s[i] = '0';
    }
}
//-------5-------   (não é a resolução totalmente correta)
int sacos (int p[], int N, int C){
    int res = 0, i = 0, peso = 0;
    for (i = 0; i<N; i++){
        peso += p[i];
    }
    if (peso%C == 0) return (peso/C);
    else return (peso/C)+1;
}