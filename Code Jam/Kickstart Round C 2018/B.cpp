#include <bits/stdc++.h>
using namespace std;

const int N = 15;
vector< pair<int,int> > sticks;
// vector< pair<int,int> > valid[1<<N];
int tol, selected[10], len[N][N], ans;

void dfs(int cur, int sta) {
    if(cur == sticks.size()) {
        if(tol <= 2) return;
        int sum = 0, mx = -1, l;
//            cout << "---" << endl;
        for(int i = 0; i < tol; ++i) {
            l = len[sticks[selected[i]].first][sticks[selected[i]].second];
//            cout << sticks[selected[i]].first << " " << sticks[selected[i]].second << endl;
            sum += l;
            mx = max(mx, l);
        }
        if(sum - mx > mx) ++ans;
        return ;
    }
    dfs(cur+1, sta);
    int tmp = ((1<<sticks[cur].first) | (1<<sticks[cur].second));
    if(!(sta&tmp)) {
        selected[tol++] = cur;
        dfs(cur+1, sta|tmp);
        --tol;
    }
}

void init() {
    ans = tol = 0;
    sticks.clear();
}

int main() {
    int T, n;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca) {

        init();

        cin >> n;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                cin >> len[i][j];
                if(len[i][j] && i < j) sticks.push_back({i, j});
            }
        }
        dfs(0, 0);
        cout << "Case #" << ca << ": " << ans << endl;
    }
    return 0;
}
