#include <stdio.h>
int f[11][1001];                       // supports E <= 10, F <= 1000
int main(){
    int E, F, e, k, x, a, b, t;
    printf("E and F: ");
    scanf("%d %d", &E, &F);
    for(k=0; k<=F; k++) f[1][k] = k;
    for(e=2; e<=E; e++){
        f[e][0] = 0;
        for(k=1; k<=F; k++){
            f[e][k] = k;               // never needs more than k drops
            for(x=1; x<=k; x++){
                a = f[e-1][x-1];       // egg breaks
                b = f[e][k-x];         // egg survives
                if(b > a) a = b;
                t = 1 + a;
                if(t < f[e][k]) f[e][k] = t;
            }
        }
    }
    printf("minimum drops = %d\n", f[E][F]);
    return 0;
}
