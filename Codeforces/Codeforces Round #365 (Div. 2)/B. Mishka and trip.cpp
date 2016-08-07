#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100010;
int a[N], b[N];
int vis[N];
ll s[N];
int main() {
    memset(vis, 0, sizeof(vis));
    int n, k, x;
    ll sum = 0 ;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < k; i ++) {
        scanf("%d", &x);
        vis[--x] = 1;
        b[i] = a[x];
    }

    s[k] = 0;
    ll res = 0;

    for(int i = k - 1; i > -1; i --) {
        s[i] = s[i + 1] + b[i];
        res += b[i] * s[i + 1];
    }

    for(int i = 0; i < n; i ++) if(!vis[i]) sum += a[i];

    for(int i = 0; i < n; i ++) {
        if(vis[i]) res += sum * a[i];
        else {
            if(!vis[(i + 1) % n]) res += a[i] * a[(i + 1) % n];
        }
    }
    printf("%I64d\n", res);
    return 0;
}
