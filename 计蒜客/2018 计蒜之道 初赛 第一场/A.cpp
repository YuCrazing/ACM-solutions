#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N=20002;
ll s, p, n, a[N];

bool ok(int x) {
    int i = n-1;
    ll sum=0;
    while(i>=0) {
        if(a[i]>x) sum += p*(a[i]-x);
        --i;
    }
    return sum <= s;

}

int bs() {
    int l=1, r=a[n-1];
    while(l<r) {
        int mid=(l+r)>>1;
        if(ok(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}
int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    scanf("%lld%lld", &p, &s);
    sort(a, a+n);
    printf("%d\n", bs());

    return 0;
}
