#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200020;
int dp[N][20], a[N], n, m, k, sum[N], c[N], cnt[N];

struct Point {
    int x, y;
    bool operator<(const Point& b)const {
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
} b[N];
void initRMQ() {
    for(int i = 1; i <= n; i++) dp[i][0] = a[i];
    for(int j = 1; (1<<j) <= n; j++) {
        for(int i = 1; i + (1<<j) - 1 <= n; i++) {
            dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
        }
    }
}

int RMQ(int x, int y) {
    int j = 0;
    while((1<<j) <= y - x + 1) j++;
    j--;
    return min(dp[x][j], dp[y-(1<<j)+1][j]);
}

int ask(int i, int j) {
    int low = min(b[i].y, b[j].y);
    int high = max(b[i].y, b[j].y);
    int mid = RMQ(b[i].x, b[j].x);
    int dis = b[j].x - b[i].x + high - low;
    if(mid < low) dis += (low - mid)<<1;
    if(dis <= k) return 1;
    return 0;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    initRMQ();
    memset(cnt, 0, sizeof(cnt));

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &b[i].x, &b[i].y);
        cnt[b[i].x]++;
    }
    sum[0] = 0;
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + cnt[i];

    sort(b, b + m);

    for(int i = 0; i < m; i++) {
        c[i] = b[i].x;
    }

    ll ans = 0;
    for(int i = 0; i < m; i++) {
        int xx = min(k - 42 + b[i].x, n);
        if(xx > b[i].x) {
            ans += sum[xx] - sum[b[i].x];
            int p = upper_bound(c, c + m, xx) - c;
            for(int j = p; j < m && b[j].x - b[i].x <= k; j++) {
                ans += ask(i, j);
            }
            for(int j = i+1; j < p && b[j].x == b[i].x; j++) {
                ans += ask(i, j);
            }

        } else {
            for(int j = i+1; j < m && b[j].x - b[i].x <= k; j++) {
                ans += ask(i, j);
            }
        }

    }
    printf("%lld\n", ans);
    return 0;
}
