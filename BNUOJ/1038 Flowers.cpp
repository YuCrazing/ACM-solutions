#include<bits/stdc++.h>
using namespace std;

/*
    可种植花区域可能有多个联通块
*/

const int N = 103;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, ans;
char mp[N][N];
bool vis[N][N], done;

struct Node {
    int x, y;
    Node() {};
    Node(int x, int y):x(x), y(y) {};
};

int ob(Node& t) {
    int x = t.x;
    int y = t.y;
    if(x < 0 || x >= n || y < 0 || y >= m) return -1;
    if(mp[x][y] == '*' || vis[x][y]) return 0;
    return 1;
}

int bfs(Node s) {
    int cnt = 0;
    bool may = true;
    queue<Node> q;
    q.push(s);
    vis[s.x][s.y] = true;
    while(!q.empty()) {
        Node u = q.front();
        q.pop();
        cnt ++;

        for(int i = 0; i < 4; i++) {
            int x = u.x + dx[i];
            int y = u.y + dy[i];
            Node v(x, y);
            if(ob(v) < 0) {
                may = false;
                continue;
            }
            if(ob(v) == 0) continue;
            q.push(v);
            vis[v.x][v.y] = true;
        }
    }
    if(may) return cnt;
    return 0;
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 0; i < n; i++)
            scanf("%s", mp[i]);
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mp[i][j] == '.' && !vis[i][j]) {
                    ans += bfs(Node(i, j));
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
