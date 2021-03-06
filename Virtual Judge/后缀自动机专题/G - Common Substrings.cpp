/*
    注意:
        1. C=52
        2. 最终计算时，注意保证no[u].mx>=k
*/

#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=1e5+5;
const int C=52;

int d[N], t[N<<1];

struct Node {
    int mx, fa, go[C], pos;
    ll cnt;
};

struct SAM {

    Node no[N<<1];
    int tol;

    int newNode(int mx=-1, int fa=-1, int *go=NULL) {
        no[tol].mx=mx;
        no[tol].fa=fa;
        no[tol].pos=no[tol].cnt=0;
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
        int c=(ch>='a'&&ch<='z'?ch-'a':ch-'A'+26);
        int z=newNode(no[u].mx+1);
        no[z].pos=1;//
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
        memset(d, 0, sizeof(d));
        int n=0;
        for(int i=0; i<tol; i++) {
            d[no[i].mx]++;
            n=max(n, no[i].mx);
        }
        for(int i=1; i<=n; i++) d[i]+=d[i-1];
        for(int i=0; i<tol; i++) t[--d[no[i].mx]]=i;
        for(int i=tol-1; i>0; i--) {
            int u=t[i];
            no[no[u].fa].pos+=no[u].pos;
        }
    }

    void build(char *s) {
        init();
        int cur=0;
        for(int i = 0; s[i]; i++) cur=add(cur, s[i]);
        topo();
    }

    void debug() {
        for(int i = 0; i < tol; i++) printf("no[%d].pos=%d\n", i, no[i].pos);
    }

    ll search(char *s, int k) {
        int u=0, l=0;
        ll ans=0;
        for(int i=0; s[i]; i++) {
            int c=(s[i]>='a'&&s[i]<='z'?s[i]-'a':s[i]-'A'+26);
            while(u&&no[u].go[c]==-1) {
                u=no[u].fa;
                l=no[u].mx;
            }
            if(no[u].go[c]!=-1) {
                u=no[u].go[c];
                l++;
            } else u=l=0;
            if(l>=k) {
                ans+=(ll)(l-max(no[no[u].fa].mx, k-1))*no[u].pos;
                if(no[no[u].fa].mx>=k) no[no[u].fa].cnt++;
            }

        }
        for(int i = tol-1; i > 0; i--) {
            int u = t[i];
            if(!no[u].cnt) continue;
            if(no[u].mx<k) continue; //!!
            no[no[u].fa].cnt+=no[u].cnt;//!!
            ans+=no[u].cnt*(ll)(no[u].mx-max(no[no[u].fa].mx, k-1))*(ll)no[u].pos;
        }
        return ans;
    }

} sam;

//ll calc(string s, string t, int k) {
//    ll ans=0;
//    for(int i = 0; i < t.size(); i++) {
//        for(int j = k; i+j-1 < t.size(); j++) {
//            string sub=t.substr(i, j);
//            for(int l = 0; l+j-1 < s.size(); l++) {
//                if(s.substr(i, j)==sub) ans++;
//            }
//        }
//    }
//    return ans;
//}

int k;
char s[N];

int main() {
    //freopen("in.in", "r", stdin);
    while(scanf("%d", &k)&&k) {
        scanf("%s", s);
        sam.build(s);
        //sam.debug();
        scanf("%s", s);
        printf("%lld\n", sam.search(s, k));
    }
}
