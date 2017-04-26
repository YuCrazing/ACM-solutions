#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
const int M = 1e5;

struct Edge {
    int u, v, w;

    bool operator<(const Edge& b) const {
        return w < b.w;
    }

    void read() {
        scanf("%d%d%d", &u, &v, &w);
    }
} e[M];

int fa[N];

void init() {
    for(int i = 0; i < N; i++) fa[i] = i;
}

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}

int main() {
    int T, n, m, a;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d%d", &n, &m, &a);
        for(int i = 0; i < m; i++) e[i].read();
        sort(e, e + m);

        init(); // !
        int cost = n * a, ans = cost, cc = n, num = cc;
        for(int i = 0; i < m; i++) {
            int u = e[i].u;
            int v = e[i].v;
            int w = e[i].w;
            if(find(u) == find(v)) continue;

            merge(u, v);
            cc--;
            cost += w - a;
            if(ans > cost) {
                ans = cost;
                num = cc;
            }
        }
        printf("Case %d: %d %d\n", ca, ans, num);
    }
    return 0;
}
