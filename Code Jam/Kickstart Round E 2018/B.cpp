#include <bits/stdc++.h>
using namespace std;

const int C = 2;
const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;

queue<int> Q;

struct Node {
    int next, son[N];
    bool bad;
};

struct AC {

    Node no[N];
    int tol;

    int newNode() {
        no[tol].next = no[tol].bad = 0;
        memset(no[tol].son, 0, sizeof(no[tol].son));
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(char * s) {
        int cur = 0;
        for(int i = 0; s[i]; ++i) {
            int &son = no[cur].son[s[i]-'0'];
            if(!son) {
                son = newNode();
            }
            cur = son;
        }
        no[cur].bad = true;
    }

    void bfs() {
        while(!Q.empty()) Q.pop();
        for(int i = 0; i < C; ++i) if(no[0].son[i]) Q.push(no[0].son[i]);
        while(!Q.empty()) {
            int fa = Q.front();
            int nex = no[fa].next;
            Q.pop();
            for(int i = 0; i < C; ++i) {
                int & son = no[fa].son[i];
                if(!son) {
                    son = no[nex].son[i];
                } else {
                    no[son].next = no[nex].son[i];
                    Q.push(son);
                }
            }
        }
    }
} ac;

char s[111];
int dig[111][2], dp[105][10005];

int main() {

    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);

    int T, n, m, p;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {

        scanf("%d%d%d", &n, &m, &p);

        for(int i = 1; i <= p; ++i) dig[i][0] = dig[i][1] = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            for(int j = 0; s[j]; ++j) {
                ++dig[j+1][s[j]-'0'];
            }
        }

        ac.init();

        for(int i = 0; i < m; ++i) {
            scanf("%s", s);
            ac.insert(s);
        }

        ac.bfs();

        for(int i = 0; i <= p; ++i)
            for(int j = 0; j < ac.tol; ++j)
                dp[i][j] = INF;

        dp[0][0] = 0;

        for(int i = 0; i < p; ++i) {
            for(int j = 0; j < ac.tol; ++j) {
                if(ac.no[j].bad) continue;
                for(int k = 0; k < 2; ++k) {
                    int nex = ac.no[j].son[k];
                    if(ac.no[nex].bad) continue;
                    dp[i+1][nex] = min(dp[i+1][nex], dp[i][j] + dig[i+1][1-k]);
                }
            }
        }

        int ans = INF;
        for(int i = 0; i < ac.tol; ++i) {
            if(ac.no[i].bad) continue;
            ans = min(ans, dp[p][i]);
        }

        printf("Case #%d: %d\n", ca, ans);

    }
    return 0;
}
