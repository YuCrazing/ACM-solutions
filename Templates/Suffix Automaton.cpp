/*
* hihoCoder 1465 : 后缀自动机五·重复旋律8
* 给出一个文本串，n个单词串
* 对于每个单词串，求该文本串中与之"循环相似"的子串的出现次数。
*
* 解法：记单词串长度为l，将单词串重复两次拼接成长为2*l的新串，
* 即求文本串与新串的【长度为l的公共子串】的出现次数。
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
const int C = 26;

struct Node {
    int go[C], mx, pos, fa, in;
};

struct SAM {

    Node no[N<<1];
    bool vis[N<<1];
    vector<int> vec;
    int tol;

    int newNode(int mx=-1, int fa=-1, int *go=NULL) {
        no[tol].mx = mx;
        no[tol].fa = fa;
        no[tol].pos = no[tol].in = 0;
        if(go) for(int i = 0; i < C; i++) no[tol].go[i] = go[i];
        else for(int i = 0; i < C; i++) no[tol].go[i] = -1;
        return tol++;
    }

    void init() {
        tol = 0;
        newNode(0);
        memset(vis, false, sizeof(vis));
    }

    int split(int x, int len) {
        int y = newNode(len, no[x].fa, no[x].go);
        no[x].fa=y;
        return y;
    }

    int add(int u, char ch) {
        int c = ch-'a';
        int z = newNode(no[u].mx+1);
        no[z].pos++;//一个前缀
        int v = u;
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
        int cur = 0;
        for(int i = 0; s[i]; i++) {
            cur = add(cur, s[i]);
        }
    }

    void topo() {
        for(int i = 1; i < tol; i++) no[no[i].fa].in++;
        queue<int> q;
        for(int i = 0; i < tol; i++) if(!no[i].in) q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            int fa = no[u].fa;
            no[fa].pos+=no[u].pos;
            if(!--no[fa].in && fa) q.push(fa); //根节点不进入队列
        }
    }

    int search(char *s, int n) {
        int u,l,ans;
        u=l=ans=0;
        for(int i = 0; s[i]; i++) {
            int c = s[i]-'a';
            while(u&&no[u].go[c]==-1) {
                u=no[u].fa;
                l=no[u].mx;
            }
            if(no[u].go[c]!=-1) {
                u=no[u].go[c];
                l++;
            } else u=l=0;

            //!!!
            if(l > n) {
                while(u&&no[no[u].fa].mx>=n) {
                    u=no[u].fa;
                    l=no[u].mx;
                }
            }
            if(l >= n && !vis[u]) {
                vis[u]=true;
                vec.push_back(u);
                ans += no[u].pos;
            }
        }
        for(int i = 0; i < vec.size(); i++) vis[vec[i]]=false;
        vec.clear();
        return ans;
    }

} sam;

int n;
char s[N<<1];

int main() {
    scanf("%s%d", s, &n);
    sam.init();
    sam.build(s);
    sam.topo();
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        int l = strlen(s);
        for(int j = 0; j < l; j++) s[l+j]=s[j];
        s[2*l]=0;
        printf("%d\n", sam.search(s, l));
    }
    return 0;
}
