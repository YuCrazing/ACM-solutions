#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 55555;
int wx[MAXN], wy[MAXN];
int main() {
    int T, m, n, q;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d%d", &n, &m, &q);
        int x, y, w;
        long long sum = 0, sumw = 0;
        for(int i = 0; i < MAXN; i ++) wx[i] = wy[i] = 0;
        for(int i = 0; i < q; i ++) {
            scanf("%d%d%d", &x, &y, &w);
            wx[x] += w;
            wy[y] += w;
            sumw += w;
        }

        int posx = 1, posy = 1;
        for(int i = 1; i <= n; i ++) {
            if(sum + wx[i] - (sumw - sum - wx[i]) >= 0) {
                posx = i;
                break;
            }
            sum += wx[i];
        }

        sum = 0;
        for(int i = 1; i <= m; i ++) {
            if(sum + wy[i] - (sumw - sum - wy[i]) >= 0) {
                posy = i;
                break;
            }
            sum += wy[i];
        }

        printf("Case %d: %d %d\n", cas, posx, posy);
    }
    return 0;
}
