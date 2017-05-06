#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point() {};
    Point(int _x, int _y): x(_x), y(_y) {};
} pos[8];

const int INF = 0x3f3f3f3f;

int tol = 0, vis[8], res[100][8], dis[8][8][8][8];
char s[10];

bool ok(int x, int y) {
    for(int i = 0; i < x; i++) if(vis[i] == y || x - i == y - vis[i] || x - i == vis[i] - y) return false;
    return true;
}

void dfs(int x) {
    if(x == 8) {
        for(int i = 0; i < 8; i++) res[tol][i] = vis[i];
        tol++;
        return ;
    }
    for(int y = 0; y < 8; y++) {
        if(!ok(x, y)) continue;
        vis[x] = y;
        dfs(x + 1);
    }
}

/* ??? */
int d(int x1, int y1, int x2, int y2) {

    int& d1 = dis[x1][y1][x2][y2];
    int& d2 = dis[x2][y2][x1][y1];

    if(d1 != -1) return d1;

    int ans;
    if(x1 == x2 && y1 == y2) ans = 0;
    else if(x1 == x2 || y1 == y2 || x1 - x2 == y1 - y2 || x1 - x2 == y2 - y1) {
        ans = 1;
    } else ans = 2;

    d1 = d2 = ans;
    return ans;
}

void init() {
    memset(dis, -1, sizeof(dis));
    dfs(0);
}

/* KM算法
* 复杂度O(nx*nx*ny)
* 求最大权匹配
* 若求最小权匹配，可将权值取相反数，结果取相反数
* 点的编号从0开始
*/
const int N = 8;
int nx,ny;//两边的点数
int g[N][N];//二分图描述
int linker[N],lx[N],ly[N];//y中各点匹配状态，x,y中的点标号
int slack[N];
bool visx[N],visy[N];
bool DFS(int x) {
    visx[x] = true;
    for(int y = 0; y < ny; y++) {
        if(visy[y])continue;
        int tmp = lx[x] + ly[y] - g[x][y];
        if(tmp == 0) {
            visy[y] = true;
            if(linker[y] == -1 || DFS(linker[y])) {
                linker[y] = x;
                return true;
            }
        } else if(slack[y] > tmp)
            slack[y] = tmp;
    }
    return false;
}

int KM() {
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));
    for(int i = 0; i < nx; i++) {
        lx[i] = -INF;
        for(int j = 0; j < ny; j++)
            if(g[i][j] > lx[i])
                lx[i] = g[i][j];
    }
    for(int x = 0; x < nx; x++) {
        for(int i = 0; i < ny; i++)
            slack[i] = INF;
        while(true) {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(DFS(x))break;
            int d = INF;
            for(int i = 0; i < ny; i++)
                if(!visy[i] && d > slack[i])
                    d = slack[i];
            for(int i = 0; i < nx; i++)
                if(visx[i])
                    lx[i] -= d;
            for(int i = 0; i < ny; i++) {
                if(visy[i])ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < ny; i++)
        if(linker[i] != -1)
            res += g[linker[i]][i];
    return res;
}

int solve() {
    int ans = INF;
    for(int k = 0; k < tol; k++) {
        memset(g, 0, sizeof(g));
        nx = ny = 8;
        for(int i = 0; i < nx; i++)
            for(int j = 0; j < ny; j++) {
                g[i][j] = -d(i, res[k][i], pos[j].x, pos[j].y);
            }
        ans = min(ans, -KM());
    }
    return ans;
}

int main() {

    init();

    int T, n;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        n = 0;
        for(int i = 0; i < 8; i++) {
            scanf("%s", s);
            for(int j = 0; j < 8; j++)
                if(s[j] == 'q') pos[n++] = Point(i, j);
        }
        printf("Case %d: %d\n", ca, solve());
    }
    return 0;
}
