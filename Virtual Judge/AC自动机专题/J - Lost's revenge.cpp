/*
    dp[i][j][k][l][s]: i个'A', j个'C', k个'G', l个'T', 到达s节点时的最大收益
    然后Hash压缩状态
    注意重复串认为是不同的串
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 505;
const int C = 4;

int id[128];

struct Node {
    int son[C], next, val;
};

struct AC {

    Node no[N];
    int tol;

    int newNode() {
        memset(no[tol].son, 0, sizeof(no[tol].son));
        no[tol].next = no[tol].val = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(char *s) {
        int cur = 0;
        for(int i = 0; s[i]; i++) {
            int &son = no[cur].son[id[s[i]]];
            if(!son) son = newNode();
            cur = son;
        }
        no[cur].val++;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < C; i++) if(no[0].son[i]) q.push(no[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            int nex = no[fa].next;
            no[fa].val += no[nex].val;
            for(int i = 0; i < C; i++) {
                int &son = no[fa].son[i];
                if(!son) {
                    son = no[nex].son[i];
                    continue;
                }
                no[son].next = no[nex].son[i];
                q.push(son);
            }
        }
    }

    void debug() {
        for(int i = 0; i < tol; i++) {
            printf("-----\n");
            printf("no[%d].next = %d\n", i, no[i].next);
            printf("no[%d].val = %d\n", i, no[i].val);
            for(int j = 0; j < C; j++) {
                printf("%d ", no[i].son[j]);
            }
            puts("");
        }
    }

} ac;

char s[44];
int num[4], p[3], dp[20000][N];

void init() {
    id['A'] = 0;
    id['C'] = 1;
    id['G'] = 2;
    id['T'] = 3;
}

int h(int a, int b, int c, int d) {
    return a*p[1]+b*p[2]+c*p[3]+d;
}

int main() {
    init();
    int n, cas = 0;
    while(scanf("%d", &n)!=EOF && n) {
        cas++;
        ac.init();
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            ac.insert(s);
        }

        ac.bfs();

        //ac.debug();

        scanf("%s", s);
        memset(num, 0, sizeof(num));
        for(int i = 0; s[i]; i++) num[id[s[i]]]++;
        p[3] = num[3]+1;
        p[2] = (num[2]+1)*p[3];
        p[1] = (num[1]+1)*p[2];

        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 0; i <= num[0]; i++) {
            for(int j = 0; j <= num[1]; j++) {
                for(int k = 0; k <= num[2]; k++) {
                    for(int l = 0; l <= num[3]; l++) {
                        int hashval = h(i, j, k, l);
                        for(int s = 0; s < ac.tol; s++) {
                            if(dp[hashval][s]==-1) continue;
                            //printf("dp[%d][%d][%d][%d][%d] = %d\n", i, j, k, l, s, dp[hashval][s]);
                            if(i < num[0]) {
                                int nex = ac.no[s].son[0];
                                int &dpp = dp[h(i+1, j, k, l)][nex];
                                dpp = max(dpp, dp[hashval][s]+ac.no[nex].val);
                            }
                            if(j < num[1]) {
                                int nex = ac.no[s].son[1];
                                int &dpp = dp[h(i, j+1, k, l)][nex];
                                dpp = max(dpp, dp[hashval][s]+ac.no[nex].val);
                            }
                            if(k < num[2]) {
                                int nex = ac.no[s].son[2];
                                int &dpp = dp[h(i, j, k+1, l)][nex];
                                dpp = max(dpp, dp[hashval][s]+ac.no[nex].val);
                            }
                            if(l < num[3]) {
                                int nex = ac.no[s].son[3];
                                int &dpp = dp[h(i, j, k, l+1)][nex];
                                dpp = max(dpp, dp[hashval][s]+ac.no[nex].val);
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        int hashval = h(num[0], num[1], num[2], num[3]);
        for(int i = 0; i < ac.tol; i++) ans = max(ans, dp[hashval][i]);

        printf("Case %d: %d\n", cas, ans);

    }
    return 0;
}
