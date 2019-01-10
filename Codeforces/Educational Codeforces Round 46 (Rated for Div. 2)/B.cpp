#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int a[N], sum[N];
int main() {
    int n, M;
    scanf("%d%d", &n, &M);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i+1]);
    a[0]=0;
    a[n+1]=M;
    n+=2;
    sum[n-1]=0;
    for(int i = n-2; i >=0; --i) {
        if(i&1) sum[i] = sum[i+1];
        else sum[i] = sum[i+1] + a[i+1]-a[i];
    }
    int ans = sum[0];
    for(int i = 0; i < n-1; ++i) {
        if(a[i+1]-1!=a[i]) ans = max(ans, M-a[i+1]-sum[i+1]+sum[0]-sum[i]+a[i+1]-a[i]-1);
    }
    printf("%d", ans);
    return 0;
}
