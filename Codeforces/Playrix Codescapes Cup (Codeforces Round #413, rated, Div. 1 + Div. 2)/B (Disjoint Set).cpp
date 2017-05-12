#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e5 + 5;
int fa[N][4], nex[N][4], n, m;
struct Node {
    int p, a, b;
    bool operator<(const Node& t)const {
        return p < t.p;
    }
};
Node a[N];
void init() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < 4; j++) {
            if(j == a[i].a || j == a[i].b) {
                fa[i][j] = i;
            } else fa[i][j] = nex[i][j];
        }
    }
    for(int j = 1; j < 4; j++) fa[n + 1][j] = n + 1;
}
int find(int x, int i) {
    if(fa[x][i] == x) return x;
    return fa[x][i] = find(fa[x][i], i);
}
void merge(int x, int y, int i) {
    int fx = find(x, i);
    int fy = find(y, i);
    fa[fx][i] = fy;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i].p);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i].a);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i].b);

    sort(a + 1, a + n + 1);

    int las[4] = {0, 0, 0, 0};
    for(int i = 1; i <= n; i++) {
        if(a[i].a != a[i].b) {
            int& la = las[a[i].a];
            nex[la][a[i].a] = i;
            la = i;
            int& lb = las[a[i].b];
            nex[lb][a[i].b] = i;
            lb = i;
        } else {
            int& la = las[a[i].a];
            nex[la][a[i].a] = i;
            la = i;
        }
    }
    for(int i = 1; i <= 3; i++) nex[las[i]][i] = n + 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 3; j++) if(!nex[i][j]) nex[i][j] = n + 1;

    init();

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        int id = find(nex[0][x], x);
        if(!id || id > n)printf((i == m - 1) ? "-1\n" : "-1 ");
        else {
            printf((i == m - 1) ? "%d\n" : "%d ", a[id].p);
            merge(id, nex[id][a[id].a], a[id].a);
            merge(id, nex[id][a[id].b], a[id].b);
        }
    }

    return 0;
}

/*
5
100 200 100 50 3
1 1 1 1 1
1 1 1 1 1
10
3 1 2 1 3 1 2 1 3 1

*/
