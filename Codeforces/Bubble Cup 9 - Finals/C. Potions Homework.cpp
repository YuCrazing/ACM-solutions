#include <cstdio>
#include <algorithm>
using namespace std;

long long a[100010];
const long long mod = 10007;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%I64d", &a[i]);
    sort(a, a + n);
    long long sum = 0;
    for(int i = 0; i < n; i ++) {
        sum += a[n - i - 1] * a[i] % mod;
        sum %= mod;
    }
    printf("%I64d\n", sum);
    return 0;
}
