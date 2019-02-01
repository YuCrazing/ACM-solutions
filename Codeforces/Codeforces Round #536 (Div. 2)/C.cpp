#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;


int a[300003];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a+n);
    ll sum = 0;
    for(int i = 0; i < n/2; ++i) {
        ll t = a[i] + a[n-1-i];
        sum += t*t;
    }
    printf("%lld\n", sum);
    return 0;
}

