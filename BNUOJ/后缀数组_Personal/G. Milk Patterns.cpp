#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;
const int N = 2e4 + 5;

int t1[N], t2[N], c[1000005], sa[N], ra[N], height[N], dp[N][20];

void initRMQ(int n) {
    for(int i = 2; i <= n; i++) dp[i][0] = height[i];
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 2; i + (1<<j) - 1 <= n; i++) {
            dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
        }
    }
}

int RMQ(int x, int y) {
    int j = 0;
    while((1<<j) <= y - x + 1) j++;
    j--;
    return min(dp[x][j], dp[y - (1<<j) + 1][j]);
}

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void DA(int *s, int n) {
    n++;
    int m = 1000005;

    int *x = t1, *y = t2;
    for(int i = 0; i < m; i++) c[i] = 0;
    for(int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for(int i = 1; i < m; i++) c[i] += c[i - 1];
    for(int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;

    int p;
    for(int l = 1; l <= n; l <<= 1, m = p) {
        p = 0;
        for(int i = n - l; i < n; i++) y[p++] = i;
        for(int i = 0; i < n; i++) if(sa[i] >= l) y[p++] = sa[i] - l;

        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[y[i]]]++;
        for(int i = 1; i < m; i++) c[i] += c[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

        swap(x, y);

        p = 0;
        x[sa[0]] = p++;
        for(int i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], l) ? p-1 : p++;
        if(p >= n) break;
    }

    for(int i = 0; i < n; i++) ra[sa[i]] = i;

    int k = 0;
    for(int i = 0; i < n - 1; i++) {
        if(k) k--;
        int j = sa[ra[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        height[ra[i]] = k;
    }
//    for(int i = 0; i < n; i++) printf("%3d: %3d %3d %3d %3d\n", i, sa[i], ra[i], height[i], s[i]);
}

int a[N], k, n;

int solve() {
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        ans = max(ans, RMQ(i, i + k - 2));
    }
    assert(ans > 0);
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]++;
    }
    a[n] = 0;

    DA(a, n);

    initRMQ(n);

    printf("%d\n", solve());

    return 0;
}
