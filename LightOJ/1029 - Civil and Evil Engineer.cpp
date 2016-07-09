#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 111;
struct Edge {
    int u, v, w;
    bool operator<(const Edge b)const {
        return w < b.w;
    }
} edge[12002];
int fa[MAXN];

void init() {
    for(int i = 0; i < MAXN; i ++) fa[i] = i;
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

    int T, n, m, u, v, w;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        m = 0;
        while(scanf("%d%d%d", &u, &v, &w)) {
            if(!u && !v && !w) break;
            edge[m].u = u;
            edge[m].v = v;
            edge[m ++].w = w;
        }
        sort(edge, edge + m);
        int cct, minn, maxx;

        init();
        cct = n + 1, minn = 0;
        for(int i = 0; i < m; i ++) {
            u = edge[i].u;
            v = edge[i].v;
            if(find(u) != find(v)) {
                merge(u, v);
                cct --;
                minn += edge[i].w;
            }
            if(cct == 1) break;
        }

        init();
        cct = n + 1, maxx = 0;
        for(int i = m - 1; i > -1; i --) {
            u = edge[i].u;
            v = edge[i].v;
            if(find(u) != find(v)) {
                merge(u, v);
                cct --;
                maxx += edge[i].w;
            }
            if(cct == 1) break;
        }

        printf("Case %d: ", cas);
        if((minn + maxx) & 1) printf("%d/%d\n", minn + maxx, 2); // \n
        else printf("%d\n", (minn + maxx) / 2);

    }
}
