#include <cstdio>
#include <algorithm>
using namespace std;

int dIP[4];
int bIP[4];
int b2d(int ip) {
    int res = 0, p = 1;
    while(ip) {
        res += (ip % 10) * p;
        ip /= 10;
        p <<= 1;
    }
    return res;
}
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d.%d.%d.%d", &dIP[0], &dIP[1], &dIP[2], &dIP[3]);
        scanf("%d.%d.%d.%d", &bIP[0], &bIP[1], &bIP[2], &bIP[3]);
        char same = true;
        for(int i = 0; i < 4; i ++)
            if(b2d(bIP[i]) != dIP[i]) {
                same = false;
                break;
            }
        printf("Case %d: ", cas);
        if(same) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
