#include<bits/stdc++.h>
using namespace std;

const int N = 1010;

struct P {

    int x, y;

    P(int _x = 0, int _y = 0):x(_x), y(_y) {}

    P operator+(const P& t)const {
        return P(x + t.x, y + t.y);
    }

};

P dir[4]= {
    P(0, -1),
    P(0, 1),
    P(-1, 0),
    P(1, 0)
};

char mp[N][N];
int ans[N*N], vis[N][N], n, m, cc;

bool isValid(P u) {
    return u.x >= 0 && u.x < n && u.y >= 0 && u.y < n && !vis[u.x][u.y];
}

int dfs(P u) {
    vis[u.x][u.y] = cc;
    int cnt = 1;
    P v;
    for(int i = 0; i < 4; ++i) {
        v = u + dir[i];
        if(isValid(v) && mp[u.x][u.y] != mp[v.x][v.y])
            cnt += dfs(v);
    }
    return cnt;
}

int main() {

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%s", mp[i]);

    cc = 0;
    memset(vis, 0, sizeof(vis));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!vis[i][j]) {
                ++cc;
                ans[cc] = dfs(P(i, j));
            }
        }
    }

    int x, y;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        -- x;
        -- y;
        printf("%d\n", ans[vis[x][y]]);
    }
    return 0;
}
