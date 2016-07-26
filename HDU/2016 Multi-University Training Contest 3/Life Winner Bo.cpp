/*
    1.king: dfs
    2.rook: first wins when n != m, first loses when n == m;
    3.knight: dfs, when a situation can't win, try to tie.
    4.queue: pre-process(Down-To-Top) all positions in O(n^2).
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int N = 1000;
int mp[5][MAXN][MAXN];
int dir3[2][2] = {
    1, 2,
    2, 1
};
int dir1[3][2] = {
    1, 0,
    0, 1,
    1, 1
};

int n, m;

bool ok(int x, int y) {
    return x > 0 && x <= N && y > 0 && y <= N;
}

int dfs(int x, int y, int k) {
    if(mp[k][x][y] != -1) return mp[k][x][y];
    if(x == N && y == N) return mp[k][x][y] = 0;
    int xx, yy;
    bool fail = 0, tie = 0;
    if(k == 1) {
        /*king*/
        for(int j = 0; j < 3; j ++) {
            xx = x + dir1[j][0];
            yy = y + dir1[j][1];
            if(ok(xx, yy)) {
                if(dfs(xx, yy, k) == 0) fail = 1;
            }
        }

        if(fail) return  mp[k][x][y] = 2;
        else return mp[k][x][y] = 0;

    } else if(k == 3) {
        /*knight*/
        int son = 0;
        for(int j = 0; j < 2; j ++) {
            xx = x + dir3[j][0];
            yy = y + dir3[j][1];
            if(ok(xx, yy)) {
                son ++;
                int t = dfs(xx, yy, k);
                if(t == 0) fail = 1;
                else if(t == 1) tie = 1;
            }
        }
        if(son == 0) return mp[k][x][y] = 1;
        if(fail) return mp[k][x][y] = 2;
        else if(tie) return mp[k][x][y] = 1;
        else return mp[k][x][y] = 0;
    }

}
void init() {
    memset(mp, -1, sizeof(mp));

    /*queue. Precess all positions in O(n^2)*/

    for(int i = N; i > 0; i --)
        for(int j = N; j > 0; j --)
            if(mp[4][i][j] == -1) {
                mp[4][i][j] = 0;
                for(int k = 1; ; k ++) {
                    if(i - k < 1) break;
                    mp[4][i - k][j] = 1;
                }
                for(int k = 1; ; k ++) {
                    if(j - k < 1) break;
                    mp[4][i][j - k] = 1;
                }
                for(int k = 1; ; k ++) {
                    if(j - k < 1) break;
                    if(i - k < 1) break;
                    mp[4][i - k][j - k] = 1;
                }
            }

}
int main() {
    init();

    int T, k;
    scanf("%d", &T);
    while(T --) {
        scanf("%d%d%d", &k, &n, &m);
        if(k == 2) {
            /*rook*/
            if(n == m) printf("G\n");
            else printf("B\n");
        } else if(k == 4) {
            if(mp[4][N - n + 1][N - m + 1]) printf("B\n");
            else printf("G\n");
        } else {
            int t = dfs(N - n + 1, N - m + 1, k);
            if(t == 2) printf("B\n");
            else if(t == 1) printf("D\n");
            else printf("G\n");
        }

    }
    return 0;
}
