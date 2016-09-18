#include <cstdio>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    scanf("%I64d", &n);
    printf("%d\n",2);
    for(ll i = 2; i <= n; i ++) printf("%I64d\n",(i + 1)*(i + 1)*i - (i-1));
    return 0;
}
