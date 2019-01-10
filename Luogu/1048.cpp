#include<bits/stdc++.h>
using namespace std;

const int N = 111;
int n, C, w[N], v[N], dp[1111];

int main(){
    scanf("%d%d", &C, &n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &w[i], &v[i]);
    }

    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i){
        for(int j = C; j >= 0; --j){
            if(j>=w[i]) dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    printf("%d\n", dp[C]);
    return 0;
}
