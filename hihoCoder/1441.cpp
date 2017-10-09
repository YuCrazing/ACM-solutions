#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+5;
const int C = 26;

struct Node {
    int go[C], mx, mi, fa;
};

struct SAM {

    Node no[N<<1];
    int tol;

    int newNode(int _mx=-1, int _mi=-1, int _fa=-1, int* _go=NULL) {
        no[tol].mx = _mx;
        no[tol].mi = _mi;
        no[tol].fa = _fa;

        if(_go==NULL) {
            for(int i = 0; i < C; i++) no[tol].go[i] = -1;
        } else {
            for(int i = 0; i < C; i++) no[tol].go[i] = _go[i];
        }

        return tol++;
    }

    void init() {
        tol = 0;
        newNode(0,0,-1);
    }

    int split(int x, int len) {
        int y = newNode(len, no[no[x].fa].mx+1, no[x].fa, no[x].go); //!!
        no[x].fa = y;
        no[x].mi = no[y].mx+1;
        return y;
    }

    int add(int u, char ch) {

        int c = ch - 'a';
        int v = u;
        int z = newNode(no[u].mx+1);

        while(v!=-1 && no[v].go[c]==-1) {
            no[v].go[c]=z;
            v=no[v].fa;
        }

        if(v==-1) {
            no[z].fa=0;
            no[z].mi=1;
            return z;
        }


        int x = no[v].go[c];

        // 1. no[x].mx == no[v].mx + 1
        if(no[x].mx==no[v].mx+1) {
            no[z].fa = x;
            no[z].mi = no[x].mx+1;
            return z;
        }

        // 2. no[x].mx > no[v].mx + 1
        int y = split(x, no[v].mx+1);
        no[z].fa = y;
        no[z].mi = no[y].mx+1;

        int w = v;
        while(w!=-1 && no[w].go[c]==x) {
            no[w].go[c] = y;
            w=no[w].fa;
        }
        return z;
    }

    void build(char *s) {
        int cur = 0;
        for(int i = 0; s[i]; i++) {
            cur = add(cur, s[i]);
            //debug();
        }
    }

    ll count() {
        ll ans=0;
        for(int i = 0; i < tol; i++) ans += no[i].mx-no[i].mi+1;
        return ans-1;
    }

    void debug() {
        printf("---\n");
        for(int i = 0; i < tol; i++) {
            printf("Node[%d].fa = %d, len = [%d %d]\n", i, no[i].fa, no[i].mx, no[i].mi);
            for(int j = 0; j < C; j++) if(no[i].go[j]!=-1)
                    printf("    no[%d].go[%c] = %d\n", i, j+'a', no[i].go[j]);
        }
        printf("---\n");
    }

    bool check() {
        for(int i = 0; i < tol; i++) if(no[i].fa!=-1) {
                assert(no[i].mi==no[no[i].fa].mx+1);
            }
    }
} sam;

char s[N];
int main() {
    while(scanf("%s", s)!=EOF) {

        sam.init();
        sam.build(s);
        sam.debug();
        //sam.check();

        printf("%lld\n", sam.count());

    }
    return 0;
}
