/*
    多组样例时注意初始化拓扑排序用到的d[]数组
*/

#include<bits/stdc++.h>
using namespace std;

const int N=110005;
const int C=11;
const int mod=2012;

int d[N], t[N<<1];

struct Node {
    int mx, fa, go[C], ans, cnt;
};

struct SAM {

    Node no[N<<1];
    int tol;

    int newNode(int mx=-1, int fa=-1, int *go=NULL) {
        no[tol].mx=mx;
        no[tol].fa=fa;
        no[tol].ans=no[tol].cnt=0;
        if(go) memcpy(no[tol].go, go, sizeof(int)*C);
        else memset(no[tol].go,-1, sizeof(int)*C);
        return tol++;
    }

    void init() {
        tol=0;
        newNode(0);
        no[0].cnt=1;
    }

    int split(int x, int len) {
        int y=newNode(len, no[x].fa, no[x].go);
        no[x].fa=y;
        return y;
    }

    int add(int u, int ch) {
        int c=ch-'0';
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
        for(int i = 0; i <= n; i++) d[i]=0; //!!!!

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

    int calc() {
        int ans=0;
        for(int i = 0; i < tol; i++) {
            int u=t[i];
            for(int j = 0; j < C; j++) {
                int v=no[u].go[j];
                if(v==-1 || j==10) continue;
                if(!u&&!j) continue;//不包含前导零
                no[v].cnt+=no[u].cnt;
                no[v].ans+=(no[u].ans*10%mod+j*no[u].cnt%mod)%mod;
                if(no[v].ans>=mod) no[v].ans-=mod;
            }
            ans+=no[u].ans;
            if(ans>=mod) ans-=mod;
        }
        return ans;
    }

    void debug() {
        for(int i = 0; i < tol; i++) {
            printf("no[%d].cnt=%d ", i, no[i].cnt);
            printf("no[%d].ans=%d\n", i, no[i].ans);
        }
    }

} sam;

int n;
char s[N], tt[N];

int main() {
    while(scanf("%d", &n)!=EOF) {
        int lt=0;
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            if(i) tt[lt++]=('0'+10);
            for(int j = 0; s[j]; j++) tt[lt++]=s[j];
        }
        tt[lt]=0;
        sam.build(tt);
        printf("%d\n", sam.calc());
        //sam.debug();
    }
    return 0;
}
