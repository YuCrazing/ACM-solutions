#include<bits/stdc++.h>
using namespace std;

const int N = 404;

struct P {

    int x, y;

    P(int _x = 0, int _y = 0):x(_x), y(_y) {}

    P operator+(const P& t)const {
        return P(x + t.x, y + t.y);
    }

};

P s;
queue<P> Q;
int dis[N][N], n, m;

P dir[8]= {
    P(-1, -2),
    P(-1, 2),
    P(1, -2),
    P(1, 2),
    P(-2, -1),
    P(-2, 1),
    P(2, -1),
    P(2, 1)
};

bool isValid(P u) {
    return u.x >= 0 && u.x < n && u.y >= 0 && u.y < m && dis[u.x][u.y] == -1;
}

void bfs() {

    dis[s.x][s.y] = 0;
    Q.push(s);

    P u, v;
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();

        for(int i = 0; i < 8; ++i) {
            v = u + dir[i];
            if(isValid(v)) {
                dis[v.x][v.y] = dis[u.x][u.y] + 1;
                Q.push(v);
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s.x, &s.y);
    -- s.x;
    -- s.y;
    memset(dis, -1, sizeof(dis));
    bfs();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) printf(j==m-1?"%-5d\n":"%-5d", dis[i][j]);
    return 0;
}
