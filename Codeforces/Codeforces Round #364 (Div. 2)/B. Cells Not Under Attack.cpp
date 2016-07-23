#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100010;
bool vis[2][N];
int main(){
    ll n, row, col;
    int x, y, m;
    row = col = 0;
    scanf("%I64d%d", &n, &m);
    for(int i = 0; i < m;  i++){
        scanf("%d%d", &x, &y);
        if(!vis[0][x]){
            row ++;
            vis[0][x] = 1;
        }
        if(!vis[1][y]){
            col ++;
            vis[1][y] = 1;
        }
        printf((i == m - 1) ? "%I64d\n" : "%I64d ", (n - row) * (n - col));
    }

    return 0;
}
