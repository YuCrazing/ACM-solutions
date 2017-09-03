/*
    TLE优化方法：dp[i][j][k]每一次向后转移需要26次操作，
    而dp[i][j][k]矩阵比较稀疏，如果dp[i][j][k]==0则直接跳过，
    每一次跳过可减少26次操作。
*/

#include<cstdio>
#include<cassert>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 120;
const int C = 26;
const int S = (1<<10);
const int mod = 20090717;

inline void add(int &a, int b) {
    a += b;
    if(a > mod) a -= mod;
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
            int &son = no[cur].son[s[i]-'a'];
            if(!son) son = newNode();
            cur = son;
        }
        no[cur].end |= (1<<id);
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
    }

} ac;

char s[15];
int n, m, k, dp[2][N][S], cnt[S];

void init() {
    for(int i = 0; i < S; i++) {
        int t = i, sum = 0;
        while(t>0) {
            if(t&1) sum++;
            t >>= 1;
        }
        cnt[i] = sum;
    }
}

int main() {
    init();
    while(scanf("%d%d%d", &n, &m, &k) != EOF) {
        if(!n && !m && !k) break;
        ac.init();
        for(int i = 0; i < m; i++) {
            scanf("%s", s);
            ac.insert(s, i);
        }
        ac.bfs();
        memset(dp, 0, sizeof(dp));
        int cur = 0, pre = 1;
        dp[cur][0][0] = 1;
        for(int i = 0; i < n; i++) {
            swap(cur, pre);
            memset(dp[cur], 0, sizeof(dp[cur]));
            for(int j = 0; j < ac.tol; j++)
                for(int s = 0; s < (1<<m); s++) {
                    if(dp[pre][j][s] == 0) continue; //!!!!优化
                    for(int l = 0; l < C; l++) {
                        int nex = ac.no[j].son[l];
                        add(dp[cur][nex][s|ac.no[nex].end], dp[pre][j][s]);
                    }
                }

        }

        int ans = 0;
        for(int j = 0; j < ac.tol; j++)
            for(int s = 0; s < (1<<m); s++)
                if(cnt[s] >= k)
                    add(ans, dp[cur][j][s]);

        printf("%d\n", ans);
    }
    return 0;
}
/*

25 10 10
adsfakldfa
bdsflkhjls
hsdldfjasl
oldidkadkj
dlkjjkygsd
iuhhdkduhk
euihlkhdlk
iuhkjhkjhh
jaklsdfhjh
liygasdfad

25 10 0
a
b
c
d
e
f
g
h
i
j

*/
