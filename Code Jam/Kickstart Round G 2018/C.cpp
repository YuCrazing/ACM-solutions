#include <bits/stdc++.h>
using namespace std;

const int N = 111;

bool vis[N][N], reachExit[1<<15], dpVis[1<<15];
int c[N][N], id[N][N], energy[1<<15];
vector< tuple<int, int, int> > traps;
vector< int > reachable[1<<15];
int T, n, m, e, mask, ans, k;
pair<int, int> src, dst;

bool check(pair<int, int> u) {
    if(!(vis[u.first][u.second] == false && u.first > 0 && u.first <= n && u.second > 0 && u.second <= m)) return false;

    if(c[u.first][u.second] > -100000 && c[u.first][u.second] < 0) reachable[mask].push_back(id[u.first][u.second]);
    else if(c[u.first][u.second] > 0) energy[mask] += c[u.first][u.second];

    if(u == dst) reachExit[mask] = true;

    return c[u.first][u.second] >= 0;
}

void dfs(pair<int, int> u) {
    vis[u.first][u.second] = true;
    if(check({u.first+1, u.second})) dfs({u.first+1, u.second});
    if(check({u.first-1, u.second})) dfs({u.first-1, u.second});
    if(check({u.first, u.second+1})) dfs({u.first, u.second+1});
    if(check({u.first, u.second-1})) dfs({u.first, u.second-1});
}

// 注意使用 dpVis 记忆化
void dp(int s) {
    dpVis[s] = true;
    if(reachExit[s]) ans = max(ans, energy[s]);
    for(int i = 0; i < reachable[s].size(); ++i) {
        if(!dpVis[s | (1<<reachable[s][i])] && energy[s] + get<2>(traps[reachable[s][i]]) >= 0) dp(s | (1<<reachable[s][i]));
    }
}

int main() {

    freopen("C-large-practice.in", "r", stdin);
    freopen("C-large-practice.out", "w", stdout);

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        traps.clear();
        scanf("%d%d%d%d%d%d%d", &n, &m, &e, &src.first, &src.second, &dst.first, &dst.second);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                scanf("%d", &c[i][j]);
                if(c[i][j] > -100000 && c[i][j] < 0) {
                    id[i][j] = traps.size();
                    traps.push_back(tuple<int, int, int>(i, j, c[i][j]));
                }
            }
        }

        k = traps.size();
        for(mask = 0; mask < (1<<k); ++mask) {
            reachable[mask].clear();
            energy[mask] = e;
            reachExit[mask] = dpVis[mask] = false;
            for(int i = 0; i < k; ++i) if((1<<i)&mask) {
                    c[get<0>(traps[i])][get<1>(traps[i])] = 0;
                    energy[mask] += get<2>(traps[i]);
                }

            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= m; ++j)
                    vis[i][j] = false;
            dfs(src);

            for(int i = 0; i < k; ++i) if((1<<i)&mask) {
                    c[get<0>(traps[i])][get<1>(traps[i])] = get<2>(traps[i]);
                }
        }
        ans = -1;
        dp(0);
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
