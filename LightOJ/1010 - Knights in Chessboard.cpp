#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int T, n, m, minn, maxx, cas = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        minn = min(n, m);
        maxx = max(n, m);
        printf("Case %d: ", ++cas);
        if(minn == 1) printf("%d\n", maxx);
        else if(minn == 2) printf("%d\n", maxx/4 * 4 + min(2*(maxx%4), 4));
        else printf("%d\n", (n*m + 1)/2);
    }
    return 0;
}
