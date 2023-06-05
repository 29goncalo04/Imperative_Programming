int minInd (int v[], int n) {
   int i = 0, min = v[0], res = 0;
   for (i = 0; i<n; i++){
       if (v[i]<min){
           min = v[i];
           res = i;
       }
   }
   return res;
}