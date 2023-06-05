#include <stdio.h>
void insere (int v[], int N, int x){
    for (int i=0; i<N; i++){
        if (x>v[i] && i==N-1) v[N]=x;
        if (x>v[i]) continue;
        else {for (int j=N-1; j>=i; j--){
             v[j+1]=v[j];    
             }
             v[i]=x;
             break;
        }        
    }
}
int main(){
    int v[6]={0,3,6,7};
    insere(v, 4, 2);
    for (int i=0; i<5; i++){
        printf ("%d ", v[i]);
    }
    printf ("\n");
}
// 0 1 2 3
// 1 2 4 5
// 1
// 1 2   4 5
