/*
    去掉子串，哈密尔顿路径
    （前几次WA是因为去除子串的步骤有问题，
    只判断了【新加进来的串】是否是【之前的串】的子串，
    没有判断【之前的串】是否是【新加进来的串】的子串）

    对于vector<string> words,
    unique(words.begin(), words.end())后，words.size()并没有改变，需要手动删除后面一部分重复的字符串。

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 6e4 + 5;
const int C = 2;
const int INF = 1e9;
queue<int> q;
int g[12][12], dis0[12], pos[12], vis[N], c[1<<12][1<<12], n, m;

struct Node {
    int son[C], next, s;
};

struct AC {

    Node no[N];
    int tol;

    int newNode() {
        memset(no[tol].son, 0, sizeof(no[tol].son));
        no[tol].next = no[tol].s = 0;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode();
    }

    int insert(string s, int sta) {
        int cur = 0;
        for(int i = 0; i < s.size(); i++) {
            int &son = no[cur].son[s[i]-'0'];
            if(!son) son = newNode();
            cur = son;
        }
        //assert(no[cur].s==0); // 病毒串未去重
        no[cur].s = sta;
        return cur;
    }

    void build() {
        while(!q.empty()) q.pop();
        for(int i = 0; i < C; i++) if(no[0].son[i]) q.push(no[0].son[i]);
        while(!q.empty()) {
            int fa = q.front();
            q.pop();
            int nex = no[fa].next;
            //assert(no[nex].s<=0); // 普通串可能是病毒串的子串
            if(no[nex].s == -1 || no[fa].s == -1) no[fa].s = -1;
            else no[fa].s |= no[nex].s;
            for(int i = 0; i < C; i++) {
                int &son = no[fa].son[i];
                if(!son) {
                    son = no[nex].son[i];
                    continue;
                }
                no[son].next = no[nex].son[i];
                if(no[fa].s == -1 || no[son].s == -1) no[son].s = -1;
                else no[son].s |= no[fa].s;
                q.push(son);
            }
        }
    }

    void spfa(int k) {
        memset(vis, 0, sizeof(vis));
        while(!q.empty()) q.pop();

        if(k==-1) {
            q.push(0);
            vis[0] = 1;
        } else {
            q.push(pos[k]);
            vis[pos[k]]=1;
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = 0; i < C; i++) {
                int v = no[u].son[i];
                if(no[v].s!=-1 && !vis[v]) {
                    vis[v] = vis[u]+1;
                    q.push(v);
                }
            }
        }

        if(k==-1) {
            for(int i = 0; i < n; i++) {
                assert(vis[pos[i]]!=0);
                dis0[i] = vis[pos[i]]-1;
            }
        } else {
            for(int i = 0; i < n; i++) g[k][i]=(vis[pos[i]]?vis[pos[i]]-1:INF);
        }
    }

    void proc() {

        for(int i = 0; i < 12; i++) {
            dis0[i]=INF;
            for(int j = 0; j < 12; j++)
                g[i][j]=INF;
        }

        spfa(-1); //From root
        for(int k = 0; k < n; k++) spfa(k);
    }

    void debug() {
        for(int i = 0; i < tol; i++) {
            printf("---------\n");
            printf("no[%d].next = %d\n", i, no[i].next);
            printf("no[%d].s = %d\n", i, no[i].s);
            for(int j = 0; j < C; j++) printf("  %2d\n", no[i].son[j]);
        }
        printf("------\n");
        for(int i = 0; i < n; i++) printf("dis0[%d]=%d\n", i, dis0[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                printf(j==n-1?"%d\n":"%d ", g[i][j]);
    }
} ac;

int Next[1011];

void initkmp(string s, int l) {
    int j;
    j = Next[0] = Next[1] = 0;
    for(int i = 1; i < l; i++) {
        while(j>0 && s[j]!=s[i]) j=Next[j];
        if(s[i]==s[j])j++;
        Next[i+1] = j;
    }
}

//
bool kmp(string s, int ls, string t, int lt) {
    int j = 0;
    for(int i = 0; i < lt; i++) {
        while(j>0 && s[j]!=t[i]) j=Next[j];
        if(s[j]==t[i])j++;
        if(j==ls)return true;
    }
    return false;
}

int dp[1<<12][12];

int dfs(int s, int las) {
    int &dpp = dp[s][las];
    if(dpp != -1) return dpp;
    s = s^(1<<las);
    dpp = INF;
    for(int i = 0; i < n; i++) {
        if(g[i][las]!=INF && (s&(1<<i))) dpp = min(dpp, dfs(s, i) + g[i][las]);
    }
    return dpp;
}

int solve() {
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) dp[1<<i][i] = dis0[i];
    int ans = INF;
    for(int i = 0; i < n; i++) ans = min(ans, dfs((1<<n)-1, i));
    return ans;
}

char s[50005];
string word;
vector<string> words;
bool isSub[12];

int main() {
    while(scanf("%d%d", &n, &m)) {
        if(!n && !m) break;
        ac.init();
        words.clear();
        memset(isSub, 0, sizeof(isSub));
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            word.clear();
            for(int j = 0; s[j]; j++) word += s[j];
            words.push_back(word);
        }

        sort(words.begin(), words.end());
        n = unique(words.begin(), words.end()) - words.begin();

        // unique没有改变words.size()，需要手动删除后面重复的字符串
        for(int i = words.size()-1; i >= n; i--) {
            words.erase(words.begin()+i);
        }

        for(int i = 0; i < n; i++) {
            initkmp(words[i], words[i].size());
            for(int j = 0; j < n; j++) {
                if(j==i) continue;
                bool isSub_ = kmp(words[i], words[i].size(), words[j], words[j].size());
                if(isSub_) {
                    isSub[i] = true;
                    break;
                }
            }
        }

        for(int i = n-1; i >= 0; i--) {
            if(isSub[i]) words.erase(words.begin()+i);
        }

        n = words.size();
        for(int i = 0; i < n; i++) {
            pos[i] = ac.insert(words[i], 1<<i);
            //cout << "pos = " << pos[i] << ",word: " << words[i] << endl;
        }

        for(int i = 0; i < m; i++) {
            scanf("%s", s);
            word.clear();
            for(int j = 0; s[j]; j++) word += s[j];
            ac.insert(s, -1);
        }
        ac.build();
        ac.proc();
        //ac.debug();
        printf("%d\n", solve());
    }
    return 0;
}

/*
3 3
0001
0000
10000
010
101
111

3 1
000
000
000
0000

3 1
111
110
101
1111

*/
