#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N];
int main(){
    int n , q, x;
    scanf("%d", &n);
    for(int i = 0; i < n;  i++) scanf("%d", &a[i]);
    sort(a, a + n);
    scanf("%d", &q);
    for(int i = 0; i < q; i ++){
        scanf("%d", &x);
        printf("%d\n", upper_bound(a, a + n, x) - a);
    }
    return 0;
}
