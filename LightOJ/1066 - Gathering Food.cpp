#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;
struct Node {
    int x, y;
    Node(int _x = 0, int _y = 0):x(_x),y(_y) {};

} a[30];
char mp[11][11];
int n, T, vis[11][11];
int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}
};

bool ok(Node s, int k) {
    int i = s.x;
    int j = s.y;
    if(mp[i][j] >= 'A' && mp[i][j] <= 'Z') return mp[i][j] - 'A' <= k;
    return i >= 0 && i < n && j >= 0 && j < n && mp[i][j] != '#';
}

bool bfs(Node s, Node t, int k) {
    memset(vis, 0, sizeof(vis));
    queue<Node> Q;
    Q.push(s);
    vis[s.x][s.y] = 1;
    while(!Q.empty()) {
        Node u = Q.front();
        Q.pop();
        Node v;
        for(int i = 0; i < 4; i ++) {
            v = Node(u.x + dir[i][0], u.y + dir[i][1]);
            if(!ok(v, k)) continue;
            if(vis[v.x][v.y]) continue;
            vis[v.x][v.y] = vis[u.x][u.y] + 1;
            if(v.x == t.x && v.y == t.y) break;
            Q.push(v);
        }
    }
    return vis[t.x][t.y];
}

int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        int k = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%s", mp[i]);
            for(int j = 0; j < n; j ++)
                if(mp[i][j] >= 'A' && mp[i][j] <= 'Z') {
                    k ++;
                    a[mp[i][j] - 'A'] = Node(i, j);
                }
        }

        bool flag = 1;
        int ans = 0;
        for(int i = 0; i < k - 1; i ++) {
            if(!bfs(a[i], a[i + 1], i + 1)) {
                flag = 0;
                break;
            } else ans += vis[a[i + 1].x][a[i + 1].y] - 1;
        }

        printf("Case %d: ", cas);
        if(!flag) printf("Impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}
