#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5;
int a[N], s, n;
ll b[N];

ll check(int x) {
    b[0] = 0;
    for(int i = 1; i <= n; i++) b[i] = a[i] + ll(x) * ll(i);
    sort(b + 1, b + n + 1);
    ll sum = 0;
    for(int i = 1; i <= x; i++) sum += b[i];
    return sum;
}

int BS(int& res) {
    int l = 0, r = n;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(mid) <= s) l = mid;
        else r = mid - 1;
    }
    res = check(l);
    return l;
}
int main() {
    scanf("%d%d", &n, &s);
    for(int i = 1; i<= n; i++) scanf("%d", &a[i]);
    int ans;
    int k = BS(ans);
    printf("%d %d\n", k, ans);
    return 0;
}
