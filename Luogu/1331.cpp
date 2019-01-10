#include<bits/stdc++.h>
using namespace std;

const int N=1011;
char mp[N][N];
bool vis[N][N];
int n, m;
int dx[4]= {0, 0, -1, 1};
int dy[4]= {1, -1, 0, 0};

bool check(int i, int j) {
    bool ok = true;
    if(i > 0 && j > 0) {
        int ct=0;
        if(mp[i-1][j-1]=='#') ++ct;
        if(mp[i][j-1]=='#') ++ct;
        if(mp[i-1][j]=='#') ++ct;
        if(mp[i][j]=='#') ++ct;
        if(ct==3) ok=false;
    }
    return ok;

}

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && mp[i][j]=='#';
}

void dfs(int x, int y) {
    vis[x][y]=true;
    for(int i = 0; i < 4; ++i) {
        int vx = x + dx[i];
        int vy = y + dy[i];
        if(valid(vx, vy)) dfs(vx, vy);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)scanf("%s", mp[i]);

    bool ok = true;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(!check(i, j)) {
                ok=false;
                break;
            }
    if(ok) {
        int ans=0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(valid(i, j)) {
                    ++ans;
                    dfs(i, j);
                }
        printf("There are %d ships.\n", ans);
    } else puts("Bad placement.");
    return 0;
}
