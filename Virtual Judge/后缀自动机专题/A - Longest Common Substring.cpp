#include<bits/stdc++.h>
using namespace std;

const int N=250005;
const int C=26;

struct Node {
    int mx, fa, go[C];
};

struct SAM {

    Node no[N<<1];
    int tol;

    int newNode(int mx=-1, int fa=-1, int *go=NULL) {
        no[tol].mx=mx;
        no[tol].fa=fa;
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
        for(int i = 0; s[i]; i++) cur=add(cur, s[i]);
    }

    int search(char *s) {
        int u=0, l=0, ans=0;
        for(int i=0; s[i]; i++) {
            int c=s[i]-'a';
            while(u&&no[u].go[c]==-1) {
                u=no[u].fa;
                l=no[u].mx;
            }
            if(no[u].go[c]!=-1) {
                u=no[u].go[c];
                l++;
            } else u=l=0;
            ans=max(ans, l);
        }
        return ans;
    }
} sam;

char s[N];

int main() {
    scanf("%s", s);
    sam.build(s);
    scanf("%s", s);
    printf("%d\n", sam.search(s));
}
