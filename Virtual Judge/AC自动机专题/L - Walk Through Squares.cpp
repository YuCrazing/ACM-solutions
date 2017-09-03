/*
    注意：swap(n, m)
    AC自动机 bfs 之后，一个字符串在图上走的时候，经过的节点都是此时前缀的最长后缀。
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 205;
const int C = 2;
const int mod = 1000000007;

inline int getid(char ch) {
    if(ch == 'R') return 0;
    return 1;
}

struct Node {
    int son[C], next, end;
};

struct AC {

    Node no[N];
    int tol;

    int newNode() {
        memset(no[tol].son, 0, sizeof(no[tol].son));
        no[tol].next = no[tol].end = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(char *s, int id) {
        int cur = 0;
        for(int i = 0; s[i]; i++) {
            int &son = no[cur].son[getid(s[i])];
            if(!son) son = newNode();
            cur = son;
        }
        no[cur].end |= id;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < C; i++) if(no[0].son[i]) q.push(no[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            int nex = no[fa].next;
            no[fa].end |= no[nex].end;
            for(int i = 0; i < C; i++) {
                int &son = no[fa].son[i];
                if(!son) {
                    son = no[nex].son[i];
                    continue;
                }
                no[son].next = no[nex].son[i];
                no[son].end |= no[fa].end;
                q.push(son);
            }
        }
//        for(int i = 0; i < tol; i++) {
//            printf("%d: %d %d\n", i, no[i].next, no[i].end);
//            for(int j = 0; j < C; j++){
//                printf("%2d: %3d\n", j, no[i].son[j]);
//            }
//        }
    }
} ac;

void add(int &a, int b) {
    a += b;
    if(a > mod) a -= mod;
}

char s[105];
int T, n, m, dp[102][102][N][4];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        swap(n, m); // Orz!!!!!!!!!
        ac.init();
        scanf("%s", s);
        ac.insert(s, 1);
        scanf("%s", s);
        ac.insert(s, 2);
        ac.bfs();

        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 1;

        for(int i = 0; i <= n; i++) // WA: i < n !!
            for(int j = 0; j <= m; j++) // WA: j < m !!
                for(int k = 0; k < ac.tol; k++)
                    for(int l = 0; l < 4; l++) {
                        int nex = ac.no[k].son[0];
                        add(dp[i][j+1][nex][l | ac.no[nex].end], dp[i][j][k][l]);
                        nex = ac.no[k].son[1];
                        add(dp[i+1][j][nex][l | ac.no[nex].end], dp[i][j][k][l]);
                    }
        int ans = 0;
        for(int i = 0; i < ac.tol; i++) add(ans, dp[n][m][i][3]);
        printf("%d\n", ans);
    }
    return 0;
}
/*

100
2 2
R
D

*/
