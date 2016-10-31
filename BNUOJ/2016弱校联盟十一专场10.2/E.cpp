#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[4];
int main(){

    for(int i = 1; i <= 3; i ++) scanf("%lld", &a[i]);

    ll ans;
    if(a[2] == 0 && a[3] == 0) ans = a[1];
    else if(a[1] == 0 && a[3] == 0) ans = a[2];
    else if(a[1] == 0 && a[2] == 0) ans = a[3];
    else if(a[3] == 0) ans = 2 * a[2] + a[1];
    else if(a[2] == 0){
        if(a[1] > 1) ans = 3 * a[3] + a[1];
        else ans = a[3] * 2 + 1;
    }else if(a[1] == 0){
        if(a[2] > 1){
            ans = 3 * a[3] + 2 * a[2] - 2;
        }else ans = a[3] * 2 + 1;

    }else{
        ans = a[1] + 2 * a[2] + 3 * a[3];
    }

    printf("%lld\n", ans);
    return 0;
}
/*
0 2 1
1 0 1
0 0 0

7 7
1 2
2 3
3 1

4 5
5 6
6 7

3 7
*/
