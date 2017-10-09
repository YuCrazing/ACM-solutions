/*
    dfs, 拓扑排序都可以
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int C = 26;

struct Node {
    int mx, pos, fa, go[C], in;
    bool pre;
};

struct SAM {

    Node no[N<<1];
    int tol, cnt[N];

    int newNode(int _mx=-1, int _fa=-1, int *_go=NULL) {
        no[tol].mx = _mx;
        no[tol].fa = _fa;
        no[tol].pos = no[tol].pre = no[tol].in=0;
        if(_go) for(int i = 0; i < C; i++) no[tol].go[i] = _go[i];
        else for(int i = 0; i < C; i++) no[tol].go[i] = -1;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode(0);
    }

    int split(int x, int len) {
        int y = newNode(len, no[x].fa, no[x].go);
        no[x].fa = y;
        return y;
    }

    int add(int u, char ch) {
        int c = ch-'a';
        int v = u;
        int z = newNode(no[u].mx+1);
        no[z].pre = true;
        while(v!=-1&&no[v].go[c]==-1) {
            no[v].go[c]=z;
            v=no[v].fa;
        }
        if(v==-1) {
            no[z].fa=0;
            return z;
        }

        int x = no[v].go[c];
        if(no[x].mx==no[v].mx+1) {
            no[z].fa=x;
            return z;
        }

        int y = split(x, no[v].mx+1);
        no[z].fa=y;

        int w = v;
        while(w!=-1&&no[w].go[c]==x) {
            no[w].go[c]=y;
            w=no[w].fa;
        }
        return z;
    }

    void build(char *s) {
        int cur = 0;
        for(int i = 0; s[i]; i++) cur = add(cur, s[i]);
    }

//
//    int dfs(int u) {
//        no[u].pos = no[u].pre;
//        for(int i = 0; i < no[u].son.size(); i++) {
//            int v = no[u].son[i];
//            no[u].pos += dfs(v);
//        }
//        return no[u].pos;
//    }

    void topo() {
        queue<int> q;
        for(int i = 1; i < tol; i++) if(!no[i].in) q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(no[u].pre) no[u].pos++;
            int fa = no[u].fa;
            no[fa].in--;
            no[fa].pos += no[u].pos;
            if(!no[fa].in && fa) {
                q.push(fa);
            }
        }
    }

    void solve(int len) {
        for(int i = 1; i < tol; i++) {
            no[no[i].fa].in++;
        }
        //dfs(0);
        topo();
        for(int i = 0; i <= len; i++) cnt[i] = 0;
        for(int i = 0; i < tol; i++) {
            cnt[no[i].mx] = max(cnt[no[i].mx], no[i].pos);
        }
        for(int i = len; i > 0; i--) cnt[i] = max(cnt[i], cnt[i+1]);
        for(int i = 1; i <= len; i++) printf("%d\n", cnt[i]);
    }
} sam;

char s[N];

int main() {
    while(scanf("%s", s)!=EOF) {
        sam.init();
        sam.build(s);
        sam.solve(strlen(s));
    }
    return 0;
}
