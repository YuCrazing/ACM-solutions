/*
    二进制分组

    需要两个自动机组，add的字符串加入第一个自动机组，delete的字符串加入第二个自动机组

    需要内存池，静态创建自动机会MLE

    查询操作：
        1.将结束节点end记为1，查询时跑一遍匹配，然后对所有节点进行拓扑排序，计算答案。
        2.在build的过程中，每个节点记录一个cnt，表示匹配到该节点时对答案的贡献为多少，
            查询时跑一遍匹配，将经过的节点的cnt加起来即可。
    第1种查询方法会超时，因为当文本串s特别短时，查询操作会有很多，但是每次查询要遍历自动机上所有节点，
    查询复杂度退化为n^2.
    因此应该使用第2种方法。

    合并两个自动机的过程容易出错，要注意。

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=(6e5)+50;
const int C=26;

int mem[N], top;

struct Node {
    int son[C], go[C], next, end;
    ll cnt;
};

Node no[N];

struct AC {

    int root;
    queue<int> q;

    int newNode() {
        int id=mem[top-1];
        memset(no[id].son, 0, sizeof(no[id].son));
        memset(no[id].go, 0, sizeof(no[id].go));
        no[id].end=no[id].next=no[id].cnt=0;
        top--;
        return id;
    }

    void init() {
        if(root) {
            while(!q.empty()) q.pop();
            q.push(root);
            while(!q.empty()) {
                int u=q.front();
                q.pop();
                mem[top++]=u;
                for(int i = 0; i < C; i++) {
                    int son=no[u].son[i];
                    if(son)q.push(son);
                }
            }
        }
        root=0;
    }

    void insert(char *s) {
        if(!root) root=newNode();
        int cur=root;
        for(int i = 0; s[i]; i++) {
            int &son=no[cur].son[s[i]-'a'];
            if(!son) {
                son=newNode();
                no[cur].go[s[i]-'a']=son;
            }
            cur=son;
        }
        no[cur].end++;
    }

    void build() {
        if(!root) return;
        while(!q.empty()) q.pop(); // no clear
        no[root].next=root;
        for(int i = 0; i < C; i++) if(!no[root].son[i]) no[root].go[i]=root;
        for(int i = 0; i < C; i++) if(no[root].son[i]) {
                no[no[root].son[i]].cnt=0;
                q.push(no[root].son[i]);
                no[no[root].son[i]].next=root;
            }

        while(!q.empty()) {
            int fa=q.front();
            q.pop();
            if(no[fa].end) no[fa].cnt++;
            int nex=no[fa].next;
            no[fa].cnt+=no[nex].cnt;
            for(int i = 0; i < C; i++) {
                int son=no[fa].son[i];
                int &go=no[fa].go[i];
                if(!son) {
                    go=no[nex].go[i];
                    continue;
                }
                no[go].next=no[nex].go[i];
                no[go].cnt=0;
                q.push(go);
            }
        }
    }

    ll search(char *s) {
        if(!root) return 0;
        ll ans=0;
        int cur=root;
        for(int i = 0; s[i]; i++) {
            cur=no[cur].go[s[i]-'a'];
            ans+=no[cur].cnt;
        }

        return ans;
    }

    void debug() {
        if(!root) return ;
        while(!q.empty()) q.pop();
        q.push(root);
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            printf("---------\n");
            printf("u=%d no[%d].next=%d no[%d].end=%d\n", u, u, no[u].next, u, no[u].end);
            for(int i = 0; i < C; i++) {
                int v=no[u].son[i];
                if(!v) continue;
                printf("    son[%d]=%d\n", i, v);
                q.push(v);
            }
            printf("---------\n");
        }
    }
};

const int D=20;
struct ACbin {

    AC ac[D];
    queue<int> qa, qb;

    void init() {
        for(int i = 0; i < D; i++) ac[i].init();
    }

    // i --> j
    void merge(int a, int b) {
        while(!qa.empty()) qa.empty();
        while(!qb.empty()) qb.empty();
        if(!ac[b].root)ac[b].root=ac[b].newNode();
        qa.push(ac[a].root);
        qb.push(ac[b].root);

        while(!qa.empty()) {
            int ua=qa.front();
            int ub=qb.front();
            qa.pop();
            qb.pop();
            no[ub].end+=no[ua].end;
            for(int i = 0; i < C; i++) {
                int va, vb;
                va=no[ua].son[i];
                vb=no[ub].son[i];
                if(!va) continue;
                if(!vb) {
                    no[ub].son[i]=ac[b].newNode();
                    no[ub].go[i]=no[ub].son[i];
                }
                vb=no[ub].son[i];
                qa.push(va);
                qb.push(vb);
            }
        }
        ac[a].init();
        ac[b].build();
    }

    void insert(char *s) {
        bool ok=false;
        if(!ac[0].root) ok=true;
        ac[0].insert(s);
        if(ok) ac[0].build();
        if(ok) return;
        int cur=0;
        while(1) {
            if(!ac[cur+1].root) ok=true;
            merge(cur, cur+1);
            if(ok) return;
            cur++;
        }
    }

    ll search(char *s) {
        ll ans=0;
        for(int i = 0; i < D; i++) {
            ans += ac[i].search(s);
        }
        return ans;
    }

} acbin[2];

void init() {
    for(int i = 0; i < N; i++) mem[i]=i;
    top=N;
    acbin[0].init();
    acbin[1].init();
}

char s[N];
int main() {
    int m, t;
    init();
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%s", &t, s);
        if(t==1) acbin[0].insert(s);
        else if(t==2) acbin[1].insert(s);
        else {
            printf("%I64d\n", acbin[0].search(s)-acbin[1].search(s));
            fflush(stdout);
        }
    }
    return 0;
}
