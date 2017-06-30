#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1011;

struct Seg {

    int l, r, w;

    bool operator<(const Seg& t)const {
        return r < t.r;
    }

    void read() {
        scanf("%d%d%d", &l, &r, &w);
    }

} a[N];

int n, m, r, b[N], mx[N], dp[N];
int main() {
    scanf("%d%d%d", &m, &n, &r);
    for(int i = 0; i < n; i++) a[i].read();
    sort(a, a + n);
    for(int i = 0; i < n; i++) b[i] = a[i].r;

    int maxx = 0, ans;
    for(int i = 0; i < n; i++) {
        dp[i] = a[i].w;
        int p = upper_bound(b, b + i, a[i].l - r) - b - 1;
        if(p>=0) dp[i] += mx[p];
        mx[i] = max((i ? mx[i-1] : 0), dp[i]);
        if(a[i].r <= m) ans = mx[i];
        else break;
    }
    printf("%d\n", ans);
    return 0;
}
