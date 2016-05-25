#include <cstdio>
using namespace std;
typedef long long LL;

int main(){
    int T;
    LL W;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%lld", &W);
        LL even = 1;
        while(W % 2 == 0) {
            even <<= 1;
            W >>= 1;
        }
        printf("Case %d: ", cas);
        if(even == 1) printf("Impossible\n");
        else printf("%lld %lld\n", W, even);
    }
    return 0;
}
