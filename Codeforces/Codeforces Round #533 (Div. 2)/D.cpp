/*
    1. 想清楚思路再动手，这道题目显然使用 bfs 更合适（多源，距离源点不超过一个固定距离）
    2. 所有玩家的区域均不扩大时停止循环，此时棋盘并不一定所有位置都被占据
    3. 不要在 bfs 中新建 queue 对象，bfs 最多会被调用一百万次，新建一百万次 queue 对象会超时（本地无法测出具体时间差为多少）
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

const int N = 1011;
int dir[4][2]= {
    {
        1, 0
    },
    {
        -1, 0
    },
    {
        0, 1
    },
    {
        0, -1
    }
};
char mp[N][N];
vector< pair<int,int> > pos[10];
queue< pair<int,int> > Q;
int n, m, p, v[10], ans[10], step[N][N];
bool valid(int x, int y, int id) {
    return (1 <= x && x <= n && 1 <= y && y <= m && mp[x][y] == '.');
}

bool bfs(int id) {

    // 判断是否更新
    bool update = false;

//    queue< pair<int,int> > Q;

    while(!Q.empty()) Q.pop();

    for(auto item : pos[id]) {
        Q.push(item);
        step[item.fi][item.se] = 0;
    }

    pos[id].clear();

    while(!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        if(step[u.fi][u.se] >= v[id]) break;
        for(int i = 0; i < 4; ++i) {
            pair<int,int> v{u.fi+dir[i][0], u.se+dir[i][1]};
            if(valid(v.fi, v.se, id)) {
                Q.push(v);
                pos[id].push_back(v);
                step[v.fi][v.se] = step[u.fi][u.se] + 1;
                mp[v.fi][v.se] = id + '0';
                update = true;
            }
        }
    }

    return update;
}

int main() {
//    freopen("in.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= p; ++i) scanf("%d", &v[i]);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", mp[i]+1);
        for(int j = 1; j <= m; ++j) {
            if(mp[i][j] >= '0' && mp[i][j] <= '9') {
                pos[mp[i][j]-'0'].push_back({i, j});
            }
        }
    }

    while(1) {
        // 若所有玩家均未更新，停止循环
        bool stop = true;
        for(int i = 1; i <= p; ++i) {
            if(bfs(i)) stop = false;
        }
        if(stop) break;
    }

//    for(int i = 1; i <= n; ++i) {
//        for(int j = 1; j <= m; ++j) {
//            printf("%c", mp[i][j]);
//        }
//        printf("\n");
//    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(mp[i][j] >= '0' && mp[i][j] <= '9') {
                ++ans[mp[i][j]-'0'];
            }
        }
    }

    for(int i = 1; i <= p; ++i) printf("%d ", ans[i]);

    return 0;
}
