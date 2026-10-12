#include <stdio.h>
#include <stdlib.h>
int yr;
int cmp(const void *x, const void *y){ return *(int*)x - *(int*)y; }   // used by qsort
int best(int n, int B[], int D[]){
    int b[100], d[100], i, j = 0, k, cur = 0, mx = 0;
    for(k=0; k<n; k++){ b[k] = B[k]; d[k] = D[k]; }
    qsort(b, n, sizeof(int), cmp);
    qsort(d, n, sizeof(int), cmp);
    i = 0;
    while(i < n){
        if(j < n && d[j] <= b[i]){ cur--; j++; }         // death first on a tie
        else{
            cur++;
            if(cur > mx){ mx = cur; yr = b[i]; }
            i++;
        }
    }
    return mx;
}
int main(){
    int n, i, y, c, mx, bm, by, B[100], D[100];
    int tb[3] = {1900, 1950, 1940}, td[3] = {1950, 2000, 1960};   // demo
    mx = best(3, tb, td);
    printf("demo: max %d alive from year %d\n\n", mx, yr);
    printf("n\tmax\tyear\tbrute max\tbrute year\tsame\n");
    for(n=10; n<=90; n+=20){
        for(i=0; i<n; i++){
            B[i] = 1000 + rand()%1000;
            D[i] = B[i] + 1 + rand()%80;
        }
        mx = best(n, B, D);
        bm = 0; by = 0;
        for(y=1000; y<=2100; y++){                       // brute force
            c = 0;
            for(i=0; i<n; i++) if(B[i] <= y && y < D[i]) c++;
            if(c > bm){ bm = c; by = y; }
        }
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", n, mx, yr, bm, by, mx == bm && yr == by);
    }
    return 0;
}
