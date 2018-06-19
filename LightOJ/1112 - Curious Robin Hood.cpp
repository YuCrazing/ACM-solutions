#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int c[N], n, q, T;

void init() {
    memset(c, 0, sizeof(c));
}

int low(int x) {
    return x&(-x);
}

void add(int a, int b) {
    for(; a<=n; a+=low(a))c[a]+=b;
}

int ask(int a) {
    int r=0;
    for(; a>0; a-=low(a)) r+=c[a];
    return r;
}

int main() {
    int x, y, op;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &q);
        init();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            add(i, x);
        }
        printf("Case %d:\n", ca);
        for(int i = 0; i < q; ++i) {
            scanf("%d", &op);
            if(op==1) {
                scanf("%d", &x);
                ++x;
                int r=ask(x)-ask(x-1);
                add(x, -r);
                printf("%d\n", r);
            } else if(op==2) {
                scanf("%d%d", &x, &y);
                ++x;
                add(x, y);
            } else {
                scanf("%d%d", &x, &y);
                ++x, ++y;
                printf("%d\n", ask(y)-ask(x-1));
            }
        }

    }
    return 0;
}
