#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, n, m, mx=0, sum=0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        sum += x;
        mx = max(mx, x);
    }

    if(sum+m-mx*n>0) x = (sum+m-mx*n+n-1)/n;
    else x = 0;

    printf("%d %d\n", mx+x, mx+m);
    return 0;
}
