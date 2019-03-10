// 写法还可以优化

#include <bits/stdc++.h>
using namespace std;

const int M = 2222;
const int N = 1e6 + 5;
int a[N], cnt[M];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    int l = 1, r = 0;

    int diff = m;

    int ans = 1000000000;

    for(; l <= n; ++l) {

        if(r < l) {
            r = l;
            ++cnt[a[r]];
            if(a[r] && cnt[a[r]] == 1) --diff;
            if(!diff) ans = min(ans, r-l+1);
        }

        while(r < n && diff) {
            ++r;
            ++cnt[a[r]];
            if(a[r] && cnt[a[r]] == 1) --diff;
            if(!diff) ans = min(ans, r-l+1);
        }
//        printf("%d %d\n", l, r);
        if(!diff) ans = min(ans, r-l+1);

        --cnt[a[l]];
        if(a[l] && cnt[a[l]] == 0) ++diff;
    }

    if(ans == 1000000000) ans = -1;
    printf("%d\n", ans);

    return 0;
}

