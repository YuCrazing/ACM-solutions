#include<bits/stdc++.h>
using namespace std;

const int S=22;

struct Point{
    int x, y;
    Point(int _x=0,int _y=0):x(_x),y(_y){}
    Point operator+(const Point &t)const {
        return Point(x+t.x, y+t.y);
    }
};

int n;
bool vis[S<<1][S<<1];

void dfs(Point cur, int step){
    //if(vis[cur.x][cur.y]) return ;
    vis[cur.x][cur.y]=true;
    if(step==n) return;
    dfs(cur+Point(-1, -2), step+1);
    dfs(cur+Point(-2, -1), step+1);
    dfs(cur+Point(-2, 1), step+1);
    dfs(cur+Point(-1, 2), step+1);
    dfs(cur+Point(1, 2), step+1);
    dfs(cur+Point(2, 1), step+1);
    dfs(cur+Point(2, -1), step+1);
    dfs(cur+Point(1, -2), step+1);
}

int calc(){
    int ans=0;
    for(int i = 0; i < 2*S; i++){
        for(int j = 0; j < 2*S; j++){
            if(vis[i][j]) ans++;
            //if(vis[i][j]) printf("# ");
            //else printf(". ");
//            printf("%d ",vis[i][j]);
        }
        //printf("\n");
    }
    return ans;
}

void solve(){
    int k = 5;
    for(n = 0; n <= k; n++){
        memset(vis, 0, sizeof(vis));
        dfs(Point(S, S), 0);
        printf("%d: %d\n", n, calc());
    }
}


int main(){
    //freopen("out.txt", "w", stdout);
    solve();
}
