#include <cstdio>
#include <cstring>
using namespace std;

char g[22][22];
bool vis[22][22];
int T, W, H, sum;

struct Node{
    int x, y;
    Node(int _x = 0, int _y = 0):x(_x),y(_y){}
};

void init(){
    memset(vis, 0, sizeof(vis));
    sum = 0;
}

void dfs(Node u){

    if(vis[u.x][u.y]) return ;
    if(g[u.x][u.y] == '#') return ;

    vis[u.x][u.y] = 1;
    sum ++;
    if(u.x > 0) dfs(Node(u.x - 1, u.y));
    if(u.x < H - 1) dfs(Node(u.x + 1, u.y));
    if(u.y > 0) dfs(Node(u.x, u.y - 1));
    if(u.y < W - 1) dfs(Node(u.x, u.y + 1));
}
int main(){
    Node s;
    scanf("%d", &T);
    for(int cas = 1;  cas <= T; cas ++){
        init();
        scanf("%d%d", &W, &H);
        for(int i = 0; i < H; i ++) {
            scanf("%s", g[i]);
            for(int j = 0; j < W; j ++)
                if(g[i][j] == '@') s = Node(i, j);
        }
        dfs(s);
        printf("Case %d: %d\n", cas, sum);
    }
    return 0;
}
