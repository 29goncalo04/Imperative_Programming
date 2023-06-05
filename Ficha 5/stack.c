#include <stdio.h>

#define Max 1000

struct staticStack {
	int sp;
	int values [Max];
};

typedef struct staticStack * SStack;

void SinitStack(SStack s) {
    s->sp = 0;
    // (*s).sp = 0;
}

int SisEmpty (SStack s) {
    return s->sp == 0;
}

int Spush (SStack s, int x) {
    if(s->sp < Max) {
        s->values[s->sp] = x;
        s->sp++;
        return 0;
    }
    else {
        return 1;
    }
}

void imprimeStack(SStack s) {
    printf("+-----+\n");
    for(int i = s->sp - 1; i >= 0; i--)
        printf("| %3d |\n", s->values[i]);
    printf("+-----+\n");
}