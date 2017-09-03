#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
const int C = 4;

int id[128];

struct Node {
    int son[C], next;
    bool bad;
};

struct AC {

    Node no[N];
    int tol;

    int newNode() {
        memset(no[tol].son, 0, sizeof(no[tol].son));
        no[tol].next = no[tol].bad = 0;
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
        no[cur].bad = true;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < C; i++) if(no[0].son[i]) q.push(no[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            int nex = no[fa].next;
            if(no[nex].bad) no[fa].bad = true;
            for(int i = 0; i < C; i++) {
                int &son = no[fa].son[i];
                if(!son) {
                    son = no[nex].son[i];
                    continue;
                }
                no[son].next = no[nex].son[i];
                if(no[fa].bad) no[son].bad = true;
                q.push(son);
            }
        }
    }
} ac;

void init() {
    id['A'] = 0;
    id['C'] = 1;
    id['G'] = 2;
    id['T'] = 3;
}

char s[N];
int dp[N][N];

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

        scanf("%s", s+1);
        int l = strlen(s+1);
        for(int i = 1; i <= l; i++) s[i] = id[s[i]];

        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < ac.tol; j++) {
                if(dp[i][j]==-1) continue;
                if(ac.no[j].bad) continue;
                for(int k = 0; k < C; k++) {
                    int nex = ac.no[j].son[k];
                    if(ac.no[nex].bad) continue;
                    int &dpp = dp[i+1][nex];
                    if(s[i+1]!=k) {
                        if(dpp==-1) dpp = dp[i][j] + 1;
                        else dpp = min(dpp, dp[i][j]+1);
                    } else {
                        if(dpp==-1) dpp = dp[i][j];
                        else dpp = min(dpp, dp[i][j]);
                    }
                }
            }
        }
        int ans = 1e9;
        for(int i = 0; i < ac.tol; i++) if(!ac.no[i].bad && dp[l][i]!=-1) ans = min(ans, dp[l][i]);
        if(ans == 1e9) ans = -1;
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
