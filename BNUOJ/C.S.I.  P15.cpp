#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;

char mp[33][33];
int dir[14][2] {
    -1, 0,
    -1, -1,
    -1, 1,
    0, -1,
    0, 1,
    1, -1,
    1, 1,
    2, -1,
    2, 1,
    3, -1,
    3, 1,
    4, -1,
    4, 1,
    4, 0
};
int step[8][2] {
    -1, -1,
    -1, 0,
    -1, 1,
    0, -1,
    0, 1,
    1, -1,
    1, 0,
    1, 1,
};
bool vis[33][33];
int T, n, m, bird, flower;
bool out(int x, int y) {
    return (x >= n || x < 0 || y >= m || y < 0);
}
bool emp(int x, int y) {
    if(out(x, y)) return true;
    if(mp[x][y] == '.') return true;
    return false;
}
bool isbird(int x, int y) {
    if(out(x, y)) return false;
    if(out(x, y + 3)) return false;
    if(mp[x][y] != '/' || mp[x][y + 2]  != '/' || mp[x][y + 1] != '\\' || mp[x][y + 3] != '\\')
        return false;
    for(int i = 0;  i < 14; i ++) if(!emp(x + dir[i][1], y + dir[i][0])) return false;
    return true;
}
bool may(int x, int y) {
    return (mp[x][y] == '@' || mp[x][y] == '-' || mp[x][y] == '\\' || mp[x][y] == '/' || mp[x][y] == '|');
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for(int i = 0; i < 8; i ++) {
        int xx = x + step[i][0];
        int yy = y + step[i][1];
        if(out(xx, yy)) continue;
        if(vis[xx][yy] || !may(xx, yy)) continue;
        dfs(xx, yy);
    }
}
int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%s", mp[i]);
        bird = flower = 0;
        if(n > 1) {
            memset(vis, 0, sizeof(vis));
            for(int i = 0; i < n - 1; i ++)
                for(int j = 0; j < m; j ++)
                    if(isbird(i, j)) bird ++;
            for(int j = 0; j < m; j ++) {
                if(may(n - 2, j) && !vis[n - 2][j]) {
                    flower ++;
                    dfs(n - 2, j);
                }
            }
        }
        printf("Flowers: %d\nBirds: %d\n", flower, bird);
    }
}
