#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int T, n, k;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &n, &k);
        int pos = 0;
        for(int i = 2; i <= n; i ++) pos = (pos + k) % i;
        printf("Case %d: %d\n", cas, pos + 1);
    }
    return 0;
}
