#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
typedef long long ll;


const int MAXN = 1e5 + 5;
int a[MAXN];

void dfs(int l, int r) {
    if(l == r) {
        a[l] = l;
        return ;
    }
    a[l] = l + 1;
    a[l + 1] = r;
    a[r - 1] = l;
    a[r] = r - 1;
    if(r - l < 4) return ;
    dfs(l + 2, r - 2);
}
int main() {
    int n;
    scanf("%d", &n);
    if(n % 4 == 2 || n % 4 == 3) printf("-1\n");
    else {
        dfs(1, n);
        for(int j = 1; j <= n; j ++) printf((j == n) ? "%d\n" : "%d ", a[j]);
    }
    return 0;
}
