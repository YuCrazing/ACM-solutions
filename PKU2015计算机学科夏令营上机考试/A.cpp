#include <cstdio>
using namespace std;

int main() {
    int a[3] = {0, 0, 0}, n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &x);
        if(x == 1) a[0] ++;
        else if(x == 5) a[1] ++;
        else if(x == 10) a[2] ++;
    }
    for(int i = 0; i < 3; i ++) printf("%d\n", a[i]);
    return 0;
}
