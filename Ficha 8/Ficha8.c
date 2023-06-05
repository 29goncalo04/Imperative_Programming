typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;


LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}


typedef LInt Stack;       //pode-se usar LInt ou Stack


//-----1------
void initStack (Stack *s){     //para inicializar uma stack
    *s = NULL;       //inicialmente o apontador não aponta para nada
}

int SisEmpty (Stack s){      //verificar se a stack é nula (vazia)
    if (s==NULL) return 1;
    return 0;
}

int push (Stack *s, int x){    //adicionar um novo elemento no início da stack
    Stack novo = newLInt (x, *s);
    if (novo==NULL) return 1;
    *s = novo;
    return 0;
}

int pop (Stack *s, int *x){   //remover o primeiro elemento
    if (*s == NULL) return 1;    //não há nada a remover
    *x = (*s)->valor;
    Stack aux = (*s)->prox;
    free(*s);
    *s = aux;
    return 0;
}

//-----2-----
typedef struct {
    LInt inicio,fim;
} Queue;

void initQueue (Queue *q){
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty (Queue q){
    if (q.inicio == NULL) return 1;
    return 0;
}

int enqueue (Queue *q, int x){     //colocar um elemento no final
    LInt nova = newLInt (x, NULL);
    if (nova == NULL) return 1;
    if (QisEmpty (*q)){
        q->inicio = nova;
        q->fim = nova;
    }
    else{
        q->fim->prox = nova;
        q->fim = nova;
    }
    return 0;
}

int dequeue (Queue *q, int *x){   //remove o primeiro 
    if (QisEmpty(*q)) return 1;
    *x = q->inicio->valor;
    LInt aux = q->inicio->prox;
    free (q->inicio);
    q->inicio = aux;
    if (QisEmpty(*q)) q->fim = NULL;
    return 0;
}

int front (Queue q, int *x){
    if (QisEmpty(q)) return 1;
    *x = (q.inicio)->valor;
    return 0;
}