#include <cstdio>
#include <algorithm>
using namespace std;

int y[50000];
int main() {
    int T, n, w, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &w);
        for(int i = 0; i < n; i ++) scanf("%d%d",&x, &y[i]);
        sort(y, y + n);
        int sum = 0, j;
        for(int i = 0; i < n; ) {
            sum ++;
            for(j = i + 1; j < n; j ++) if(y[j] - y[i] > w) break;
            if(j == n - 1 && y[j] - y[i] <= w) break;
            i = j;
        }
        printf("Case %d: %d\n", cas, sum);
    }
    return 0;
}
