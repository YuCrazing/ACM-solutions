#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e5 + 5;
const int MAXQ = 1e5 + 5;

int c[2*MAXN], L[MAXN], R[MAXN], K[MAXQ], X[MAXN], Y[MAXN], Z[MAXQ], b[2*MAXN];
ll sum[2*MAXN];

int bin(int m, int k) {
    ll rk = sum[m] + 1 - k;
    if(rk < 1) return 0;
    int l = 1, r = m;
    while(l < r) {
        int mid = (l+r) / 2;
        if(sum[mid] >= rk) r = mid;
        else l = mid + 1;
    }
    return b[r] + (rk - sum[r-1] - 1)/c[r];
}

int main() {

//    freopen("B-large-practice.in", "r", stdin);
//    freopen("B-large-practice.out", "w", stdout);

    int T, N, Q, A, B, C, M;

    scanf("%d", &T);

    for(int ca = 1; ca <= T; ++ca) {

        memset(c, 0, sizeof(c));
        memset(sum, 0, sizeof(sum));

        scanf("%d%d", &N, &Q);

        scanf("%d%d%d%d%d%d", &X[1], &X[2], &A, &B, &C, &M);
        for(int i = 3; i <= N; ++i) {
            X[i] = ((ll)A*X[i-1]+(ll)B*X[i-2]+C)%M;
        }
        scanf("%d%d%d%d%d%d", &Y[1], &Y[2], &A, &B, &C, &M);
        for(int i = 3; i <= N; ++i) {
            Y[i] = ((ll)A*Y[i-1]+(ll)B*Y[i-2]+C)%M;
        }
        scanf("%d%d%d%d%d%d", &Z[1], &Z[2], &A, &B, &C, &M);
        for(int i = 3; i <= Q; ++i) {
            Z[i] = ((ll)A*Z[i-1]+(ll)B*Z[i-2]+C)%M;
        }

        for(int i = 1; i <= N; ++i) {
            L[i] = min(X[i], Y[i]) + 1;
            R[i] = max(X[i], Y[i]) + 1;
        }
        for(int i = 1; i <= Q; ++i) {
            K[i] = Z[i] + 1;
        }

        for(int i = 1; i <= N; ++i) {
            b[i] = L[i];
            b[i+N] = R[i]+1;
        }
        sort(b+1, b+2*N+1);
        int m = unique(b+1, b+2*N+1) - b - 1;

        for(int i = 1; i <= N; ++i) {
            int l = lower_bound(b+1, b+m+1, L[i]) - b;
            ++c[l];
            int r = lower_bound(b+1, b+m+1, R[i]+1) - b;
            --c[r];
        }

        for(int i = 1; i < m; ++i) {
            c[i] += c[i-1];
            sum[i] = (ll) c[i] * (b[i+1] - b[i]) + sum[i-1];
        }
        c[m] += c[m-1];
        sum[m] = sum[m-1];

        ll ans = 0;
        for(int i = 1; i <= Q; ++i) {
            ans += (ll)i * bin(m, K[i]);
        }
        printf("Case #%d: %I64d\n", ca, ans);

    }
    return 0;
}
