/*
    注意数组大小。
    strcat()特别慢，慎用。
    ":"边也要参与拓扑排序，否则有些节点的入度无法减到0。":"边不参与计算即可。
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6+5;
const int C = 11;
const int mod = 1e9+7;

void upd(int &a, int b) {
    a += b;
    if(a >= mod) a -= mod;
}

struct Node {
    int mx, fa, go[C], in, cnt, ans;
};

struct SAM {

    Node no[N<<1];
    int tol;

    int newNode(int mx=-1, int fa=-1, int *go=NULL) {
        no[tol].mx = mx;
        no[tol].fa = fa;
        no[tol].cnt = no[tol].in = no[tol].ans=0;
        if(go) for(int i = 0; i < C; i++) no[tol].go[i] = go[i];
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
        int c = ch-'0';
        int z = newNode(no[u].mx+1);
        int v = u;
        while(v!=-1 && no[v].go[c]==-1) {
            no[v].go[c] = z;
            v=no[v].fa;
        }
        if(v==-1) {
            no[z].fa = 0;
            return z;
        }

        int x = no[v].go[c];
        if(no[x].mx == no[v].mx+1) {
            no[z].fa = x;
            return z;
        }

        int y = split(x, no[v].mx+1);
        while(v!=-1&&no[v].go[c]==x) {
            no[v].go[c]=y;
            v=no[v].fa;
        }
        no[z].fa=y;
        return z;
    }

    void build(char *s) {
        int cur = 0;
        for(int i = 0; s[i]; i++) {
            cur = add(cur, s[i]);
        }
    }

    void topo() {
        queue<int> q;
        q.push(0);
        no[0].cnt=1;
        no[0].ans=0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = 0; i < C; i++) {
                if(no[u].go[i]!=-1) {
                    int v = no[u].go[i];
                    no[v].in--;
                    if(!no[v].in) q.push(v);
                    if(i!=10) {
                        upd(no[v].cnt, no[u].cnt); //
                        int x = (ll)no[u].ans*(ll)10%mod;
                        int y = (ll)no[u].cnt*(ll)i%mod;
                        upd(x, y);
                        upd(no[v].ans, x);
                    }
                }
            }
        }
    }

    int solve() {
        for(int i = 0; i < tol; i++) {
            for(int j = 0; j < C; j++) {
                if(no[i].go[j]!=-1) no[no[i].go[j]].in++;
            }
        }
        topo();
        int ans = 0;
        for(int i = 0; i < tol; i++) upd(ans, no[i].ans);
        return ans;
    }

    void debug() {
        for(int i = 0; i < tol; i++) {
            printf("---\n");
            printf("no[%d].fa = %d\n", i, no[i].fa);
            printf("no[%d].mx = %d\n", i, no[i].mx);
            printf("no[%d].cnt = %d\n", i, no[i].cnt);
            printf("no[%d].ans = %d\n", i, no[i].ans);
            printf("no[%d].in = %d\n", i, no[i].in);
            for(int j = 0; j < C; j++) if(no[i].go[j]!=-1) {
                    printf("    no[%d].go[%c] = %d\n", i, j+'0', no[i].go[j]);
                }
            printf("---\n");
        }
    }

} sam;

int n;
char s[N>>1], t[N];

int main() {

    //freopen("in.in", "r", stdin);

    scanf("%d", &n);
    int lt=0;
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        if(i) t[lt++]=('0'+10);
        for(int j = 0; s[j]; j++) t[lt++]=s[j];
    }
    t[lt]=0;

    sam.init();
    sam.build(t);

    printf("%d\n", sam.solve());
    //sam.debug();
    return 0;
}
