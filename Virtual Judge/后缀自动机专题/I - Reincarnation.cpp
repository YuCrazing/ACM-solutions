/*
    对每个后缀做一次后缀自动机，预处理出所有答案。

    在构建后缀自动机的过程中，在当前字符串后插入一个字符，
    记该字符新建节点的编号为z，则不同的子串数量增加了no[z].mx-no[no[z].fa].mx
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
const int C = 26;

int ans[N][N];

struct Node {
    int mx, fa, go[C];
};

struct SAM {

    Node no[N<<1];
    int tol;

    int newNode(int mx=-1, int fa=-1, int *go=NULL) {
        no[tol].mx=mx;
        no[tol].fa=fa;
        if(go) for(int i = 0; i < C; i++) no[tol].go[i]=go[i];
        else for(int i = 0; i < C; i++) no[tol].go[i]=-1;
        return tol++;
    }

    void init() {
        tol=0;
        newNode(0);
    }

    int split(int x, int len) {
        int y=newNode(len, no[x].fa, no[x].go);
        no[x].fa=y;
        return y;
    }

    int add(int u, char ch) {
        int c=ch-'a';
        int z=newNode(no[u].mx+1);
        int v=u;
        while(v!=-1&&no[v].go[c]==-1) {
            no[v].go[c]=z;
            v=no[v].fa;
        }
        if(v==-1) {
            no[z].fa=0;
            return z;
        }

        int x=no[v].go[c];
        if(no[x].mx==no[v].mx+1) {
            no[z].fa=x;
            return z;
        }

        int y=split(x, no[v].mx+1);
        while(v!=-1&&no[v].go[c]==x) {
            no[v].go[c]=y;
            v=no[v].fa;
        }
        no[z].fa=y;
        return z;
    }

    void build(char *s, int l) {
        init();
        int cur = 0, cnt = 0;
        for(int i = 0; s[i]; i++) {
            cur = add(cur, s[i]);
            cnt += no[cur].mx-no[no[cur].fa].mx;
            ans[l][l+i]=cnt;
        }
    }

    void solve(char *s) {
        int l = strlen(s);
        for(int i = 0; i < l; i++) {
            build(s+i, i);
        }
    }
} sam;

int T, n, l, r;
char s[N];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%s%d", s, &n);
        sam.solve(s);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &l, &r);
            l--;
            r--;
            printf("%d\n", ans[l][r]);
        }
    }
    return 0;
}
