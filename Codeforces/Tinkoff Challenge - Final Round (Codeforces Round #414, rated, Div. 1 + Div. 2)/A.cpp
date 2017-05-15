#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a, b, c, x;
    scanf("%d%d%d", &a, &b, &c);
    assert(b < a);
    assert(c > a);
    int n;
    int ans =0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &x);
        if(x > b && x < c) ans ++;
    }
    printf("%d\n", ans);
    return 0;
}
