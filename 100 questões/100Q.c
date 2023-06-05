#include <stdlib.h>
#include <stdio.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//---------1--------
int length (LInt l){
    int contador=0;
    while (l!=NULL){
        contador++;
        l=l->prox;
    }
    return contador;
}
//---------2---------
void freeL (LInt l){
    LInt aux;
    while (l!=NULL){
        aux=l;
        l=l->prox;
        free(aux);
    }
}
//---------3--------
void imprimeL (LInt l){
    while (l!=NULL){
        printf ("%d\n", l->valor);
        l=l->prox;
    }
}
//---------4---------    (difícil)
LInt reverseL (LInt l){
    LInt atual=l;
    LInt anterior=NULL;
    LInt proximo=NULL;
    while (atual!=NULL){              //
        proximo=atual->prox;         //não entendi nada
        atual->prox=anterior;       //
        anterior=atual;
        atual=proximo;
    }
    return anterior;
}
//---------5---------
void insertOrd (LInt * l, int valor){
    LInt novo_numero = (LInt) malloc(sizeof(LInt));      //cria um novo nó
    novo_numero->valor=valor;
    LInt atual = *l;      //"atual" é um apontador como l
    LInt anterior = NULL;
    while (atual!=NULL && valor>atual->valor){
        anterior=atual;
        atual=atual->prox;                                     
    }                                                          
    if (anterior==NULL){                                       
        novo_numero->prox=*l;
        *l=novo_numero;
    }
    else{
        novo_numero->prox=atual;
        anterior->prox=novo_numero;
    }
}
//---------6-----------
int removeOneOrd (LInt *l, int valor){
    LInt atual = *l;
    LInt anterior = NULL;
    while (atual!=NULL && atual->valor!=valor){
        anterior=atual;
        atual=atual->prox;
    }
    if (atual==NULL) return 1;
    if (anterior==NULL){
        *l=atual->prox;             //se o primeiro elemento é o que tem que ser removido então o *l (cabeça da lista) passa a ser o próximo elemento
    }else{
        anterior->prox=atual->prox;
        return 0;
    }
    free(atual);
}
//----------7---------
void merge (LInt *r, LInt a, LInt b){
    if (a==NULL){
        *r=b;                 //não entendi
    }else if (b==NULL){
        *r=a;
    }else{
        if (a->valor > b->valor){
            *r=b;
            b=b->prox;
        }else{
            *r=a;
            a=a->prox;
        }
        merge (&(*r)->prox, a, b);
    }
}
     //OU//
void merge (LInt *r, LInt a, LInt b){
    *r = NULL;
    while (a!=NULL && b!=NULL){
        if (a->valor <= b->valor){
            LInt nova = malloc(sizeof(struct lligada));
            nova->valor = a->valor;
            nova->prox = NULL;
            *r = nova;
            r = &((*r)->prox);
            a = a->prox;
        }
        else{
            LInt nova = malloc(sizeof(struct lligada));
            nova->valor = b->valor;
            nova->prox = NULL;
            *r = nova;
            r = &((*r)->prox);
            b = b->prox;
        }
    }
    if (a==NULL) *r = b;
    if (b==NULL) *r = a;
}
//----------8----------
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if (l==NULL){
        *mx=NULL;                //não esquecer desta parte em que quando a lista chegou ao fim temos de encerrar a mx e Mx
        *Mx=NULL;
    }else {if (l->valor < x){
       *mx=l;
       l=l->prox;
       splitQS (l, x, &((*mx)->prox), Mx);               //é só Mx e não *Mx
       }else {
          *Mx=l;
          l=l->prox;
          splitQS (l, x, mx, &((*Mx)->prox));
       }
    }
}
     //OU//
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while (l!=NULL){
        LInt nova = malloc(sizeof(struct lligada));
        nova->valor = l->valor;
        nova->prox = NULL;
        if (l->valor < x){
            *mx = nova;
            mx = &((*mx)->prox);
            l = l->prox;
        }
        else{
            *Mx = nova;
            Mx = &((*Mx)->prox);
            l = l->prox;
        }
    }
}
//-----------9---------- (está errada na folha)
int comprimento (LInt l){
    int x = 0;
    while (l!=NULL){
        x++;
        l = l->prox;
    }
    return x;
}


LInt parteAmeio (LInt *l){
    int comp_nova = comprimento(*l)/2;
    int i = 0;
    LInt nova = NULL;
    LInt temporaria = NULL;
    LInt atual = NULL;
    for (i=0; i<comp_nova; i++){
        temporaria = malloc(sizeof(struct lligada));
        temporaria->valor = (*l)->valor;
        *l = (*l)->prox;
        temporaria->prox = NULL;
        if (nova == NULL){
            nova = temporaria;
            atual = nova;
        }
        else{
            atual->prox = temporaria;
            atual = atual->prox;
        }
    }
    return nova;
}
//-----------10---------
int removeAll (LInt *l, int x){
    int contador=0;
    LInt anterior=NULL;
    LInt atual = *l;
    while (atual!=NULL){
        if (atual->valor == x){
            if (anterior==NULL){
                (*l)=(*l)->prox;
                atual = *l;
            }
            else{
                anterior->prox=atual->prox;
                atual = atual->prox;
            }
            contador++;
        } else{
            anterior = atual;
            atual = atual->prox;
        }
    }
    return contador;
}
//----------11---------
int removeDups (LInt *l){
    int removidos = 0;
    int valor;
    LInt atual = *l;
    LInt anterior = NULL;
    LInt auxiliar = atual;
    while (atual!=NULL){
        valor = atual->valor;
        while (auxiliar!=NULL){
            if (auxiliar->valor == valor && auxiliar!=atual){
                anterior->prox = auxiliar->prox;
                auxiliar = auxiliar->prox;
                removidos++;
            }
            else{
                anterior = auxiliar;
                auxiliar = auxiliar->prox;
            }
        }
        anterior = atual;
        atual = atual->prox;
        auxiliar = atual;
    }
    return removidos;
}
     //OU//
int removeDups (LInt *l){
    LInt atual = *l;
    LInt anterior = NULL;
    int removidos = 0;
    while (atual !=NULL){
        int rem = atual->valor;
        anterior = atual;
        atual = atual->prox;
        while(atual!=NULL){
            if (atual->valor==rem){
                anterior->prox = atual->prox;
                atual = atual->prox;
                removidos++;
            }
            else{
                anterior = atual;
                atual = atual->prox;
            }
        }
        l = &((*l)->prox);
        atual = *l;
    }
}
//----------12---------
int removeMaiorL (LInt *l){
    LInt atual=*l;
    LInt anterior=NULL;
    int maior=atual->valor;
    int aux=0;
    while (atual!=NULL){
        if (atual->valor > maior){
            maior=atual->valor;
        }
        atual=atual->prox;
    }
    while (*l!=NULL && aux==0){
        if ((*l)->valor == maior){
            if (anterior==NULL) (*l)=(*l)->prox;
            else anterior->prox=(*l)->prox;
            aux++;
        }else{
            anterior=(*l);
            l=&((*l)->prox);
        }
    }
    return maior;
}
     //OU//
int removeMaiorL (LInt *l){
    LInt atual = *l;
    LInt anterior = NULL;
    int maximo = atual->valor;
    atual = atual->prox;
    while (atual!=NULL){
        if (atual->valor > maximo){
            maximo = atual->valor;
            atual = atual->prox;
        }
        else{
            atual = atual->prox;
        }
    }
    atual = *l;
    while (atual->valor!=maximo){
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior == NULL){
        *l = (*l)->prox;
        return maximo;
    }
    else{
        anterior->prox = atual->prox;
        atual = atual->prox;
        return maximo;
    }
}
//------------13---------
void init (LInt *l){
    while (*l!=NULL){
        if ((*l)->prox == NULL){
            free (*l);                   //para evitar perdas de memória o "free" vem primeiro para
            *l=NULL;                    //libertar toda a memória e só depois é que removemos o último elemento
        }else {
            l=&((*l)->prox);
        }
    }
}
     //OU//
void init (LInt *l){
    while ((*l)->prox!=NULL){
        l = &((*l)->prox);
    }
    free(*l);
    *l = NULL;
}
//-----------14---------
void appendL (LInt *l, int valor){
    LInt nova = (LInt) malloc(sizeof(struct lligada));
    nova->valor = valor;
    nova->prox = NULL;
    LInt atual = *l;              //o atual é para percorrer a lista, logo
    if ((*l)==NULL){             //se a lista for vazia então não usamos o atual
        *l=nova;
    }
    else{
        while (atual->prox!=NULL){
            atual=atual->prox;
        }
        atual->prox = nova;
    }
}
//------------15---------
void concatL (LInt *a, LInt b){
    LInt atual = *a;
    if (*a == NULL){
        *a = b;
    }
    else{
        while (atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = b;
    }
}
//-----------16---------
LInt cloneL (LInt l){
    LInt nova = NULL;
    LINt anterior = NULL;
    while (l!=NULL){
        nova = (LInt) malloc(sizeof(struct lligada));
        nova->valor = l->valor;
        novo->prox = NULL;
        if (anterior==NULL) anterior = nova;
        else anterior->prox = nova;
        anterior=nova;
        l=l->prox;
    }
    return anterior;
}
    //OU//
LInt cloneL (LInt l){
    LInt nova = NULL;
    LInt atual = nova;
    while (l!=NULL){
        LInt temporaria = malloc(sizeof(struct lligada));
        temporaria->valor = l->valor;
        temporaria->prox = NULL;
        if (nova==NULL){
            nova = temporaria;
            atual = nova;
        }
        else{
            atual->prox = temporaria;
            atual = atual->prox;
        }
        l = l->prox;
    }
    return nova;
}
//-----------17---------
LInt cloneRev (LInt l){
    LInt nova = NULL;
    LInt atual = l;
    while (atual!=NULL){
        LInt auxiliar = malloc(sizeof(struct lligada));
        auxiliar->valor = atual->valor;
        auxiliar->prox = nova;
        nova = auxiliar;
        atual = atual->prox;
    }
    return nova;
}
//----------18----------
int maximo (LInt l){
    int max=l->valor;
    while (l!=NULL){
        if (l->valor > max) max=l->valor;
        l=l->prox;
    }
    return max;
}
//---------19----------
void freeLista (LInt l){
    LInt temporaria;
    while (l!=NULL){
        temporaria = l;
        l=l->prox;
        free(temporaria);
    }
}

int take (int n, LInt *l){
    int comprimento = 0;
    LInt atual=*l;
    while (comprimento!=(n-1) && atual!=NULL){
        atual=atual->prox;
        comprimento++;
    }
    if (atual==NULL) return comprimento;
    else{
        freeLista (atual->prox);
        atual->prox = NULL;
        comprimento++;
        return comprimento;
    }
}
       //OU
int take (int n, LInt *l){
    int res = 0;
    while (n>0 && *l!=NULL){
        l = &((*l)->prox);
        n--;
        res++;
    }
    while (*l!=NULL){
        LInt atual = *l;
        atual = atual->prox;
        free(*l);
        *l = atual;
    }
    return res;
}
//----------20----------
void free_lista (LInt l, LInt atual){
    LInt aux;
    while (l!=atual){
        aux = l;
        l=l->prox;
        free(aux);
    }
}

int drop (int n, LInt *l){
    LInt atual = *l;
    int removidos = 0;
    while (removidos<n && atual!=NULL){
        atual = atual->prox;
        removidos++;
    }
    free_lista(*l, atual);
    *l=atual;
    return removidos;
}
     //OU//
int drop (int n, LInt *l){
    int removidos = 0;
    LInt atual = *l;
    while (atual!=NULL && n>0){
        n--;
        removidos++;
        atual = atual->prox;
        free(*l);
        *l = atual;
    }
    return removidos;
}
//----------21---------
LInt NForward (LInt l, int N){
    LInt atual = l;
    while (N>0){
        N--;
        atual = atual->prox;
    }
    return atual;
}
//----------22---------
int listToArray (LInt l, int v[], int N){
    for (int i=0; i<N && l!=NULL; i++){
        v[i] = l->valor;
        l = l->prox;
    }
    return i;
}
     //OU//
int listToArray (LInt l, int v[], int N){
    int contador = 0;
    while (contador<N && l!=NULL){
        contador++;
        *v = l->valor;
        v++;
        l = l->prox;
    }
    return contador;
}
//---------23----------
LInt arrayToList (int v[], int N){
    LInt nova = NULL;
    LInt atual = nova;
    while (N>0){
        N--;
        LInt aux = malloc(sizeof(struct lligada));
        aux->valor = *v;
        aux->prox = NULL;
        v++;
        if (nova == NULL){
            nova = aux;
            atual = nova;
        }
        else{
            atual->prox = aux;
            atual = atual->prox;
        }
    }
    return nova;
}
//---------24----------   (não entendi)
LInt somasAcL (LInt l){
    LInt nova = NULL;
    LInt atual = l;
    LInt atual2 = nova;
    int soma = 0;
    while (atual!=NULL){
        LInt temporaria = malloc(sizeof(struct lligada));
        soma+=atual->valor;
        temporaria->valor = soma;
        temporaria->prox = NULL;
        if (nova == NULL){
            nova = temporaria;
            atual2 = nova;
        }
        else{
            atual2->prox = temporaria;
            atual2 = atual2->prox;
        }
        atual = atual->prox;
    }    
    return nova;
}
//---------25----------
void remreps (LInt l){
    LInt anterior = NULL;
    LInt atual = l;
    while (atual!=NULL){
        if (anterior!=NULL && atual->valor == anterior->valor){
            anterior->prox = atual->prox;
            free(atual);
            atual = anterior->prox;
        }
        else{
            anterior = atual;
            atual = atual->prox;
        }
    }
}
//---------26---------    (não podia fazer malloc)
LInt rotateL (LInt l){
    if (l == NULL || l->prox == NULL) return l;
    LInt atual = l;
    LInt nova = NULL;
    int valor = l->valor;
    while (atual->prox != NULL){
        atual = atual->prox;
    }
    nova = malloc(sizeof(struct lligada));
    nova->valor = valor;
    nova->prox = NULL;
    atual->prox = nova;
    l = l->prox;
    return l;
}
//---------27---------
LInt parte (LInt l){
    LInt atual = l;
    LInt anterior = NULL;
    LInt nova = NULL;
    LInt atual2 = nova;
    while (atual!=NULL){
        if (atual->valor%2==1){
            anterior = atual;
            atual = atual->prox;
        }
        else{
            LInt temp = malloc(sizeof(struct lligada));
            temp->valor = atual->valor;
            temp->prox = NULL;
            if (nova == NULL){
                nova = temp;
                atual2 = nova;
            }
            else if (nova!=NULL){
                atual2->prox = temp;
                atual2 = atual2->prox;
            }
            if (anterior == NULL){
                l = l->prox;
                atual = l;
                anterior = atual;
            }
            else if (anterior!=NULL){
                anterior->prox = atual->prox;
                atual = anterior->prox;
            }
        }
    }
    return nova;
}
//-----------------------------------------------------------------------//
//--------28--------
int max(int a, int b){
    if (a>=b) return a;
    else return b;
}
int altura (ABin a){
    int resultado = 0;
    if (a!=NULL){
        resultado = 1+max(altura(a->esq), altura(a->dir));
    }
    return resultado;
}
      //OU//
int altura (ABin a){
    if (a!=NULL){
        return 1 + max(altura(a->esq), altura(a->dir));
    }
	return 0;
}
//--------29---------
ABin cloneAB (ABin a){
    ABin nova = NULL;
    if (a!=NULL){
        nova = malloc(sizeof(struct nodo));
        nova->valor = a->valor;
        nova->esq = cloneAB (a->esq);
        nova->dir = cloneAB (a->dir);
    }
    return nova;
}
     //OU//
ABin cloneAB (ABin a) {
    if (a!=NULL){
        ABin nova = malloc(sizeof (struct nodo));
        nova->valor = a->valor;
        nova->esq = cloneAB (a->esq);
        nova->dir = cloneAB (a->dir);
        return nova;
    }
    return NULL;
}
//-------30---------
void mirror (ABin *a){
    ABin temp = NULL;
    if (*a!=NULL){
        temp = (*a)->esq;      //é necessário criar uma variável para guardar um lado da árvore
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror (&((*a)->esq));
        mirror (&((*a)->dir));
    }
}
      //OU//
void mirror (ABin *a) {
    if (*a!=NULL){
        ABin temporaria = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temporaria;
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
    }
}
//-------31---------  ->esquerda-raíz-direita
void inorder2 (ABin a, LInt *l){
    if (a!=NULL){
        inorder2 (a->dir, l);
        LInt nova = malloc(sizeof(struct lligada));
        nova->valor = a->valor;
        nova->prox = *l;
        *l = nova;
        inorder2 (a->esq, l);
    }
}

void inorder (ABin a, LInt *l){
    *l = NULL;
    inorder2 (a, l);
}
//-------32-------- ->raíz-esquerda-direita
void preorder2 (ABin a, LInt *l){
    if (a!=NULL){
        preorder2 (a->dir, l);
        preorder2 (a->esq, l);
        LInt nova = malloc(sizeof(struct lligada));
        nova->valor = a->valor;
        nova->prox = *l;
        *l = nova;
    }
}

void preorder (ABin a, LInt *l){
    *l = NULL;
    preorder2 (a, l);
}
//-------33-------    ->esquerda-direita-raíz
void posorder2 (ABin a, LInt *l){
    if (a!=NULL){
        LInt nova = malloc(sizeof(struct lligada));
        nova->valor = a->valor;
        nova->prox = *l;
        *l = nova;
        posorder2 (a->dir, l);
        posorder2 (a->esq, l);
    }
}

void posorder (ABin a, LInt *l){
    *l = NULL;
    posorder2 (a, l);
}
//-------34------ (não entendi)
int min (int a, int b){
    if (a<=b) return a;
    else return b;
}

int depth (ABin a, int x){       //podemos fazer só "if" porque ao fim de cada um ele dá return
    if (a==NULL) return -1;
    if (a->valor == x) return 1;
    int esquerda = depth (a->esq, x);
    int direita = depth (a->dir, x);
    if (esquerda==-1 && direita==-1) return -1;
    if (esquerda==-1) return direita+1;
    if (direita==-1) return esquerda+1;
    else return 1+min(esquerda, direita);
}
//-------35-------
int freeAB (ABin a){
    int libertados = 0;
    if (a!=NULL){
        int esquerda = freeAB(a->esq);
        int direita = freeAB(a->dir);
        free(a);
        libertados = 1+direita+esquerda;
    }
    return libertados;
}
      //OU//
int freeAB (ABin a){
    if (a!=NULL){
        int esquerda = freeAB (a->esq);
        int direita = freeAB (a->dir);
        free(a);
        return 1+esquerda+direita;
    }
    return 0;
}
//-------36-------
int pruneAB (ABin *a, int l){ 
    int removidos = 0;              //nas árvores já não posso usar um novo apontador para percorrer a árvore, porque estamos a usar recursividade
    if (*a!=NULL){
        if (l==0){
            int esquerda = pruneAB (&((*a)->esq), l);
            int direita = pruneAB (&((*a)->dir), l);
            free (*a);
            *a = NULL;
            removidos = 1 + esquerda + direita;
        }
        else{
            int esquerda2 = pruneAB (&((*a)->esq), l-1);
            int direita2 = pruneAB (&((*a)->dir), l-1);
            removidos = esquerda2 + direita2;
        }
    }
    return removidos;
}
     //OU//
int pruneAB (ABin *a, int l){
    if (*a!=NULL){
        if (l==0){
            int esquerda = pruneAB (&((*a)->esq), l);
            int direita = pruneAB (&((*a)->dir), l);
            free (*a);
            *a = NULL;                 //não esquecer
            return 1 + esquerda + direita;
        }
        else{
            return pruneAB (&((*a)->dir), l-1) + pruneAB (&((*a)->esq), l-1);
        }
    }
    return 0;
}
//-------37------
int min (int a, int b){
    if (a<=b) return a;
    else return b;
}

int iguaisAB (ABin a, ABin b){
    int resultado = 1;
    if ((a!=NULL && b==NULL) || (a==NULL && b!=NULL)) return 0;
    if (a!=NULL && b!=NULL){
        if (a->valor == b->valor){
            resultado = 1;
            int esquerda = iguaisAB (a->esq, b->esq);
            int direita = iguaisAB (a->dir, b->dir);
            return resultado = min (esquerda, direita);
        }
        else return 0;
    }
    return resultado;
}
     //OU//
int iguaisAB (ABin a, ABin b) {
    if (a==NULL && b!=NULL) return 0;
    if (a!=NULL && b==NULL) return 0;
    if (a==NULL && b==NULL) return 1;
    if (a!=NULL && b!=NULL){
        if (a->valor != b->valor) return 0;
        else return min (iguaisAB(a->esq, b->esq), iguaisAB(a->dir, b->dir));
    }
}
//--------38------  (difícil)
LInt junta (LInt esquerda, LInt direita){
    LInt atual = esquerda;
    if (atual == NULL) return direita;
    while (atual->prox!=NULL){
        atual = atual->prox;
    }
    atual->prox = direita;
    return esquerda;
}

LInt nivelL (ABin a, int n){
    if (a==NULL || n<1) return NULL;
    if (n==1){
        LInt nova = malloc(sizeof(struct lligada));
        nova->valor = a->valor;
        nova->prox = NULL; 
    }
    else{
        LInt esquerda = nivelL (a->esq, n-1);
        LInt direita = nivelL (a->dir, n-1);
        return junta(esquerda, direita);
    }
}
//---------39--------
int nivelV (ABin a, int n, int v[]){
    if (a==NULL || n<1) return 0;
    if (n==1){
        *v = a->valor;
        return 1;                
    }
    else{
        int esquerda = nivelV (a->esq, n-1, v);
        int direita = nivelV (a->dir, n-1, v+esquerda);
        return esquerda+direita;
    }
}
//--------40-------  (não entendi)
/*
int dumpAbin (ABin a, int v[], int N){
    if (N>0 && a!=NULL){
        dumpAbin (a->esq, v, N-1);
        *v = a->valor;
        v++;
        dumpAbin (a->dir, v+esquerda, N-1);
        return 1+esquerda+direita;
    }
}
*/
//-------41--------
ABin somasAcA (ABin a){
    if (a!=NULL){
        ABin nova = malloc(sizeof(struct nodo));
        nova->esq = somasAcA (a->esq);
        nova->dir = somasAcA (a->dir);
        if (nova->esq == NULL && nova->dir == NULL){
            nova->valor = a->valor;
        }
        else if (nova->esq == NULL) nova->valor = a->valor + nova->dir->valor;
        else if (nova->dir == NULL) nova->valor = a->valor + nova->esq->valor
        else{
            nova->valor = a->valor + nova->esq->valor + nova->dir->valor;
        }
        return nova;
    }
    return NULL;
}
   //OU//
ABin somasAcA (ABin a) {
    if (a==NULL) return NULL;
    ABin nova = malloc(sizeof(struct nodo));
    if (a->esq==NULL && a->dir==NULL) nova->valor = a->valor;
    else if (a->esq == NULL) nova->valor = a->valor + somasAcA(a->dir)->valor;
    else if (a->dir == NULL) nova->valor = a->valor + somasAcA(a->esq)->valor;
    else nova->valor = a->valor + somasAcA(a->esq)->valor + somasAcA(a->dir)->valor;
    nova->esq = somasAcA(a->esq);
    nova->dir = somasAcA(a->dir);
    return nova;
}
//-------42--------
int contaFolhas (ABin a){
    if (a!=NULL){
        if (a->esq == NULL && a->dir == NULL){
            return 1;
        }
        else{
            return contaFolhas (a->esq) + contaFolhas (a->dir);
        }
    }
}
    //OU//
int contaFolhas (ABin a) {
    if (a==NULL) return 0;
    if (a->esq == NULL && a->dir == NULL) return 1;
    return contaFolhas(a->esq) + contaFolhas(a->dir);
}
//-------43--------
ABin cloneMirror (ABin a){
    if (a!=NULL){
        ABin esquerda = cloneMirror (a->esq);
        ABin direita = cloneMirror (a->dir);
        ABin nova = malloc(sizeof(struct nodo));
        nova->valor = a->valor;
        nova->esq = direita;
        nova->dir = esquerda;
        return nova;
    }
}
   //OU//
ABin cloneMirror (ABin a) {
    if (a!=NULL){
        ABin temporaria = malloc(sizeof(struct nodo));
        temporaria->valor = a->valor;
        temporaria->esq = cloneMirror (a->dir);
        temporaria->dir = cloneMirror (a->esq);
        return temporaria;
    }
    return NULL;
}
//-------44--------
int addOrd (ABin *a, int x){
    ABin nova = malloc(sizeof(struct nodo));
    nova->valor = x;
    nova->esq = NULL;
    nova->dir = NULL;
    while (*a!=NULL){
        if ((*a)->valor == x) return 1;
        if ((*a)->valor < x){
            a = &((*a)->dir);
        }
        else if ((*a)->valor > x){
            a = &((*a)->esq);
        }
    }
    *a = nova;
    return 0;
}
    //OU//
int addOrd (ABin *a, int x) {
    if (*a!=NULL){
        if (x<(*a)->valor) return addOrd (&((*a)->esq), x);
        if (x>(*a)->valor) return addOrd (&((*a)->dir), x);
        if (x == (*a)->valor) return 1;
    }
    if (*a==NULL){
        ABin nova = malloc(sizeof(struct nodo));
        nova->valor = x;
        nova->esq = NULL;
        nova->dir = NULL;
        *a = nova;
        return 0;
    }
}
//-------45------
int lookupAB (ABin a, int x){
    while (a!=NULL){
        if (a->valor == x) return 1;
        if (x < a->valor) a = a->esq;
        else a = a->dir;
    }
    return 0;
}
   //OU//
int lookupAB (ABin a, int x) {
    if (a==NULL) return 0;
    if (a!=NULL){
        if (a->valor == x) return 1;
        if (x<a->valor) return lookupAB (a->esq, x);
        if (x>a->valor) return lookupAB (a->dir, x);
    }
}
//-------46------
int depthOrd (ABin a, int x) {
    if (a==NULL) return -1;
    if (a!=NULL){
        if (a->valor == x) return 1;
        if (x<a->valor && depthOrd(a->esq, x)!=-1) return 1+depthOrd(a->esq, x);
        if (x>a->valor && depthOrd(a->dir, x)!=-1) return 1+depthOrd(a->dir, x);
        return -1;
    }
}
//-------47-------
int maiorAB (ABin a) {
    while (a->dir!=NULL){
        a = a->dir;
    }
    return a->valor;
}
//------48-------
void removeMaiorA (ABin *a){
    if ((*a)!=NULL){
        if ((*a)->dir!=NULL){
            removeMaiorA (&((*a)->dir));
        }
        else{
            ABin temporaria = (*a)->esq;
            free (*a);
            *a = temporaria; 
        }
    }
}
//------49-------
int quantosMaiores (ABin a, int x){
    if (a!=NULL){
        if (x >= a->valor){
            return quantosMaiores (a->dir, x);
        }
        else{
            return 1 + quantosMaiores (a->esq, x) + quantosMaiores (a->dir, x);
        }
    }
}
//------50------     (criei uma árvore muito simples)
void listToBTree (LInt l, ABin *a){
    if (l!=NULL){
        ABin nova = malloc(sizeof(struct nodo));
        nova->valor = l->valor;
        nova->esq = NULL;
        nova->dir = NULL;
        *a = nova;
        a = &((*a)->dir);
        l = l->prox;
        listToBTree (l, a);
    }
}
//------51------
/*
int min (int a, int b){
    if (a<=b) return a;
    return b;
}

int deProcura (ABin a){
    int res = 0;
    if (a!=NULL){
        if (a->esq->valor<a->valor && a->dir->valor>a->valor){
            res = 1;
        }
        else res = 0;
        return min (deProcura(a->esq), deProcura(a->dir));
    }
}
*/