/*
    Use BFS to calculate vis[c][i][j], represents c-th horse needed jump numbers to position(i, j),
    divide k is move numbers.
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
char mp[10][10];
int vis[100][10][10], n, m, T, ct, k[100];
struct Node {
    int x, y;

    Node(int _x = 0, int _y = 0):x(_x),y(_y) {};

    Node operator+(const Node& b)const {
        return Node(x + b.x, y + b.y);
    }

    bool operator<(const Node& b)const {
        if(x == b.x) return y < b.y;
        return x < b.x;
    }

    bool operator==(const Node& b)const {
        return x == b.x && y == b.y;
    }
};

Node dir[8] = {
    Node(1, 2),
    Node(1, -2),
    Node(2, 1),
    Node(2, -1),
    Node(-1, 2),
    Node(-1, -2),
    Node(-2, 1),
    Node(-2, -1)
};

bool ok(Node s) {
    return s.x >=0 && s.x < n && s.y >= 0 && s.y < m;
}


void bfs(Node s) {
    int grid = 0;
    memset(vis[ct], 0, sizeof(vis[ct]));
    queue<Node> Q;
    Q.push(s);
    vis[ct][s.x][s.y] = 1;

    while(!Q.empty()) {
        Node u = Q.front();
        Q.pop();
        for(int i = 0; i < 8; i ++) {
            Node v = u + dir[i];
            if(!ok(v)) continue;
            if(vis[ct][v.x][v.y]) continue;
            vis[ct][v.x][v.y] = vis[ct][u.x][u.y] + 1;
            Q.push(v);
        }
    }
}

int main() {

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i ++) scanf("%s", mp[i]);
        ct = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j++)
                if(mp[i][j] >= '0' && mp[i][j] <= '9') {
                    memset(vis[ct], 0, sizeof(vis[ct]));
                    bfs(Node(i, j));
                    k[ct ++] = mp[i][j] - '0';
                }

        int res = INF;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j++) {
                bool ok = 1;
                int dis = 0;
                for(int c = 0; c < ct; c++) {
                    if(vis[c][i][j] == 0) {
                        ok = 0;
                        break;
                    }
                    dis += (vis[c][i][j] - 1 + k[c] - 1) / k[c];
                }
                if(ok) res = min(res, dis);
            }

        if(res == INF) res = -1;
        printf("Case %d: %d\n", cas, res);
    }
    return 0;
}
