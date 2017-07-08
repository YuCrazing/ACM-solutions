#include<bits/stdc++.h>
using namespace std;

const int N = 252;
int c[N][N];
int main() {
    memset(c, 0, sizeof(c));
    int n, m, x1, x2, y1, y2;
    scanf("%d%d", &n, &m);
    for(int k = 1; k <= n; k++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 == x2) {
            for(int i = min(y1, y2); i <= max(y1, y2); i++) {
                c[x1][i] = k;
            }
        }
        int a = min(x1, x2);
        int b = max(x1, x2);
        int y0;

        int xx, yy;

        if(x1 > x2) {
            y0 = y2;
        } else {
            y0 = y1;
        }

        for(int i = a; i <= b; i++) {
            int dx = i - a;
            if((dx * (y1 - y2)) % (x1 - x2) == 0) {
                int dy = (dx * (y1 - y2)) / (x1 - x2);
                c[a + dx][y0 + dy] = k;
            }
        }
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", c[x][y]);
    }
    return 0;
}
