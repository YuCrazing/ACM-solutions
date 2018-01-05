/*
    注意输入全为2的情况，也要与源点相连
*/

#include<cstdio>
#include<cstring>
using namespace std;


const int MAXN = 1100;//点数的最大值
const int MAXM = 210007;//边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge {
    int to,next,cap,flow;
} edge[MAXM]; //注意是MAXM
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
void init() {
    tol = 0;
    memset(head,-1,sizeof(head));
}
//加边，单向图三个参数，双向图四个参数
void addedge(int u,int v,int w,int rw=0) {
    //printf("%d %d\n", u, v);
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].next = head[u];
    edge[tol].flow = 0;
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = rw;
    edge[tol].next = head[v];
    edge[tol].flow = 0;
    head[v]=tol++;
}
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start,int end,int N) {
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(head));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[start] < N) {
        if(u == end) {
            int Min = INF;
            for(int i = pre[u]; i != -1; i = pre[edge[i^1].to])
                if(Min > edge[i].cap - edge[i].flow)
                    Min = edge[i].cap - edge[i].flow;
            for(int i = pre[u]; i != -1; i = pre[edge[i^1].to]) {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; i != -1; i = edge[i].next) {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u]) {
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag) {
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; i != -1; i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u] = Min+1;
        gap[dep[u]]++;
        if(u != start) u = edge[pre[u]^1].to;
    }
    return ans;
}

const int N=55;
struct Node {
    int in[12], out[12];
} a[N];

int ans[MAXM][3];

int n, p, x;
int main() {
    while(scanf("%d%d", &p, &n)!=EOF) {
        init();
        for(int i = 1; i <= n; i++) {
            scanf("%d", &x);
            addedge(i, i+n, x);
            for(int j = 0; j < p; j++) scanf("%d", &a[i].in[j]);
            for(int j = 0; j < p; j++) scanf("%d", &a[i].out[j]);
        }
        int s=0, t=2*n+1;
        for(int i = 1; i <= n; i++) {
            bool one=true, zero=true, two=true;
            for(int j = 0; j < p; j++) {
                if(a[i].in[j]) zero=false;
                if(a[i].in[j]!=2) two=false;
                if(!a[i].out[j]) one=false;
            }
            if(zero || two) addedge(s, i, INF);
            if(one) addedge(i+n, t, INF);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i==j) continue;
                bool ok=true;
                for(int k=0; k<p; k++) {
                    if(a[i].out[k]+a[j].in[k]==1) {
                        ok=false;
                        break;
                    }
                }
                if(ok) addedge(i+n, j, INF);
            }
        }

        int a=sap(s, t, 2*n+2), b=0, tol=0;
        for(int u = 1; u <= n; u++) {
            for(int j = head[u+n]; j!=-1; j=edge[j].next) {
                if(!edge[j].cap || !edge[j].flow ||edge[j].to==t) continue;
                int v=edge[j].to;
                ans[tol][0]=u;
                ans[tol][1]=v;
                ans[tol++][2]=edge[j].flow;
                b++;
            }
        }

        printf("%d %d\n", a, b);
        for(int i = 0; i < tol; i++) printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    }
    return 0;
}
