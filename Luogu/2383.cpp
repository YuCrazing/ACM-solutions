#include<bits/stdc++.h>
using namespace std;

int T, n, sum, a[1111], l[4];
bool ok;

void dfs(int cur) {
    if(ok) return;
    if(cur==n) {
        ok=true;
        return ;
    }
    for(int i = 0; i < 4; ++i) {
        if(l[i] >= a[cur]) {
            l[i] -= a[cur];
            dfs(cur+1);
            l[i] += a[cur];
        }
    }
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        ok = sum = 0;
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]), sum += a[i];
        if(!(sum%4)) {
            for(int i = 0; i < 4; ++i) l[i] = sum/4;
            dfs(0);
        }
        puts(ok?"yes":"no");
    }
    return 0;
}
