#include<bits/stdc++.h>
using namespace std;
int n, k, a[7]; // array size
void dfs(int now) {
    if(now > k) {
        for(int i = 1; i <= k; i++) printf(i == k ? "%d\n" : "%d", a[i]);
        return;
    }
    for(int i = 1; i <= n; i++) {
        a[now] = i;
        dfs(now + 1);
    }
}
int main() {

    while(scanf("%d%d", &n, &k) != EOF) {
        dfs(1);
    }
    return 0;
}
