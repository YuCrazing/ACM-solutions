#include<bits/stdc++.h>
using namespace std;
typedef unsigned short ushort;

/* unsigned short is 16 bits, MAX_VALUE = 65536 < 1e5 */

const int N = 502;
int T, n, q;
ushort dp[N][9][N][9];

ushort max(ushort a, ushort b, ushort c, ushort d) {
    ushort x = a;
    if(b > x) x = b;
    if(c > x) x = c;
    if(d > x) x = d;
    return x;
}

void initRMQ() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> dp[i][0][j][0];
        }

    for(int xj = 1; (1<<xj) <= n; xj++) {
        for(int xi = 0; (xi + (1<<xj)) - 1 < n; xi++) {
            for(int yj = 1; (1<<yj) <= n; yj++) {
                for(int yi = 0; (yi + (1<<yj)) - 1 < n; yi++) {
                    dp[xi][xj][yi][yj] =
                        max(
                            dp[xi][xj - 1][yi][yj - 1],
                            dp[xi + (1<<(xj - 1))][xj - 1][yi][yj - 1],
                            dp[xi][xj - 1][yi + (1<<(yj - 1))][yj - 1],
                            dp[xi + (1<<(xj - 1))][xj - 1][yi + (1<<(yj - 1))][yj - 1]
                        );
                }
            }
        }
    }
}

ushort RMQ(int x1, int y1, int x2, int y2) {
    int yj = 0, xj = 0;
    while((1<<yj) <= y2 - y1 + 1) yj++;
    yj--;
    while((1<<xj) <= x2 - x1 + 1) xj++;
    xj--;

    return
        max(
            dp[x1][xj][y1][yj],
            dp[x2 - (1<<xj) + 1][xj][y2 - (1<<yj) + 1][yj],
            dp[x1][xj][y2 - (1<<yj) + 1][yj],
            dp[x2 - (1<<xj) + 1][xj][y1][yj]
        );
}

int main() {
//    freopen("1081.in", "r", stdin);
//    freopen("1081.out", "w", stdout);
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        cin >> n >> q;
        initRMQ();
//        printf("Case %d:\n", ca);
        cout << "Case " << ca << ":" << endl;
        for(int i = 0; i < q; i++) {
            int x1, y1, s;
            cin >> x1 >> y1 >> s;
//            printf("%hu\n", RMQ(x1 - 1, y1 - 1, x1 + s - 2, y1 + s - 2));
            cout << RMQ(x1 - 1, y1 - 1, x1 + s - 2, y1 + s - 2) << endl;
        }
    }
    return 0;
}
/*
2

1 1
26980
1 1 1

2 0
5275 62614
79726 96085
*/
