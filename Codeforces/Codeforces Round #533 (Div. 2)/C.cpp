#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, l, r;
int dp[N][3], divv[3];
int main() {
    scanf("%d%d%d", &n, &l, &r);

    // method 1
//    while(l%3 != r%3 && l < r) {
//        divv[l%3]++;
//        l++;
//    }
//
//    divv[l%3]++;
//    if(l!=r) for(int i = 0; i < 3; ++i) divv[i] += (r-l+1)/3;

    // method 2
    divv[0] = r/3 - (l-1)/3;
    divv[1] = (r+2)/3 - (l-1+2)/3;
    divv[2] = (r+1)/3 - (l-1+1)/3;

    dp[0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                dp[i+1][(j+k)%3] = (dp[i+1][(j+k)%3] + (ll)dp[i][j] * divv[k]%mod)%mod;
            }
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}
