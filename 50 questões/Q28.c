#include <stdio.h>
int crescente (int a[], int i, int j){
    for (int k=i; k<j; k++){
        if (a[k]>a[k+1]) return 0;
    }
    return 1;
}

int main(){
    int a[6]={0,3,2,4,4,7};
    printf ("%d\n", crescente(a, 1, 5));
return 0; 
}