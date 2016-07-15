#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int MAXM = 100100;
struct Edge {
    int to,next;
} edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN], in[MAXN];
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
    memset(in,0,sizeof(in));
}

int main() {
    int T, u, v, n, m;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &m);
        init();
        for(int i = 0; i < m; i ++) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }
        solve(n);
        for(u = 1; u <= n;  u ++)
            for(int j = head[u]; j != -1; j = edge[j].next) {
                int v = edge[j].to;
                if(Belong[u] != Belong[v]) in[Belong[v]] ++;
            }
        int ans = 0;
        for(int i = 1; i <= scc; i ++) if(!in[i]) ans ++;
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
