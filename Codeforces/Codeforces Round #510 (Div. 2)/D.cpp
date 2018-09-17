#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+5;
int a[N];
ll sum[N], sumb[N], b[2*N], c[N*2];

int low(int x) {
    return x&(-x);
}

void add(int a) {
    for(int i = a; i < 2*N; i+=low(i)) c[i]++;
}

ll ask(int a) {
    ll r = 0;
    for(int i = a; i > 0; i-=low(i)) r+=c[i];
    return r;
}

int main() {
    int n;
    ll t;
    memset(c, 0, sizeof(c));
    scanf("%d%I64d", &n, &t);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(i) sum[i] = sum[i-1]+a[i];
        else sum[i] = a[i];
        sumb[i]=sum[i]+t;
        b[i]=sum[i];
        b[i+n]=sum[i]+t;
    }
    b[2*n]=t;
    sort(b, b+2*n+1);
    for(int i = 0; i < n; ++i) {
        sum[i] = lower_bound(b, b+2*n+1, sum[i])-b+1;
        sumb[i] = lower_bound(b, b+2*n+1, sumb[i])-b+1;
    }
    t = lower_bound(b, b+2*n+1, t)-b+1;
    ll ans = 0;
    for(int i = n-1; i >= 0; --i) {
        ll lnum = i?sumb[i-1]:t;
        add(sum[i]);
        ans += ask(lnum-1);
    }
    printf("%I64d\n", ans);
    return 0;
}
