#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int p[111];
int main(){
    int n, a;
    scanf("%d%d", &n, &a);
    a --;
    for(int i = 0; i < n; i ++) scanf("%d", &p[i]);
    int l = min(abs(n - 1 - a), abs(a - 0));
    int sum = 0;
    if(p[a]) sum ++;
    for(int i = 1; i <= l; i ++){
        if(p[a - i] == 1 && p[a + i] == 1) sum += 2;
    }
    for(int i = 1; i <= n - 2*l - 1; i ++){
        if(p[(a + l + i)%n]) sum ++;
    }
    printf("%d\n", sum);
    return 0;
}
