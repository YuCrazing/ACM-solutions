#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int T, a[3];
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        for(int i = 0; i < 3; i ++)scanf("%d", &a[i]);
        sort(a, a+3);
        printf("Case %d: ", cas);
        printf(a[2]*a[2] - a[1]*a[1] == a[0]*a[0] ? "yes\n" : "no\n");
    }

    return 0;
}
