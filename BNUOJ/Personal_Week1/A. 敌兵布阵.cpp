#include<bits/stdc++.h>
using namespace std;

const int N=5e4+5;
int c[N];

int lowbit(int x) {
    return x&(-x);
}

void add(int x, int y) {
    for(int i = x; i < N; i+=lowbit(i)) c[i]+=y;
}

int ask(int x) {
    int r=0;
    for(int i = x; i; i-=lowbit(i)) r+=c[i];
    return r;
}

int main() {
    int n, T, x, y;
    char op[20];
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++) {
        memset(c, 0, sizeof(c));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &x);
            add(i, x);
        }
        printf("Case %d:\n", ca);
        while(scanf("%s", op)) {
            if(op[0]=='E') break;
            if(op[0]=='A') {
                scanf("%d%d", &x, &y);
                add(x, y);
            } else if(op[0]=='S') {
                scanf("%d%d", &x, &y);
                add(x, -y);
            } else {
                scanf("%d%d", &x, &y);
                printf("%d\n", ask(y)-ask(x-1));
            }
        }
    }
    return 0;
}
