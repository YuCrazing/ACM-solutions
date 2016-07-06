#include <cstdio>
using namespace std;
typedef long long ll;

int main(){
    int n, k, l, r;
    ll sum = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0;  i < n; i ++) {
        scanf("%d%d", &l, &r);
        sum += (r - l + 1);
    }
    if(sum % k == 0) printf("%d\n", 0);
    else printf("%d\n", k - sum % k);
    return 0;
}
