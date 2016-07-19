#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char mp[1111][1111];
vector<pair<int, int> > g;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n;  i++) {
        scanf("%s", mp[i]);
        for(int j = 0; j < m; j ++)
            if(mp[i][j] == '*') g.push_back(make_pair(i, j));
    }

    int sz = g.size();
    bool ok = 1;
    int x, y;
    x = y = -1;
    if(sz > n + m - 1) ok = 0;
    if(ok) {
        if(sz == 0){
            x = y = 0;
        }
        else if(sz == 1) {
            x = g[0].first;
            y = g[0].second;
        } else {
            ok = 0;
            for(int i = 0; i < sz; i ++) {
                int u = g[i].first;
                int v = g[i].second;
                int cnt = 0;
                for(int j = 0; j < n; j ++) if(mp[j][v] == '*') cnt ++;
                for(int j = 0; j < m; j ++) if(mp[u][j] == '*') cnt ++;
                if(cnt == sz + 1){
                    ok = 1;
                    x = u;
                    y = v;
                    break;
                }
            }
        }

    }
    if(ok) printf("YES\n%d %d\n", x + 1, y + 1);
    else printf("NO\n");

    return 0;
}
