#include <stdio.h>
int main(){
    int n, i, t, m, ok, s[100], p[30], q[30];
    printf("n\tshots\t2(n-2)\tguaranteed\n");
    for(n=2; n<=20; n++){
        m = 0;
        if(n == 2){ s[m++] = 1; s[m++] = 1; }
        else{
            for(i=2; i<=n-1; i++) s[m++] = i;
            for(i=n-1; i>=2; i--) s[m++] = i;
        }
        for(i=1; i<=n; i++) p[i] = 1;                // target could be anywhere
        for(t=0; t<m; t++){
            p[s[t]] = 0;                             // shot
            for(i=1; i<=n; i++)                      // target moves to an adjacent spot
                q[i] = (i > 1 && p[i-1]) || (i < n && p[i+1]);
            for(i=1; i<=n; i++) p[i] = q[i];
        }
        ok = 1;
        for(i=1; i<=n; i++) if(p[i]) ok = 0;
        printf("%d\t%d\t%d\t%d\n", n, m, 2*(n-2), ok);
    }
    return 0;
}
