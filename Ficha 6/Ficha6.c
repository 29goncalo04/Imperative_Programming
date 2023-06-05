#include <stdlib.h>
#define Max 3;

typedef struct staticStack {
    int sp;   //stack pointer que aponta sempre para o fim da stack
    int values [Max];
} STACK, *SStack;
//---------1---------
void SinitStack (SStack s){
    s->sp = 0; // OU  (*s).sp=0
}
//---------2---------
int SisEmpty (SStack s){
    return (s->sp == 0);   //se é vazia então vai retornar 1
}
//---------3---------
int Spush (SStack s, int x){
    if (s->sp < Max){
        s->values[s->sp]=x;
        s->sp += 1;
        return 0;
    }
    else return 1;
}
//---------4---------
int Spop (SStack s, int *x){
    if (s->sp > 0){
        s->sp -= 1;  //baixamos o stack pointer uma posição 
        int last_elem = s->values[s->sp];  //e o último elemento passa a ficar na posição do novo sp
        *x = last_elem;
        return 0;
    }
    else return 1;
}

int Stop (SStack s, int *x){
    if (s->sp > 0){
        *x = s->values [s->sp-1];
        return 0;
    }
    else return 1;
}



//MEMÓRIA DINÂMICA
typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

void DinitStack (DStack s){
    s->size = Max;
    s->sp = 0;
    s->values = malloc (s->size * sizeof(int));
}

int DisEmpty (DStack s){
    return (s->sp == 0);
}

int dupstack (DStack s){   //retorna 1 caso dê erro
    int *t = malloc (sizeof(int)*2 * s->size);
    if (t == NULL) return 1;
    else {
        for (int i=0; i<s->sp ; i++){
            t[i] = s->values[i]; 
        }
        free(s->values);
        s->values = t;
        s->size *= 2;
    }
}
int Dpush (DStack s, int x){
    if (s->sp == s->size){
        int d = dupStack(s);
        if (d) return 1;
    }
    s->values [(s->sp)++] = x;
    return 0;
}