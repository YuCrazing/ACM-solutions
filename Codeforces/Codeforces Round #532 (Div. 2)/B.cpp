#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +5;
int cnt[N], tol;
void add(int x){
    if(cnt[x]==0) ++tol;
    ++cnt[x];
}
void sub(int x){
    --cnt[x];
    if(cnt[x]==0) --tol;
}
int main() {
    int n, m, x;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        add(x);
        if(tol==m) {
            for(int j = 1; j <= m; ++j) sub(j);
            putchar('1');
        }
        else putchar('0');
    }
    return 0;
}

