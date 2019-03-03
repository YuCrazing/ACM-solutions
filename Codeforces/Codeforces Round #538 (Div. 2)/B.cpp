#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef double db;

const int N = 2e5 + 5;
pair<int,int> a[N];
bool bad[N];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }

    sort(a+1, a+n+1);

    for(int i = 1; i <= n - m * k; ++i) {
        bad[a[i].se] = true;
    }

    ll sum = 0;
    for(int i = n - m * k + 1; i <= n; ++i) {
        sum += a[i].fi;
    }
    printf("%I64d\n", sum);

    int cnt = 0;


    // 这个写法有问题，反例参见下面的样例
//    for(int i = 1; i <= n; ++i) {
//        if(bad[i]) continue;
//        ++cnt;
//        if(cnt == m && i != n) {
//            printf("%d ", i);
//            cnt = 0;
//        }
//    }

    for(int i = 1; i <= n; ++i) {
        if(bad[i]) continue;
        ++cnt;
        if(cnt == m+1) {
            printf("%d ", i-1);
            cnt = 1;
        }
    }

    return 0;
}
/*
    5 2 2
    10 9 8 7 6
*/
