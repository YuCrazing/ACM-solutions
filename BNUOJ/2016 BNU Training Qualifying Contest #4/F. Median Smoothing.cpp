#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

const int MAXN = 500000 + 10;
int a[MAXN];
void solve(int s, int t) {
    for(int i = 1; ; i ++) {
        int l = s + i, r = t - i;
        if(l > r) return ;
        int lc = a[l], rc = a[r];
        if(a[l - 1] != a[l] && a[l + 1] != a[l]) lc = 1 - lc;
        if(a[r - 1] != a[r] && a[r + 1] != a[r]) rc = 1 - rc;
        a[l] = lc;
        a[r] = rc;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int sum = 0, cnt = 0;
    int las = 0;
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i ++) if(i > 0 && i < n - 1) {
            if(a[i - 1] != a[i] && a[i + 1] != a[i]) cnt++;
            else {
                sum = max((cnt + 1) / 2, sum);
                cnt = 0;
                if(a[i] == a[i - 1]) {
                    las = i;
                } else {
                    solve(las, i);
                }
            }
        }
    sum = max(sum, (cnt + 1) / 2);
    solve(las, n - 1);


    printf("%d\n", sum);
    for(int i = 0; i < n; i ++) printf((i == n - 1) ? "%d\n" : "%d ", a[i]);
    return 0;
}
