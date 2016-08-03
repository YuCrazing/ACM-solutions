#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int base = 26;
const int MAXN = base * base * base + 5;

int dir[6][3] = {
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 0, -1}
};

bool forbid[MAXN];
char s[3][30];
int l[3], src, dst, vis[MAXN];

void bfs() {
    memset(vis, -1, sizeof(vis));
    if(forbid[src]) return;
    vis[src] = 0;
    queue<int> Q;
    Q.push(src);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int i = u / base / base;
        int j = u / base % base;
        int k = u % base;
        for(int l = 0; l < 6; l ++) {
            int v = (i + dir[l][0] + base) % base * base * base + (j + dir[l][1] + base) % base * base + (k + dir[l][2] + base) % base;
            if(forbid[v]) continue;
            if(vis[v] != -1) continue;
            vis[v] = vis[u] + 1;
            Q.push(v);
        }
    }
}

void init() {

    memset(forbid, 0, sizeof(forbid));

    scanf("%s%s", s[0], s[1]);
    src = (s[0][0] - 'a') * base * base + (s[0][1] - 'a') * base + (s[0][2] - 'a');
    dst = (s[1][0] - 'a') * base * base + (s[1][1] - 'a') * base + (s[1][2] - 'a');

    int n;
    scanf("%d", &n);
    while(n --) {

        for(int i = 0; i < 3; i ++) {
            scanf("%s", s[i]);
            l[i] = strlen(s[i]);
        }

        for(int i = 0; i < l[0]; i ++)
            for(int j = 0; j < l[1]; j ++)
                for(int k = 0; k < l[2]; k ++)
                    forbid[(s[0][i] - 'a') * base * base + (s[1][j]  - 'a') * base + (s[2][k] - 'a')] = 1;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        init();
        bfs();
        printf("Case %d: %d\n", cas, vis[dst]);
    }
    return 0;
}
