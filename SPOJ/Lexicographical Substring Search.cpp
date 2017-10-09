/*
    问题模型：求解在DAG上dfs过程中的第k个点，及根节点到该点的路径（有些子图会走多次）

    no[u].cnt表示以u为起点的DAG图的大小

    注意：
    1.不同子串个数可能会超出int范围
    2.拓扑排序中的t[]数组要开到2*N大小
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 90005;
const int C = 26;

int d[N], t[N<<1];

struct Node {
    int mx, fa, go[C];
    ll cnt;
};

struct SAM {

    Node no[N<<1];
    int tol;

    int newNode(int mx=-1, int fa=-1, int *go=NULL) {
        no[tol].mx=mx;
        no[tol].fa=fa;
        no[tol].cnt=1;
        if(go) memcpy(no[tol].go, go, sizeof(int)*C);
        else memset(no[tol].go, -1, sizeof(int)*C);
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

    void build(char *s) {
        init();
        int cur=0;
        for(int i=0; s[i]; i++) {
            cur=add(cur, s[i]);
        }
        topo();
    }

    void topo() {
        int n=0;
        for(int i = 0; i < tol; i++) {
            d[no[i].mx]++;
            n=max(n, no[i].mx);
        }
        for(int i = 1; i <= n; i++) d[i]+=d[i-1];
        for(int i = 0; i < tol; i++) t[--d[no[i].mx]]=i;

        for(int i = tol-1; i >= 0; i--) {
            int u=t[i];
            for(int j = 0; j < C; j++)
                if(no[u].go[j]!=-1)
                    no[u].cnt+=no[no[u].go[j]].cnt;
        }
        no[0].cnt--; // 根节点不需要计算自己。
    }

    void debug() {
        for(int i = 0; i < tol; i++) printf("no[%d].cnt = %d\n", i, no[i].cnt);
    }

    void dfs(int u, ll k) {
        if(u) k--;
        if(!k) return;
        for(int i = 0; i < C; i++) {
            int v=no[u].go[i];
            if(v==-1) continue;
            if(k>no[v].cnt) k-=no[v].cnt;
            else {
                printf("%c", 'a'+i);
                dfs(v, k);
                return;
            }
        }
    }

} sam;

int n, k;
char s[N];

int main() {
    scanf("%s%d", s, &n);
    sam.build(s);
    //sam.debug();
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        assert(k <= sam.no[0].cnt);
        sam.dfs(0, k);
        printf("\n");
    }
    return 0;
}
