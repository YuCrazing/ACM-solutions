#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e19;
const int N = 1e5 + 2;


ll sum[N];
int a[N], b[N], n;
int main() {

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    int sgn = 1;
    sum[0] = 0;
    for(int i = 0; i < n - 1; i++) {
        b[i + 1] = sgn * abs(a[i + 1] - a[i]);
        sgn *= -1;
        sum[i + 1] =  b[i + 1] + sum[i];
    }
    n --;

    ll maxx = -INF, minn = INF;
    for(int i = 1; i <= n; i++) {
        if(sum[i] > maxx) maxx = sum[i];
        if(sum[i] < minn) minn = sum[i];
    }

    printf("%I64d\n", maxx - minn);
    return 0;
}
