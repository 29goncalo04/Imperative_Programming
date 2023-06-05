#include <stdio.h>
void merge (int r [], int a[], int b[], int na, int nb){
    int i, j, k;
    for (i=j=k=0; i<na+nb; i++){
        if (j==na){
            r[i]=b[k];
            k++;
        }
        else if (k==nb){
            r[i]=a[j];
            j++;
        }
        else if (k!= nb && a[j]<=b[k]){
            r[i]=a[j];
            j++;
        }
        else if (j!=na && a[j]>b[k]){
            r[i]=b[k];
            k++;
        }
    }
}

int main(){
    int a[4]={1,3,5,7}, b[7]={0,1,2,5,7,8,9}, na=4, nb=7, r[11];
    merge (r, a, b, na, nb);
    for (int i=0; i<na+nb;i++){
        printf ("%d ", r[i]);
    }
    printf ("\n");
}