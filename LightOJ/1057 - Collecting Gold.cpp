/*
    dp[s][i]: s is a set, points in s form a shortest path, the last point is i, the first point is 'x'.
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;
struct Node {
    int x, y;
    Node(int _x = 0, int _y = 0):x(_x), y(_y) {};
} a[20], src;

vector<int> nxt[1<<15], pre[1<<15];
int n, m, T, k;
char mp[22][22];
int dp[1<<15][20];

void init() {
    for(int s = 0; s < (1<<15); s ++)
        for(int i = 0; i < 15; i ++)
            if((1<<i) & s) pre[s].push_back(i);
            else nxt[s].push_back(i);
}

int dis(Node& u, Node& v) {
    return max(abs(u.x - v.x), abs(u.y - v.y));
}

int main() {

    init();

    scanf("%d", &T);

    for(int cas = 1; cas <= T; cas ++) {
        k = 0;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i ++) {
            scanf("%s", mp[i]);
            for(int j = 0; j < m; j ++)
                if(mp[i][j] == 'g' ) a[k ++] = Node(i, j);
                else if(mp[i][j] == 'x') src = Node(i, j);
        }

        int dst = (1<<k) - 1;

        for(int s = 0; s <= dst;  s ++)
            for(int i = 0; i < k; i ++)
                dp[s][i] = inf;

        for(int i = 0; i < k; i ++)
            dp[1<<i][i] = dis(a[i], src);

        int sz1, sz2, u, v, ss;
        for(int s = 1; s < dst; s ++) {
            sz1 = pre[s].size();
            sz2 = nxt[s].size();
            for(int i = 0; i < sz1; i ++) {
                u = pre[s][i];
                for(int j = 0; j < sz2; j ++) {
                    v = nxt[s][j];
                    if(v >= k) break;
                    ss = s | (1<<v);
                    dp[ss][v] = min(dp[ss][v], dp[s][u] + dis(a[u], a[v]));
                }
            }
        }

        int ans = inf;
        for(int i = 0; i < k; i ++)
            ans = min(ans, dp[dst][i] + dis(a[i], src));

        printf("Case %d: %d\n", cas, (k == 0 ? 0 : ans));
    }
    return 0;
}
