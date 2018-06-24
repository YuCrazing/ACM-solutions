/*
    一开始的想法是从最外面开始搜索，暴露在外面的就是不会被覆盖的。
    这个想法是错误的，最下面的样例是反例，'C' 没有暴露在外面，但是也不会被覆盖。
    一个字母【是否会被覆盖】是不容易判断的。
    一个字母【自身覆盖的范围】是容易判断的。
    （考虑只保留一种字母，从最外面往里搜索，被该字母挡住的地方就是该字母覆盖的范围）
*/

#include<bits/stdc++.h>
using namespace std;

struct P {
    int x, y;
    P(int _x=0, int _y=0):x(_x), y(_y) {};
    P operator+(const P& t)const {
        return P(x+t.x, y+t.y);
    }
};

//P dir[4]= {
//    (-1, 0),
//    (0, -1),
//    (1, 0),
//    (0, 1)
//}; // 写成这样会错得很惨

P dir[4]= {
    P(-1, 0),
    P(0, -1),
    P(1, 0),
    P(0, 1)
};

bool vis[55][55];
char mp[55][55];
int n, m, T;

bool ok(P t) {
    return t.x<n && t.x>=0 && t.y<m && t.y>=0;
}

void dfs(P u, char ch) {
    vis[u.x][u.y]=true;
    for(int i = 0; i < 4; ++i) {
        P v = u+dir[i];
        if(ok(v) && mp[v.x][v.y]!=ch && !vis[v.x][v.y])
            dfs(v, ch);
    }
}

void process(char ch) {

    memset(vis, 0, sizeof(vis));

    for(int i = 0; i < n; ++i)
        if(!vis[i][0] && mp[i][0]!=ch)
            dfs(P(i, 0), ch);

    for(int i = 0; i < n; ++i)
        if(!vis[i][m-1] && mp[i][m-1]!=ch)
            dfs(P(i, m-1), ch);

    for(int j = 0; j < m; ++j)
        if(!vis[0][j] && mp[0][j]!=ch)
            dfs(P(0, j), ch);

    for(int j = 0; j < m; ++j)
        if(!vis[n-1][j] && mp[n-1][j]!=ch)
            dfs(P(n-1, j), ch);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(!vis[i][j]) mp[i][j] = ch;
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &m);

        for(int i = 0; i < n; ++i) scanf("%s", mp[i]);

        for(char ch = 'A'; ch <= 'Z'; ++ch) process(ch);

        printf("Case %d:\n", ca);
        for(int i = 0; i < n; ++i) puts(mp[i]);
    }
}

/*

100

5 5
AAAAA
ACCCA
BC.CB
BCCCB
BBBBB

*/
