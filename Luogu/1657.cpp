#include<bits/stdc++.h>
using namespace std;

int like[22][2], tol, n;
bool vis[22];

void dfs(int cur) {

    if(cur==n) {
        ++tol;
        return ;
    }

    if(!vis[like[cur][0]]) {
        vis[like[cur][0]]=true;
        dfs(cur+1);
        vis[like[cur][0]]=false;
    }

    if(!vis[like[cur][1]]) {
        vis[like[cur][1]]=true;
        dfs(cur+1);
        vis[like[cur][1]]=false;
    }

}

int main() {

    scanf("%d", &n);

    for(int i = 0; i < n; ++i) scanf("%d%d", &like[i][0], &like[i][1]);

    if(n!=0) dfs(0); // n==0

    printf("%d\n", tol);
    return 0;
}
