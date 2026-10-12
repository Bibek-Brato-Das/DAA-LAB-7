#include <stdio.h>
int main(){
    int n, i, j, c, t, on, s[20];
    long long f;
    printf("n\tmoves\tfloor(2^(n+1)/3)\n");
    for(n=1; n<=15; n++){
        for(i=0; i<n; i++) s[i] = 1;         // all on; s[0] is the rightmost switch
        c = 0;
        t = 1 - n%2;                         // 0: toggle rightmost, 1: toggle neighbour
        for(;;){
            on = 0;
            for(i=0; i<n; i++) if(s[i]) on = 1;
            if(!on) break;
            if(t == 0) s[0] = 1 - s[0];
            else{
                j = 0;
                while(!s[j]) j++;            // rightmost ON switch
                s[j+1] = 1 - s[j+1];         // its left neighbour
            }
            c++;
            t = 1 - t;
        }
        f = (1LL << (n+1)) / 3;
        printf("%d\t%d\t%lld\n", n, c, f);
    }
    return 0;
}
