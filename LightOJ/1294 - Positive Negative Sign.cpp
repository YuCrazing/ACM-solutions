#include <cstdio>
using namespace std;

int main(){
    int T, n, m;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &n, &m);
        printf("Case %d: %lld\n", cas, (long long)m*(n/2));
    }
    return 0;
}
