#include <cstdio>
using namespace std;

const int N = 111111;
int a[N];
int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for(int i = 0;  i < n;  i++) scanf("%d", &a[i]);
    int ans = 1;
    for(int i = n - 2; i >= 0; i --) {
        if(a[i + 1] - a[i] <= c) ans ++;
        else break;
    }
    printf("%d\n", ans);
    return 0;
}
