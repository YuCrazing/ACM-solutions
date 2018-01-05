/*
    注意数据要全部读入，不能break，否则会WA
*/

#include<bits/stdc++.h>
using namespace std;

const int N=1011;
int fa[N], v[N];
bool ok;

void init(int n) {
    ok=true;
    for(int i = 0; i <= n; i++) {
        fa[i]=i;
        v[i]=0;
    }
}

int find(int x) {
    if(fa[x]==x) return x;
    int fa_old=fa[x];//!!
    fa[x]=find(fa_old);
    v[x]=((v[fa_old]+v[x])&1);//!!
    return fa[x];
}

void merge(int x, int y, int w) {
    int fx=find(x);
    int fy=find(y);
    fa[fy]=fx;
    v[fy]=((v[x]+w-v[y]+2)&1);
}

int n, m, x, y, w;
int main() {
    while(scanf("%d%d", &n, &m)!=EOF) {
        init(n);
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &w);
            if(!ok) continue;
            if(find(x)==find(y)) {
                if(((v[x]-v[y]+2)&1)!=w) ok=false;
            } else merge(x, y, w);
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*

3 3
1 0 0
2 1 1
2 0 0

*/
