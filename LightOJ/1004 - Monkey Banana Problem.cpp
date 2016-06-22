#include <cstdio>
#include <algorithm>
using namespace std;

int a[222][111];
int main() {
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {

        scanf("%d", &n);
        for(int i = 1; i <= 2 * n - 1; i ++)
            for(int j = 1; j <= min(i, 2 * n - i); j ++)
                scanf("%d", &a[i][j]);

        for(int i = 2; i <= 2 * n - 1; i ++) {
            for(int j = 1; j <= min(i, 2 * n - i); j ++) {
                if(i > n) a[i][j] += max(a[i - 1][j], a[i - 1][j + 1]);
                else {
                    if(j == 1) a[i][j] += a[i - 1][j];
                    else if(j == i) a[i][j] += a[i - 1][j - 1];
                    else a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
                }
            }
        }
        printf("Case %d: %d\n", cas, a[2 * n - 1][1]);
    }
    return 0;
}
