/*
    vec中存储拓扑排序之后的节点。
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int C = 26;

struct Node {
    int mx, fa, go[C], in, len, ans;
};

struct SAM {

    Node no[N<<1];
    vector<int> vec;
    int tol;

    int newNode(int mx=-1, int fa=-1, int *go=NULL) {
        no[tol].mx=mx;
        no[tol].fa=fa;
        no[tol].in=no[tol].ans=no[tol].len=0;
        if(go) for(int i = 0; i < C; i++) no[tol].go[i]=go[i];
        else for(int i = 0; i < C; i++) no[tol].go[i]=-1;
        return tol++;
    }

    void init() {
        tol=0;
        newNode(0);
        vec.clear();
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
        for(int i = 0; i < tol; i++) no[i].ans=no[i].mx;
        for(int i = 1; i < tol; i++) no[no[i].fa].in++;
        queue<int> q;
        for(int i = 0; i < tol; i++) if(!no[i].in) q.push(i);
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            vec.push_back(u);
            int fa=no[u].fa;
            if(!--no[fa].in && fa) q.push(fa); // Node 0 can't be in queue.
        }
    }

    void build(char *s) {
        init();
        int cur=0;
        for(int i = 0; s[i]; i++) {
            cur = add(cur, s[i]);
        }
        topo();
    }

    void search(char *s) {
        int u=0,l=0;
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
            no[u].len = max(no[u].len, l);
        }
        for(int i = 0; i < vec.size(); i++) {
            int u=vec[i];
            if(!no[u].len) {
                no[u].ans=0;
                continue;
            }
            no[u].ans = min(no[u].ans, no[u].len);
//            no[no[u].fa].len=min(max(no[no[u].fa].len, no[u].len), no[no[u].fa].mx);
            no[no[u].fa].len=no[no[u].fa].mx;
            no[u].len=0;
        }
    }

    int calc() {
        int ans=0;
        for(int i = 0; i < tol; i++) ans=max(ans, no[i].ans);
        return ans;
    }

    void debug() {
        for(int i = 0; i < tol; i++) {
            printf("---\n");
            //printf("no[%d].fa=%d\n", i, no[i].fa);
            //printf("no[%d].mx=%d\n", i, no[i].mx);
            //printf("no[%d].ans=%d\n", i, no[i].ans);
            printf("no[%d].len=%d\n", i, no[i].len);
            for(int j = 0; j < C; j++)
                if(no[i].go[j]!=-1)
                    printf("    no[%d].go[%c]=%d\n", i, j+'a', no[i].go[j]);
            printf("---\n");
        }
    }
} sam;

int n=1;
char s[N];

int main() {
    //freopen("in.in", "r", stdin);
    scanf("%s", s);
    sam.build(s);
    while(scanf("%s", s)!=EOF) {
        sam.search(s);
        n++;
    }
    printf("%d\n", sam.calc());
    return 0;
}
