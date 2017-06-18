#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200022;
ll c[N], sum[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int b) {
    for(int i = x; i < N; i += lowbit(i)) {
        c[i] += b;
    }
}

ll ask(int x) {
    ll ans = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        ans += c[i];
    }
    return ans;
}
int main() {
    memset(c, 0, sizeof(c));
    int n, m, k, l, r;
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        add(l, 1);
        add(r + 1, -1);
    }

    sum[0] = 0;
    for(int i = 1; i < N; i++) {
        sum[i] = sum[i-1];
        if(ask(i)>= k) sum[i]++;
//        printf("%d  = %d\n" , i, ask(i));
    }

    for(int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        printf("%lld\n", sum[r] - sum[l-1]);
    }
    return 0;
}
