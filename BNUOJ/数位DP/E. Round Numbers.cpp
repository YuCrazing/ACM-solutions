#include<cstdio>
#include<cstring>
using namespace std;

const int L = 33;
int dp[L][L][L][2], digs[L];

void init() {
    memset(dp, -1, sizeof(dp));
}

int dfs(int cur, int zeros, int ones, bool zero, bool up) {
    if(!cur) {
        if(zero) return 1;
        if(zeros >= ones) return 1;
        return 0;
    }
    int& dpp = dp[cur][zeros][ones][zero];
    if(!up && dpp != -1) return dpp;

    int sup = up ? digs[cur] : 1;
    int ans = 0;
    if(sup) ans += dfs(cur - 1, zeros, ones + 1, 0, up && 1 == digs[cur]);
    ans += dfs(cur - 1, zeros += (!zero), ones, zero, up && 0 == digs[cur]);

    if(!up) dpp = ans;
    return ans;
}

int calc(int x) {
    int l = 0;
    while(x) {
        digs[++l] = x & 1;
        x >>= 1;
    }
    return dfs(l, 0, 0, 1, 1);
}

int main() {

    init();

    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", calc(b) - calc(a - 1));
    }
    return 0;
}
