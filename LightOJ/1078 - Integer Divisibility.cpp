#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {

    int T, n, d;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d %d", &n, &d);
        printf("Case %d: ", cas);
        int len = 1;
        int m = d;
        while(m % n){
            m = (m * 10 + d) % n;
            len ++;
        }
        printf("%d\n", len);
    }
    return 0;
}
