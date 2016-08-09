#include <cstdio>
using namespace std;

const int N = 111;
int sg[N], vis[N];
int dfs(int x){
    for(int i = 1; i*2 <= x; i ++){
        vis[sg[i] ^ sg[x - i]] = x;
    }
    int i = 0;
    while(vis[i] == x) i ++;
    return sg[x] = i;
}
int main(){
//    sg[1] = 0;
//    for(int i= 2; i < N; i ++) printf("%d %d\n",i, dfs(i));
    int n, x;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i ++){
        scanf("%d", &x);
        sum ^= 1 - (x & 1);
        if(sum) printf("1\n");
        else printf("2\n");
    }
    return 0;
}
