#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        int sum = 0;
        int x;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &x);
            sum += x;
        }
        int ans = 0;
        if(n == 1) {
            ans = (sum > 1 ? 1 : 0);
        } else {
            ans = sum / 2;
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
