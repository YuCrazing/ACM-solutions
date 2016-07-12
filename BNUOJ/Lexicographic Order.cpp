#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[22];
ll fac[22];
bool v[22];
void dfs(int cur, int n, ll x){ // sort(a + cur, a + n) will TLE;
    if(cur >= n) return ;
    int pos = 0;
    while(x > fac[n - cur - 1]) {
        pos ++;
        x -= fac[n - cur - 1];
    }
    int cnt = 0;
    for(int i = 0; i < n; i ++) if(!v[i]){
        if(cnt == pos){
            a[cur] = i;
            v[i] = 1;
            break;
        }
        cnt ++;
    }

    dfs(cur + 1, n, x);
}

char s[2][22];
int main(){
    fac[0] = 1;
    for(int i = 1; i < 22; i ++) fac[i] = fac[i - 1] * i;
    int T;
    ll x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%s%lld", s[0], &x);
        int l = strlen(s[0]);
        for(int i = 0; i < l; i ++) v[i] = 0;
        dfs(0, l, x);
        for(int i = 0; i < l; i ++) s[1][a[i]] = s[0][i];
        s[1][l] = 0;
        printf("Case %d: %s\n", cas, s[1]);
    }
    return 0;
}
