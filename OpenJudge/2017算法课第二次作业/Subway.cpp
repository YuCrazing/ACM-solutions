#include<bits/stdc++.h>
using namespace std;

const int N=222;
const double INF=1e10;

struct Point {
    double x, y;
    Point(int _x=0.0, int _y=0.0):x(_x),y(_y) {}
    void read() {
        scanf("%lf%lf", &x, &y);
    }
} p[N];

double dist(const Point &a, const Point &b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double dis[N], g[N][N];
bool vis[N];

double spfa(int s, int t, int n) {
    for(int i = 0; i < n; i++) {
        vis[i]=false;
        dis[i]=INF;
    }
    dis[s]=0.0;

    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int v = 0; v < n; v++) {
            if(u==v) continue;
            double w=g[u][v];
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                if(!vis[v]) {
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    return dis[t];
}

double v[2];
int x, y, n;

void init() {
    n=0;
    v[0]=(1e4)/60.0;
    v[1]=(4e4)/60.0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            g[i][j]=INF;
}

int main() {

    init();

    p[n++].read();
    p[n++].read();
    bool ok=false;
    while(scanf("%d%d", &x, &y)!=EOF) {
        if(x==-1&&y==-1) {
            ok=false;
            continue;
        } else {
            p[n++]=Point(x, y);
            if(ok) g[n-2][n-1]=g[n-1][n-2]=dist(p[n-1], p[n-2])/v[1];
            ok=true;
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            g[i][j]=g[j][i]=min(g[i][j], dist(p[i], p[j])/v[0]);

    printf("%.0f\n",spfa(0, 1, n));
    return 0;
}
