#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
using namespace std;

const int MAXN = 1100;//点数的最大值
const int MAXM = 6666;//边数的最大值
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

int n, m, k, nn;
map<string, int> mp;
string s, ss;

int getid(string s) {
    if(mp.find(s)!=mp.end()) return mp[s];
    return mp[s]=++nn;
}

int a[MAXN], b[MAXN];
int main() {
    init();
    nn=0;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>s;
        a[getid(s)]++;
    }
    cin>>m;
    for(int i = 0; i < m; i++) {
        cin>>s>>s;
        b[getid(s)]++;
    }
    cin>>k;
    for(int i = 0; i < k; i++) {
        cin>>s>>ss;
        int u=getid(s);
        int v=getid(ss);
        addedge(v, u, INF);
    }
    int s=0, t=nn+1;
    for(int i = 1; i <= nn; i++) {
        addedge(s, i, a[i]);
        addedge(i, t, b[i]);
    }
    printf("%d\n", m-sap(s, t, t+1));
    return 0;
}
