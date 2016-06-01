#include <cstdio>
using namespace std;

int main(){
    int T, n, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        bool ok = false;
        int sum = 0;
        for(int i = 0; i < n; i ++){
            scanf("%d", &x);
            sum ^= x;
            if(x > 1) ok = true;
        }
        printf("Case %d: ", cas);
        if((ok && sum) || (!ok && !sum)) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
