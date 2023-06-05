#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;               
} * Palavras;                        
//-------1-------/                    
void libertaLista (Palavras l){
    Palavras aux = NULL;
    while (l!=NULL){
        aux = l->prox;
        free(l->palavra);
        free(l);
        l = aux;
    }
}
//---------2-------//
int quantasP (Palavras l){
    int res = 0;
    while (l!=NULL){
        res++;
        l = l->prox;
    }
    return res;
}
//---------3--------//
void listaPal (Palavras l){
    while (l!=NULL){
        printf("%s, %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}
//---------4---------//
char * ultima (Palavras l){
    if (l!=NULL){
        while (l->prox != NULL){
            l = l->prox;
        }
        return l->palavra;
    }
    return NULL;
}
//----------5---------//
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras nova = malloc(sizeof (struct celula));
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = l;
    if (l==NULL) return nova;
    l = nova;
    return l;
}

//---------6---------//
Palavras acrescentaFim (Palavras l, char *p){
    Palavras nova = malloc(sizeof(struct celula));
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = NULL;
    Palavras atual = l;
    if (l == NULL) return nova;
    while (atual->prox != NULL){
        atual = atual->prox;
    }
    atual->prox = nova;
    return l;    
}
//---------7---------//
Palavras acrescenta (Palavras l, char *p){
    Palavras aux = l;
    while (aux!=NULL && aux->palavra!=p){
        aux = aux->prox;
    }
    if (aux==NULL){
        Palavras nova = malloc(sizeof(struct celula));
        nova->palavra = p;
        nova->ocorr = 1;
        nova->prox = l;
        l = nova;
        return l;
    }
    else{
        aux->ocorr ++;
        return l;
    }
}
//---------8---------//
struct celula * maisFreq (Palavras l){
    if (l==NULL) return NULL;
    Palavras max = l;
    while (l!=NULL){
        if (l->ocorr > max->ocorr){
            max = l;
        }
        l = l->prox;
    } 
    return max;
}