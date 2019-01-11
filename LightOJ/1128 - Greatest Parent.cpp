#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T, n, q, fa[N][20], val[N];

void init() {
    for(int j = 1; j < 20; ++j) {
        for(int i = 0; i < n; ++i) {
            fa[i][j] = fa[i][j-1]==-1?-1:fa[fa[i][j-1]][j-1];
        }
    }
}

int find(int u, int x) {
    for(int j = 19; j >= 0; --j) {
        if(fa[u][j]!=-1 && val[fa[u][j]]>=x) u = fa[u][j];
    }
    return u;
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &q);
        fa[0][0] = -1;
        val[0] = 1;
        int pa, v;
        for(int i = 1; i < n ; ++i) {
            scanf("%d%d", &pa, &v);
            fa[i][0] = pa;
            val[i] = v;
        }
        init();
        printf("Case %d:\n", ca);
        int u, x;
        for(int i = 0; i < q; ++i) {
            scanf("%d%d", &u, &x);
            printf("%d\n", find(u, x));
        }
    }
    return 0;
}
