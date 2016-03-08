//======================================================
// Author: Yu Chang
// Date: 2016-03-07
// E:\ACM-solutions\ACM-solutions\LightOJ\1002 - Country Roads.cpp
//======================================================
/* Kruskal */
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define LL long long
#define pr printf
#define sc scanf
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 511;
const int MAXM = 16666;
struct Edge{
    int w, u, v;
    Edge(int _u = 0, int _v = 0, int _w = 0):u(_u),v(_v),w(_w){}
    bool operator<(const Edge &b)const {
        return w < b.w;
    }
}edge[MAXM];
int fa[MAXN], ans[MAXN];
int tot;
list<int> st;
void init(int n){
    for(int i = 0; i < n; i++) fa[i] = i;
    mem(ans, -1);
    tot = 0;
    st.clear();
}
int find(int x){
    if(fa[x] == x) return fa[x];
    return fa[x] = find(fa[x]);
}
void merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}
int main(){
    int T, n, m, u, v, w, t;
    sc("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        sc("%d%d", &n, &m);
        init(n);
        for(int i = 0; i < m; i++){
            sc("%d%d%d", &u, &v, &w);
            edge[tot++] = Edge(u, v, w);
        }
        sc("%d", &t);
        for(int i = 0; i < n; i++) if(i != t) st.push_back(i);

        sort(edge, edge + tot);

        for(int i = 0; i < tot; i++){
            u = edge[i].u;
            v = edge[i].v;
            w = edge[i].w;
            merge(u, v);
            for(list<int>::iterator it = st.begin(); it != st.end(); ){
                if(find(t) == find(*it)){
                    ans[*it] = w;
                    it = st.erase(it);
                }else it++;
            }
        }
        ans[t] = 0;
        pr("Case %d:\n", cas);
        for(int i = 0; i < n; i++)
            if(ans[i] == -1) pr("Impossible\n");
            else pr("%d\n", ans[i]);
    }
    return 0;
}
