int elimRepOrd (int v[], int N) {
int i = 0, j = i, res = 1;
if (N<1) return 0;
for (i = 0; i<N-1;){
    if (v[i]==v[i+1]){
         for (j = i; j<N-1; j++){
             v[j] = v[j+1];
         }
         N--;
    }
    else{
        res++;
        i++;
    }
}
   return res;
}