#include <stdio.h>
void quadrado (int n){
    int i,j;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf ("#");
        }
        printf ("\n");
    }
}

void xadrez (int n){
    int i,j;
    for (i=0; i<n; i++){
        if (i%2==0){
            for (j=0; j<n; j++){
                if (j%2==0){
                    printf ("#");}
                else printf ("_");
                }
            }
        else{
            for (j=0; j<n; j++){
                if (j%2==0){
                    printf ("_");
                }
                else printf ("#");
                }
            }
            printf ("\n");
    }
}

void aux (int n){
    int i;
    for (i=0; i<n; i++){
        printf ("#");
    }
    printf ("\n");
}
void trianguloH (int n){
    int i;
    for (i=0; i<=n; i++){
        aux (i);
    }
    for (i=n-1; i>0; i--){
        aux (i);
    }
}

void aux2 (int n){
    for (int i=1; i<n; i++){
        printf (" ");
    }
}
void aux3 (int n) {
    for  (int i=0; i<((n+1)*2)-1; i++){
        printf ("#");
    }
    printf ("\n");
}
void trianguloV (int n){
    int i;
    int N=n;
    for (i=0; i<n; i++){
        aux2 (N);
        N--;
        aux3 (i);
    }
}

int main(){
    quadrado (5);  
    xadrez (5); 
    trianguloH (5);
    trianguloV (5);
}