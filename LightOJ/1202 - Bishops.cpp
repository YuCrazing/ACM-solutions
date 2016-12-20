#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int T, x[2], y[2];
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
        int ans = 0;
        if(((x[0] + y[0])%2+2)%2 != ((x[1]+y[1])%2+2)%2) ans = -1;
        else if(abs(x[1] - x[0]) == abs(y[1] - y[0]))ans = 1;
        else ans = 2;
        printf("Case %d: ", cas);
        if(ans > 0) printf("%d\n", ans);
        else printf("impossible\n");
    }
    return 0;
}
