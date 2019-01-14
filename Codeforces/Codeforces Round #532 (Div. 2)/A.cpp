#include <bits/stdc++.h>
using namespace std;

int a[111];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int mx = -1;
    for(int b = 0; b < k; ++b) {
        int r=0;
        for(int i = 0; i < n; ++i) {
            if((i-b+k)%k==0) {
                continue;
            }
            r += a[i];
        }
        mx = max(mx, abs(r));
    }
    printf("%d\n", mx);
    return 0;
}
