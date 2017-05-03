#include<bits/stdc++.h>
using namespace std;

int a[17], c[7], k;
void dfs(int now, int beg) {
    if(now > 6) {
        for(int i = 1; i <= 6; i++) printf(i == 6 ? "%d\n" : "%d ", c[i]);
        return ;
    }
    for(int i = beg; i <= k - 6 + now; i++) {
        c[now] = a[i];
        dfs(now + 1, i + 1);
    }
}

int main() {
    bool fi = true;
    while(scanf("%d", &k) != EOF && k) {
        if(fi) fi = false;
        else printf("\n");
        for(int i = 1; i <= k; i++) scanf("%d", &a[i]);
        dfs(1, 1);
    }
    return 0;
}
