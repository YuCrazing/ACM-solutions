/*
    dp[i][j]:
    长度为i，在自动机j状态位置时的最优答案
    str[i][j]:
    dp[i][j]对应的最优字符串
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
const int C = 26;

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

    void insert(char *s, int val) {
        int cur = 0;
        for(int i = 0; s[i]; i++) {
            int &son = no[cur].son[s[i]-'a'];
            if(!son) son = newNode();
            cur = son;
        }
        assert(no[cur].val==0); //!!!
        no[cur].val += val;
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

} ac;

int T, n, m, v, tmpVal, dp[55][N];
string str[55][N], tmpStr;
char s[100][13];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);

        ac.init();
        for(int i = 0; i < m; i++) {
            scanf("%s", &s[i]);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d", &v);
            ac.insert(s[i], v);
        }
        ac.bfs();

        for(int i = 0; i <= n; i++)
            for(int j = 0; j < ac.tol; j++) {
                dp[i][j] = 0;
                str[i][j].clear();
            }

        for(int i = 0; i < C; i++) {
            int nex = ac.no[0].son[i];
            dp[1][nex] = ac.no[nex].val;
            char ch;
            if(str[1][nex].size()) ch = min(str[1][nex][0], (char)(i+'a'));
            else ch = i+'a';
            str[1][nex] = ch;
        }
        for(int i = 1; i < n; i++)
            for(int j = 0; j < ac.tol; j++) {
                if(!str[i][j].size()) continue; // !!!!
                for(int k = 0; k < C; k++) {
                    int nex = ac.no[j].son[k];
                    tmpVal = ac.no[nex].val + dp[i][j];
                    char ch = (k+'a');
                    tmpStr = str[i][j] + ch;
                    if(tmpVal > dp[i+1][nex]) {
                        dp[i+1][nex] = tmpVal;
                        str[i+1][nex] = tmpStr;
                    }
                    //注意空串
                    else if(tmpVal == dp[i+1][nex] && (tmpStr < str[i+1][nex] || str[i+1][nex] == "")) {
                        str[i+1][nex] = tmpStr;
                    }
                }
            }


//        for(int i = 0; i <= n; i++) {
//            for(int j = 0; j < ac.tol; j++)
//                if(str[i][j].size())printf("dp[%d][%d] = %d %s\n", i, j, dp[i][j], str[i][j].c_str());
//        }

        int mx = 0;
        string mi;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < ac.tol; j++) {
                if(dp[i][j] > mx) {
                    mx = dp[i][j];
                    mi = str[i][j];
                } else if(dp[i][j] == mx) {
                    if(str[i][j].size() < mi.size()) mi = str[i][j]; // 长度短者优先
                    else if(str[i][j].size() == mi.size() && str[i][j] < mi) mi = str[i][j]; // 相同长度比较字典序
                }
            }
        }

        printf("%s\n", mi.c_str());
    }
    return 0;
}
/*

100
3 2
ba
ab
2 2


*/
