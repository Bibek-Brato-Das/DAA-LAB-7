#include <stdio.h>
int m[20][20], s[20][20], p[21];
void pr(int i, int j){
    if(i == j) printf("A%d", i);
    else{
        printf("(");
        pr(i, s[i][j]);
        pr(s[i][j]+1, j);
        printf(")");
    }
}
int main(){
    int n, i, j, k, l, t;
    printf("number of matrices: ");
    scanf("%d", &n);
    printf("dimensions p0 to p%d: ", n);
    for(i=0; i<=n; i++) scanf("%d", &p[i]);
    for(i=1; i<=n; i++) m[i][i] = 0;
    for(l=2; l<=n; l++)
        for(i=1; i<=n-l+1; i++){
            j = i+l-1;
            m[i][j] = 1000000000;
            for(k=i; k<j; k++){
                t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(t < m[i][j]){ m[i][j] = t; s[i][j] = k; }
            }
        }
    printf("minimum multiplications = %d\n", m[1][n]);
    printf("order: ");
    pr(1, n);
    printf("\n");
    return 0;
}
