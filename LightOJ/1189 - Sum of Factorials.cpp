#include <cstdio>
using namespace std;

typedef long long ll;

const ll maxn = 1e18;
ll fac[30], n;
int ct, T, ans[30];

void init(){
    fac[0] = 1;
    for(ct = 1; ct < 30; ct++){
        if(maxn / ct < fac[ct - 1]) break;
        fac[ct] = ct * fac[ct - 1];
    }
}

int main(){
    init();
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++){
        scanf("%lld", &n);
        int num = 0;
        bool ok = true;
        for(int i = ct - 1; i >= 0; i--){
            if(n < fac[i]) continue;
            n -= fac[i];
            ans[num++] = i;
        }
        if(n != 0) ok = false;
        printf("Case %d: ", ca);
        if(ok){
            for(int i = num - 1; i >= 0; i--)
                printf((i == num - 1 ? "%d!" : "+%d!"), ans[i]);
            printf("\n");
        }else printf("impossible\n");
    }

    return 0;
}
