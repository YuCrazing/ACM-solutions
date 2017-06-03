#include<bits/stdc++.h>
using namespace std;

const int L = 204;
const int S = 20004;
const int mod = 1000000009;

struct Node {
    int son[2], next;
    bool end;
};

struct AC {
    Node node[S];
    int tol;

    int newNode() {
        memset(node[tol].son, 0, sizeof(node[tol].son));
        node[tol].next = node[tol].end = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    void insert(string s) {
        int cur = 0;
        for(int i = 0; i < s.size(); i++) {
            int& son = node[cur].son[s[i] - '0'];
            if(!son) son = newNode();
            cur = son;
        }
        node[cur].end = 1;
    }

    void bfs() {
        queue<int> q;
        for(int i = 0; i < 2; i++) if(node[0].son[i]) q.push(node[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();

            int nex = node[fa].next;

            for(int i = 0; i < 2; i++) {

                int& son = node[fa].son[i];

                if(!son) {
                    son = node[nex].son[i];
                } else {
                    node[son].next = node[nex].son[i];
                    if(node[fa].end || node[node[son].next].end) node[son].end = 1;
                    q.push(son);
                }
            }
        }
//        for(int i = 0; i < tol; i++) {
//            printf("%d: %d %d [%d %d]\n", i, node[i].next, node[i].end, node[i].son[0], node[i].son[1]);
//        }
    }

    bool search(string s) {
        int cur = 0;
        for(int i = 0; i < s.size(); i++) {
            cur = node[cur].son[s[i] - '0'];
            if(node[cur].end) return true;
        }
        return false;
    }
} ac;

int dp[L][S][2], digs[L], T, n;
string a, b, ban;

string bin[10] = {
    "0000",
    "0001",
    "0010",
    "0011",
    "0100",
    "0101",
    "0110",
    "0111",
    "1000",
    "1001"
};

string d2b(string& s) {
    string ss = "";
    for(int i = 0; i < s.size(); i++) {
        ss += bin[s[i] - '0'];
    }
    return ss;
}

void init() {
    memset(dp, -1, sizeof(dp));
    ac.init();
}

void add(int& a, int b) {
    a += b;
    if(a > mod) a -= mod;
}

int go(int cur, int x) {
    for(int i = 0; i < 4; i++) {
        cur = ac.node[cur].son[bin[x][i] - '0'];
        if(ac.node[cur].end) return -1;
    }
    return cur;
}

int dfs(int cur, int pre, int zero, int up) {

    if(!cur) {
        return 1; //
    }

    int& dpp = dp[cur][pre][zero]; // [zero] is necessary.
    if(!up && dpp != -1) return dpp;

    int sup = up ? digs[cur] : 9;

    int ans = 0;
    for(int i = 1; i <= sup; i++) {
        int nex = go(pre, i);
        if(nex != -1) {
            add(ans, dfs(cur - 1, nex, 0, up && i == digs[cur]));
        }
    }
    if(zero) {
        add(ans, dfs(cur - 1, pre, 1, up && 0 == digs[cur]));
    } else {
        int nex = go(pre, 0);
        if(nex != -1) {
            add(ans, dfs(cur - 1, nex, 0, up && 0 == digs[cur]));
        }
    }

    if(!up) dpp = ans;
    return ans;
}

int calc() {
    int la = a.size();
    for(int i = 0; i < la; i++) digs[la - i] = a[i] - '0';
    int ans1 = dfs(la, 0, 1, 1);

    int lb = b.size();
    for(int i = 0; i < lb; i++) digs[lb - i] = b[i] - '0';
    int ans2 = dfs(lb, 0, 1, 1);

    if(!ac.search(d2b(a))) ans2++;


    return (ans2 - ans1 + mod) % mod;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("in.in", "r", stdin);

    cin >> T;
    while(T--) {

        init();

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> ban;
            ac.insert(ban);
        }
        ac.bfs();
        cin >> a >> b;
        printf("%d\n", calc());
    }

    return 0;
}
