#include<bits/stdc++.h>
using namespace std;

int main(){
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = 2;
    if(l == r) ans = l;
    printf("%d\n", ans);
    return 0;
}
