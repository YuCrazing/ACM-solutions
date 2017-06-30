#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N], aa[N], remap[N], cnt[N], n;
int main() {
    while(scanf("%d", &n) != EOF) {

        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            aa[i] = a[i];
        }
        sort(aa, aa + n);
        unique(aa, aa + n);
        for(int i = 0; i < n; i++) {
            int t = lower_bound(aa, aa + n, a[i]) - aa;
            remap[t] = a[i];
            cnt[t]++;
        }
        int ans;
        for(int i = 0; i < n; i++) {
            if(cnt[i] >= (n+1)/2) {
                ans = remap[i];
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
