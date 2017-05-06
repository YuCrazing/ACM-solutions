#include<bits/stdc++.h>
using namespace std;

const int N = 1011;
int T, n, m, a[N], MAX, ans;

bool ok(int x) {
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(sum + a[i] > x) {
            sum = a[i];
            cnt++;
        } else sum += a[i];
    }
    if(sum) cnt++;
    return cnt <= m;
}

int BS() {
    int l = MAX, r = 1e9; // l = MAX.
    while(l < r) {
        int mid = (l + r) >> 1;
        if(ok(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d%d", &n, &m);
        MAX = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            MAX = max(MAX, a[i]);
        }
        if(m >= n) ans = MAX;
        else ans = BS();
        printf("Case %d: %d\n", ca, ans);
    }
    return 0;
}
