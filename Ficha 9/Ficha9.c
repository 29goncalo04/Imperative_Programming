typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;


ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}


//------1(a)------
int max(int a, int b){
    if (a>=b) return a;
    return b;
}
int altura (ABin a){
    if (a==NULL) return 0;
    int esquerda = altura(a->esq);
    int direita = altura(a->dir);
    return 1 + max(esquerda, direita);
}
//------1(b)------
int nFolhas (ABin a){
    if (a==NULL) return 0;
    if (a->esq==NULL && a->dir==NULL) return 1;
    int esquerda = nFolhas(a->esq);
    int direita = nFolhas(a->dir);
    return esquerda+direita;
}
//------1(c)------
ABin maisEsquerda (ABin a){
    if (a==NULL) return NULL;
    if (a->esq==NULL) return a;
    return maisEsquerda(a->esq);
}

ABin maisEsquerda (ABin a){
    if (a==NULL) return NULL;
    while (a->esq!=NULL){
        a = a->esq;
    }
    return a;
}
//------1(d)------
void imprimeNivel (ABin a, int l){
    if (a!=NULL){
        if (l==0) printf("%d\n", a->valor);
        else{
            imprimeNivel(a->esq, l-1);
            imprimeNivel(a->dir, l-1);
        }
    }
}
//------1(e)------
int max(int a, int b){
    if (a>=b) return a;
    return b;
}
int procuraE (ABin a, int x){
    if (a!=NULL){
        if (a->valor == x) return 1;
        else return max(procuraE(a->esq, x), procuraE(a->dir, x));
    }
    return 0;
}
//------2(a)------
struct nodo *procura (ABin a, int x){
    if (a!=NULL){
        if (a->valor == x) return a;
        else{
            if(a->valor>x) return procura(a->esq, x);
            else if(a->valor<x) return procura(a->dir, x);
        }
    }
    return NULL;
}

struct nodo *procura (ABin a, int x){
    ABin res = NULL;
    if (a!=NULL){
        if (a->valor == x) res = a;
        else{
            if (x>a->valor) res = procura(a->dir, x);
            else res = procura(a->esq, x);
        }
    }
}
//------2(b)------
int nivel (ABin a, int x){
    if (a!=NULL){
        if (a->valor == x) return 1;
        if (x<a->valor && nivel(a->esq, x)!=-1) return 1+nivel (a->esq, x);
        if (x>a->valor && nivel(a->dir, x)!=-1) return 1+nivel (a->dir, x);
    }
    return -1;
}
//------2(c)------
void imprimeAte (ABin a, int x){
    if (a!=NULL){
        if (a->valor>=x) imprimeAte(a->esq, x);
        else if (a->valor<x){
            imprimeAte(a->esq, x);
            printf("%d\n", a->valor);
            imprimeAte(a->dir, x);
        } 
    }
}