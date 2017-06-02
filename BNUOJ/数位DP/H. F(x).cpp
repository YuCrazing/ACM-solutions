#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4600;

int dp[11][N], digs[11];

void init() {
    memset(dp, -1, sizeof(dp));
}

int dfs(int cur, int k, int up) {
    if(k < 0) return 0;
    if(!cur) {
        if(cur >= 0) return 1; // ?
        return 0;
    }

    int& dpp = dp[cur][k];

    if(!up && dpp != -1) return dpp;

    int sup = up ? digs[cur] : 9;

    int ans = 0;
    for(int i = 0; i <= sup; i++) {
        ans += dfs(cur - 1, k - i * (1<<(cur - 1)), up && i == digs[cur]);
    }

    if(!up) dpp = ans;

    return ans;
}

int calc(int x, int val) {
    int l = 0;
    while(x) {
        digs[++l] = x % 10;
        x /= 10;
    }
    return dfs(l, val, 1);
}

int f(int x) {
    ll sum = 0, p = 1;
    while(x) {
        sum += p * (x%10);
        p <<= 1;
        x /= 10;
    }
    assert(sum < N);
    return sum;
}

int main() {

    init();

    int T, l, r;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &l, &r);
        printf("Case #%d: %d\n", ca, calc(r, f(l)));
    }
    return 0;
}
