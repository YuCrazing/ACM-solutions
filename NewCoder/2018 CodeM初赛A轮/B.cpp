#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N*2];
int main() {
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a[i]-=x;
    }

    int l, r;
    long long sum=0;
    l=r=n-1;
    while(l>=0&&r>=0) {
        if(a[r]>0 && a[l]<0) {
            long long mi=min(a[r], -a[l]);
            sum+=(r-l)*mi;
            a[r]-=mi;
            a[l]+=mi;
        }
        while(a[r]<=0 && r>=0) --r;
        while((a[l]>=0 || l>=r) && l>=0) --l;
    }

    l=r=0;
    while(l<n&&r<n) {
        if(a[r]<0 && a[l]>0) {
            long long mi=min(-a[r], a[l]);
            sum+=(r+l)*mi;
            a[r]+=mi;
            a[l]-=mi;
        }
        if(a[l]<=0 && l<n) ++l;
        if((a[r]>=0 || r<=l) && r<n) ++r;
    }
    for(int i = 0; i < n; ++i) assert(a[i]==0);
    printf("%lld\n", sum);
    return 0;
}

