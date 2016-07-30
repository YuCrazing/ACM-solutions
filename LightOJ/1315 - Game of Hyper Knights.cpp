#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1003;
int dir[6][2] = {
    {1, -2},
    {-1, -3},
    {-1, -2},
    {-2, -1},
    {-3, -1},
    {-2, 1}
};
bool ok(int x, int y){
    return x >= 0 && y >= 0;
}
int dp[N][N], vis[10];
void init() {
    memset(vis, -1, sizeof(vis));
    for(int x = 0; x < N; x ++) {
        for(int y = 0; y < N; y ++) {
            //(x - y, y)
            if(!ok(x - y, y)) break;
            for(int k = 0; k < 6; k ++){
                int xx = (x - y) + dir[k][0];
                int yy = y + dir[k][1];
                if(ok(xx, yy)) vis[dp[xx][yy]] = (x - y) * N + y;
            }
            int i = 0;
            while(vis[i] == (x - y) * N + y) i ++;
            dp[x - y][y] = i;
        }
    }
}
int main() {
    init();
    int T, n, x, y;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        int sg = 0;
        for(int i = 0; i < n; i ++){
            scanf("%d%d", &x, &y);
            sg ^= dp[x][y];
        }

        printf("Case %d: ", cas);
        if(sg) printf("Alice\n");
        else printf("Bob\n");
    }
}
