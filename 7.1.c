#include <stdio.h>
int in(int r, int c, int n){ return c >= 0 && c <= r && r < n; }  // point inside upright triangle
int main(){
    int n, r, c, dr, dc, o, best, T;
    printf("n\tcoins\tmoves(program)\tn(n+1)/6\n");
    for(n=2; n<=15; n++){
        T = n*(n+1)/2; best = 0;
        for(dr=0; dr<=2*n; dr++)
            for(dc=0; dc<=2*n; dc++){
                o = 0;
                for(r=0; r<n; r++)
                    for(c=0; c<=r; c++)
                        if(in(dr-r, dc-c, n)) o++;   // coin stays if its flipped image is in the triangle
                if(o > best) best = o;
            }
        printf("%d\t%d\t%d\t\t%d\n", n, T, T-best, n*(n+1)/6);
    }
    return 0;
}
