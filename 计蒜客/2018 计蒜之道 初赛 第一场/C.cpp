/*
    2018 计蒜之道 阅读理解大赛
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5+5;
const int MAXM = 1e5+5;

struct Edge {
    int to,next;
} edge[MAXM];

int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top;
int scc;
bool Instack[MAXN];
int num[MAXN];

void addedge(int u,int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Tarjan(int u) {
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].to;
        if( !DFN[v] ) {
            Tarjan(v);
            if( Low[u] > Low[v] )Low[u] = Low[v];
        } else if(Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u]) {
        scc++;
        do {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        } while( v != u);
    }
}

void solve(int N) {
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(num,0,sizeof(num));
    Index = scc = top = 0;
    for(int i = 1; i <= N; i++)
        if(!DFN[i])
            Tarjan(i);
}

void init() {
    tot = 0;
    memset(head,-1,sizeof(head));
}

ll a[MAXN], ans[MAXN], out[MAXN], id[MAXN], res, n, m, x, y, l, r, op;
int main() {
    init();
    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        id[i]=i;
    }
    scanf("%lld", &m);
    for(int q = 0; q < m; ++q) {
        scanf("%lld", &op);
        if(op==0) {
            scanf("%lld%lld", &x, &y);
            id[x]=++n;
            a[id[x]]=y;
        } else {
            scanf("%lld%lld%lld", &x, &l, &r);
            for(int i = l; i <= r; ++i) addedge(id[x], id[i]);
        }
    }

    solve(n);

    for(int i = 1; i <= n; ++i) {
        ans[Belong[i]]+=a[i];
        //printf("id=%d ", Belong[i]);
    }

    for(int u = 1; u <= n; ++u){
        for(int j = head[u]; j !=-1; j=edge[j].next){
            int v=edge[j].to;
            if(Belong[u]!=Belong[v])
                ++out[Belong[u]];
        }
    }

    if(scc==1){
        res=ans[1];
    }else{
        res=1e18;
        for(int i = 1; i <= scc; ++i) if(out[i]==0 && res>ans[i]) res=ans[i];
    }

    printf("%lld\n", res);

    return 0;
}
/*

3
1 10 100
3
1 1 2 2
1 2 3 3
1 3 3 3

5
1 10 100 1000 10000
5
1 1 3 4
1 3 5 5
0 3 0
1 3 1 2
1 2 3 5
*/
