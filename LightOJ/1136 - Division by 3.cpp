#include <cstdio>
using namespace std;

int main(){
    int T;
    unsigned a, b; //int overflow
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%u%u", &a, &b);
        a--;
        printf("Case %d: %u\n", cas, (b - (b+2)/3) - (a - (a+2)/3));
    }
    return 0;
}
