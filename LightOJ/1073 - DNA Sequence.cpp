#include<bits/stdc++.h>
using namespace std;
/*
    unique is necessary : ["AAA", "AAA", "AAA"]
    substring should be eliminated: ["ATA", "T"]
    dfs(sta, i): i is the first word in sta.
*/

const int N = 15;
const int L = 102;
const int INF = 1e6;

int next[L], len[N], same[N][N], dp[1 << N][N], n, T, fa[1 << N][N], tol;
bool sub[N], cmp[N][N][N];
string s[N];

void initKMP(int a) {
    int l = len[a], j = 0;
    next[1] = 0;
    for(int i = 1; i < l; i++) {
        while(j > 0 && s[a][i] != s[a][j]) j = next[j];
        if(s[a][i] == s[a][j]) j++;
        next[i + 1] = j;
    }
}

int KMP(int a, int b) {
    int l = len[b], j = 0, maxx = 0;
    for(int i = 0; i < l; i++) {
        while(j > 0 && s[b][i] != s[a][j]) j = next[j];
        if(s[b][i] == s[a][j]) j++;
        if(j == len[a]) return -1;
    }
    return j;
}

int dfs(int sta, int prefix) {

    int& ans = dp[sta][prefix];
    int& nex = fa[sta][prefix];
    if(ans != -1) return ans;

    ans = INF;

    int ss = sta ^ (1 << prefix);
    for(int i = 0; i < n; i++) {
        if(ss & (1 << i)) {
            int t = len[prefix] - same[i][prefix] + dfs(ss, i);
            if(ans > t) {
                ans = t;
                nex = i;
            } else if(ans == t) {
                if(cmp[i][nex][prefix]) {
                    nex = i;
                }
            }
        }
    }
    return ans;
}

void solve() {
    int maxx = INF, id;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) dp[1 << i][i] = len[i];
    for(int i = 0; i < n; i++) {
        int t = dfs((1 << n) - 1, i);
        if(maxx > t) {
            maxx = t;
            id = i;
        } else if(maxx == t) {
            if(s[i] < s[id]) {
                id = i;
            }
        }
    }
    int sta = (1 << n) - 1, las;
    bool fi = true;
    while(sta > 0) {
        if(fi) {
            cout << s[id];
            fi = false;
        } else {
            cout << s[id].substr(same[id][las]);
        }
        las = id;
        id = fa[sta][id];
        sta = sta ^ (1 << las);
    }
    cout << endl;
}

void init() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];

    tol = 0;
    memset(sub, 0, sizeof(sub));

    n = unique(s, s + n) - s;
    for(int i = 0; i < n; i++) len[i] = s[i].size();

    for(int i = 0; i < n; i++) {
        initKMP(i);
        bool issub = false;
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            if(KMP(i, j) == -1) {
                issub = true;
                break;
            }
        }
        if(issub) sub[i] = true;
    }

    for(int i = 0; i < n; i++) if(!sub[i]) s[tol++] = s[i];
    n = tol;

    for(int i = 0; i < n; i++) len[i] = s[i].size();

    for(int i = 0; i < n; i++) {
        initKMP(i);
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            same[i][j] = KMP(i, j);
            assert(same[i][j] >= 0);
        }
    }

    // 预处理后缀比较 （优化前：3。068s，优化后: 0.948s）
    // cmp[j][k][i] = true:
    // s[j].substr(same[j][i]) < s[k].substr(same[k][i])
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            for(int k = j + 1; k < n; k++) {
                if(k == i) continue;
                cmp[k][j][i] = cmp[j][k][i] = false;
                if(s[j].substr(same[j][i]) < s[k].substr(same[k][i])) {
                    cmp[j][k][i] = true;
                }
                if(s[j].substr(same[j][i]) > s[k].substr(same[k][i])) {
                    cmp[k][j][i] = true;
                }
            }
        }

}


int main() {

//    freopen("1073.in", "r", stdin);
//    freopen("1073.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        init();
        cout << "Case " << ca << ": ";
        solve();
    }
    return 0;
}

/*

100
2
aba
b

3
ATG
ACG
GGCAAG

4
af
fc
fcb
gh

*/
