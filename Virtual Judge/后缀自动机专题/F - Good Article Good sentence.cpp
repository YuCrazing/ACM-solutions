#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int C = 26;

int d[N], t[N<<1];

struct Node {
    int mx, fa, go[C], len;
};

struct SAM {

    Node no[N<<1];
    int tol;

    int newNode(int mx=-1, int fa=-1, int *go=NULL) {
        no[tol].mx=mx;
        no[tol].fa=fa;
        no[tol].len=0;
        if(go) memcpy(no[tol].go, go, sizeof(int)*C);
        else memset(no[tol].go, -1, sizeof(int)*C);
        return tol++;//!!
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

    void topo() {
        int n=0;
        for(int i = 0; i < tol; i++) n=max(n, no[i].mx);
        for(int i = 0; i <= n; i++) d[i]=0;

        for(int i = 0; i < tol; i++) d[no[i].mx]++;
        for(int i = 1; i <= n; i++) d[i]+=d[i-1];
        for(int i = 0; i < tol; i++) t[--d[no[i].mx]]=i;
    }

    void build(char *s) {
        init();
        int cur=0;
        for(int i = 0; s[i]; i++) cur=add(cur, s[i]);
        topo();
    }

    void search(char *s) {
        int u=0, l=0;
        for(int i = 0; s[i]; i++) {
            int c=s[i]-'a';
            while(u&&no[u].go[c]==-1) {
                u=no[u].fa;
                l=no[u].mx;
            }
            if(no[u].go[c]!=-1) {
                u=no[u].go[c];
                l++;
            } else u=l=0;
            no[u].len=max(no[u].len, l);
        }
    }

    ll calc() {
        ll ans=0;
        for(int i = tol-1; i > 0; i--) {
            int u=t[i];
            //printf("u = %d %d\n", u, no[u].len);
            if(no[u].len) {
                no[no[u].fa].len=no[no[u].fa].mx;
            }
            ans+=no[u].mx-max(no[u].len, no[no[u].fa].mx); //!!
        }
        return ans;
    }
} sam;

int T, n, ca=0;
char s[N];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%s", &n, s);
        sam.build(s);
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            sam.search(s);
        }
        printf("Case %d: %lld\n", ++ca, sam.calc());
    }
    return 0;
}
