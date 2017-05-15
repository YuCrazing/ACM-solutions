#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point() {};
    Point(int _x, int _y): x(_x), y(_y) {};
} pos[8];

const int INF = 1e9;

int tol = 0, vis[8], res[100][8], dp[1 << 8], dis[8][8][8][8];
char s[10];

void print(int k) {
    printf("--- %d \n", k);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(res[k][i] == j) {
                printf("Q");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("---\n");
}

bool ok(int x, int y) {
    for(int i = 0; i < x; i++) if(vis[i] == y || x - i == y - vis[i] || x - i == vis[i] - y) return false;
    return true;
}

void dfs(int x) {
    if(x == 8) {
        for(int i = 0; i < 8; i++) res[tol][i] = vis[i];
        print(tol);
        tol++;
        return ;
    }
    for(int y = 0; y < 8; y++) {
        if(!ok(x, y)) continue;
        vis[x] = y;
        dfs(x + 1);
    }
}

/* ??? */
int d(int x1, int y1, int x2, int y2) {

    int& d1 = dis[x1][y1][x2][y2];
    int& d2 = dis[x2][y2][x1][y1];

    if(d1 != -1) return d1;

    int ans;
    if(x1 == x2 && y1 == y2) ans = 0;
    else if(x1 == x2 || y1 == y2 || x1 - x2 == y1 - y2 || x1 - x2 == y2 - y1) {
        ans = 1;
    } else ans = 2;

    d1 = d2 = ans;
    return ans;
}

void init() {
    memset(dis, -1, sizeof(dis));
    dfs(0);
    dp[0] = 0;
}

int search(int row, int s, int resid) {
    if(dp[s] != INF) {
        return dp[s];
    }
    for(int i = 0; i < 8; i++) {
        if(s & (1<<i)) {
            dp[s] =
                min(dp[s], search(row - 1, s ^ (1<<i), resid) + d(pos[i].x, pos[i].y, row, res[resid][row]));
        }
    }
    return dp[s];
}

int solve() {
    int ans = INF;
    for(int k = 0; k < tol; k++) {
        for(int i = 1; i < (1<<8); i++) dp[i] = INF;
        int step = search(7, (1<<8) - 1, k);
        ans = min(ans, step);
        printf("step: %d\n", step);
        if(step > 8){
            print(k);
        }
    }
    return ans;
}

int main() {

    init();

    int T, n;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        n = 0;
        for(int i = 0; i < 8; i++) {
            scanf("%s", s);
            for(int j = 0; j < 8; j++)
                if(s[j] == 'q') pos[n++] = Point(i, j);
        }
        printf("Case %d: %d\n", ca, solve());
    }
    return 0;
}
