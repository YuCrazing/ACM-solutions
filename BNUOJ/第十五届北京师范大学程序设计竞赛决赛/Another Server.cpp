#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, x, y, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int ans = 1e9;
        for(int i = 0; i < n - 1; i++){
            scanf("%d%d", &x, &y);
            ans = min(ans, x + y);
        }
        printf("%d\n", ans);
    }
}
