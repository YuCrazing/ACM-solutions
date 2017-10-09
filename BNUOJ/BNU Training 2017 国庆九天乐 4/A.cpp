/*
    0.建图：顶点(i, j)表示第i个节点在第j时刻的状态
    1.最大流即可，无需费用流
    2.不要忘记增加(i, j)->(i, j+1)的边
    3.addedge(Node(u, j), Node(v, j+t), p)时，不要忘记判断j+t与ddl的大小关系
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110010;
const int MAXM = 400010;
const int INF = 0x3f3f3f3f;
struct Edge {
    int to,next,cap,flow;
} edge[MAXM];
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
void init() {
    tol = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0) {
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

int t, n, s, ddl, g, m, r, src, dst, x;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d%d", &n, &s, &g, &ddl, &m);
        init();
        src=0;
        dst=(n+1)*(ddl+1)+0;
        addedge(src, s*(ddl+1)+0, g);
        for(int i = 0; i < m; i++) {
            scanf("%d", &x);
            addedge(x*(ddl+1)+ddl, dst, INF);
        }

        for(int i = 1; i <= n; i++)
            for(int j = 0; j < ddl; j++)
                addedge(i*(ddl+1)+j, i*(ddl+1)+j+1, INF);

        scanf("%d", &r);

        int u, v, p, tt;
        for(int i = 0; i < r; i++) {
            scanf("%d%d%d%d", &u, &v, &p, &tt);
            for(int j = 0; j < ddl; j++) {
                if(j+tt<=ddl) addedge(u*(ddl+1)+j, v*(ddl+1)+j+tt, p);
            }
        }
        int ans = sap(src, dst, dst+1);
        printf("%d\n", ans);
    }
    return 0;
}
/*

2
4
3 8 5
2
2
4
5
1 2 1 3
3 2 1 4
3 1 2 1
1 4 1 3
3 4 1 3
4
3 10 5
2
2
4
5
1 2 1 3
3 2 1 4
3 1 2 1
1 4 1 3
3 4 1 3


*/

