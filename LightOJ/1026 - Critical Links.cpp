#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int MAXM = 100010<<1;
struct Edge{
    int to, next;
    bool cut;
}edge[MAXM];
int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN];
int Index, top;
bool Instack[MAXN];
bool cut[MAXN];
int add_block[MAXN];
int bridge;
map<int, bool> mp;
vector<pair<int, int> > ans;

void addedge(int u, int v){
    edge[tot].to = v; edge[tot].next = head[u]; edge[tot].cut = false;
    head[u] = tot ++;
}

void Tarjan(int u, int pre){
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top ++] = u;
    Instack[u] = true;
    int son = 0;
    for(int i = head[u]; i != -1; i = edge[i].next){
        v = edge[i].to;
        if(v == pre) continue;
        if(!DFN[v]){
            son ++;
            Tarjan(v, u);
            if(Low[u] > Low[v]) Low[u] = Low[v];
            if(Low[v] > DFN[u]){
                bridge ++;
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
            if(u != pre && Low[v] >= DFN[u]){
                cut[u] = true;
                add_block[u] ++;
            }
        }
        else if(Low[u] > DFN[v]) Low[u] = DFN[v];
    }
    if(u == pre && son > 1) cut[u] = true;
    if(u == pre) add_block[u] = son - 1;
    Instack[u] = false;
    top --;
}

void init(){
    memset(head, -1, sizeof(head)); // head[] & tot initialized.
    tot = 0;
    memset(DFN, 0, sizeof(DFN));
    memset(Instack, false, sizeof(Instack));
    memset(add_block, 0, sizeof(add_block));
    memset(cut, false, sizeof(cut));
    Index = top = 0;
    bridge = 0;
    mp.clear();
    ans.clear();
}
int main(){
    int T, u, v, k, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; i ++){
            scanf("%d (%d)", &u, &k);
            for(int j = 0; j < k; j ++){
                scanf("%d", &v);
                if(!mp.count(u * MAXN + v)){
                    mp[u * MAXN + v] = 1;
                    mp[v * MAXN + u] = 1;
                    addedge(u, v);
                    addedge(v, u);
                }
            }
        }

        for(int i = 0; i < n; i ++)if(!DFN[i])Tarjan(i, i);

        for(int u = 0; u < n; u ++)
        for(int j = head[u]; j != -1; j = edge[j].next){
            int v = edge[j].to;
            if(edge[j].cut && u < v) ans.push_back(make_pair(u, v));
        }

        sort(ans.begin(), ans.end());
        printf("Case %d:\n%d critical links\n", cas, ans.size());
        for(vector<pair<int, int> >::iterator it = ans.begin(); it != ans.end(); it++)
            printf("%d - %d\n", it->first, it->second);
    }
    return 0;
}
