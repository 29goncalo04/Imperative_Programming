#include <stdio.h>
float multInt1 (int n, float m) {
    float r=0;
    for (int i=0; i<=n; i++){
        r=i*m;
    }
    return r;
}

float multInt2 (int n, float m){
    float impares=0;
    int i=1;
    while (n>0){
        if (n!=1) i++;
        if (n%2!=0){
            impares+=m;
        }        
        n=n/2;
        m=m*2;
    }
    printf ("%d operações entre floats.\n", i);
    return impares;
}

int mdc1 (int a, int b){
    int mdc=1;
    int i;
    if (a<b){
        for (i=1; i<=a; i++){
            if (a%i==0 && b%i==0) mdc=i;
        }
    }
    else {
        for (i=1; i<=b; i++){
            if (a%i==0 && b%i==0) mdc=i;
        }
    }
    return mdc;
}

int mdc2 (int a, int b){
    int mdc2, iteracoes=0;
    for (int i=0; a>0 && b>0; i++){    
        if (a>b) {
            a=a-b;
            iteracoes++;
        } 
        if (b>=a) {
            b=b-a;
            iteracoes++;
        }
    }
    if (a>b) mdc2=a;
    if (b>a) mdc2=b;
    printf ("Foram realizadas %d iterações.\n", iteracoes);
    return mdc2;
}

int AE (int a, int b){
    int mdc;
    for (int i=0; a>0 && b>0; i++){    
        if (a>b) {
            a=a%b;
        } 
        else b=b%a;
    }
    if (a>b) mdc=a;
    if (b>a) mdc=b;
    return mdc;
}

int fib1 (int n){
    int fib;
    if (n==0) fib=0;
    if (n==1) fib=1;
    if (n>=2){
        fib=fib1 (n-1) + fib1 (n-2);
    }
    return fib;
}

float main () {
    int a, b, d;
    float c;
    char e;
    printf ("Introduza o número da pergunta que deseja:");
    scanf ("%d", &a);
    if (a==1) {
        printf ("Introduza os dois números a multiplicar (separados por um espaço):");
        scanf ("%d %f", &b, &c);
        printf ("%f\n", multInt1 (b, c));
    }
    if (a==2) {
        printf ("Introduza os dois números a multiplicar (separados por um espaço):");
        scanf ("%d %f", &b, &c);
        printf ("%f\n", multInt2 (b, c));
    }
    if (a==3) {
        printf ("Introduza os dois números que quer verificar qual é o seu maior divisor comum (separados por um espaço):");
        scanf ("%d %d", &b, &d);
        printf ("%d\n", mdc1 (b, d));
    }
    if (a==4) {
        printf ("Introduza os dois números que quer verificar qual é o seu maior divisor comum (separados por um espaço):");
        scanf ("%d %d", &b, &d);
        printf ("%d\n", mdc2 (b, d));
    }
    if (a==5) {
        printf ("Introduza os dois números que quer verificar qual é o seu maior divisor comum (separados por um espaço):");
        scanf ("%d %d", &b, &d);
        printf ("%d\n", AE (b, d));
    }
    if (a==6) {
        printf ("Qual alínea?\n");
        scanf (" %c", &e);
        if (e=='a'){
            printf ("Introduza o número do termo da sequência de Fibonacci que quer encontrar:");
            scanf ("%d", &b);
            printf ("%d\n", fib1 (b));
        }
    }
    return 0;
}