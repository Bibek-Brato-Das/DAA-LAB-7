#include <stdio.h>
int st[4][20], top[4], c, bad, R[20], K[20];
void mv(int a, int b){                      // move top disk of peg a to peg b
    int d = st[a][--top[a]];
    if(top[b] > 0 && st[b][top[b]-1] < d) bad = 1;   // larger on smaller
    st[b][top[b]++] = d;
    c++;
}
void h3(int n, int a, int b, int v){        // normal Hanoi, 3 pegs
    if(n == 0) return;
    h3(n-1, a, v, b);
    mv(a, b);
    h3(n-1, v, b, a);
}
void h4(int n, int a, int b, int v, int w){ // a to b, spare pegs v and w
    int k;
    if(n == 0) return;
    if(n == 1){ mv(a, b); return; }
    k = K[n];
    h4(k, a, v, b, w);                       // top k disks to v
    h3(n-k, a, b, w);                        // rest to b, 3 pegs only (v is blocked)
    h4(k, v, b, a, w);                       // k disks onto b
}
int main(){
    int n, i, k, t;
    R[0] = 0; R[1] = 1;
    for(n=2; n<=12; n++){
        R[n] = 1000000;
        for(k=1; k<n; k++){
            t = 2*R[k] + (1<<(n-k)) - 1;
            if(t < R[n]){ R[n] = t; K[n] = k; }
        }
    }
    printf("n\tmoves\tR(n)\tlegal\tall on target\n");
    for(n=1; n<=12; n++){
        for(i=0; i<4; i++) top[i] = 0;
        for(i=0; i<n; i++) st[0][top[0]++] = n-i;   // largest at the bottom
        c = 0; bad = 0;
        h4(n, 0, 3, 1, 2);
        printf("%d\t%d\t%d\t%d\t%d\n", n, c, R[n], !bad, top[3] == n);
    }
    return 0;
}
