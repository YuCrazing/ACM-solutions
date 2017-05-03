#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n, f[40], tol = 0;
void init() {
    f[0] = 1;
    for(int i = 1; ; i++) {
        if(i * f[i - 1] <= N) {
            f[i] = f[i - 1] * i;
            tol = i;
        } else break;
    }
}

int main() {
    init();
    while(scanf("%d", &n) != EOF && n >= 0) {
        if(!n) { // !!!
            printf("NO\n");
            continue;
        }
        for(int i = tol; i >= 0; i--) {
            if(f[i] <= n) n -= f[i];
        }
        printf(n ? "NO\n" : "YES\n");
    }
    return 0;
}
