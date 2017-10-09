/*
    注意：

    for(int i = 0; i < (N<<1); i++) no[i].pos.clear();
    而不是
    for(int i = 0; i < N; i++) no[i].pos.clear();
*/

#include<bits/stdc++.h>
using namespace std;

const int N=1005;
const int C=26;

struct Node {
    int mx, fa, go[C];
    vector<int> pos;
};

struct SAM {

    Node no[N*2];
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
        for(int i = 0; i < (N<<1); i++) no[i].pos.clear(); //!!! i<(N<<1) not i<N
    }

    int split(int x, int len) {
        int y=newNode(len, no[x].fa, no[x].go);
        no[x].fa=y;
        no[y].pos=no[x].pos;//!!
        return y;
    }

    int add(int u, char ch) {
        int c=ch-'a';
        assert(c<26&&c>=0);
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
        for(int i = 0; s[i]; i++) {
            cur=add(cur, s[i]);
            int v=cur;
            while(v) {
                no[v].pos.push_back(i);
                v=no[v].fa;
            }
        }
    }

    void debug() {
        for(int i = 0; i < tol; i++) {
            printf("no[%d]: ", i);
            for(int j = 0; j < no[i].pos.size(); j++) {
                printf("%d ", no[i].pos[j]);
            }
            printf("\n");
        }
    }

    int calc() {
        int ans=0;
        for(int i = 1; i < tol; i++) {
            int n=no[i].pos.size();
            if(n<2) continue;
            int dis=no[i].pos[n-1]-no[i].pos[0];
            if(dis>no[no[i].fa].mx) {
                ans+=min(dis, no[i].mx)-no[no[i].fa].mx;
                //printf("%d==%d\n", i, dis-no[no[i].fa].mx);
            }
        }
        return ans;
    }

} sam;

char s[N];

int main() {
    //freopen("in.in", "r", stdin);
    while(scanf("%s", s)) {
        if(s[0]=='#') break;
        assert(strlen(s)<=1e3);
        sam.build(s);
        //sam.debug();
        printf("%d\n", sam.calc());
    }
    return 0;
}
