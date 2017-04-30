#include<cstdio>
#include<list>
#include<algorithm>
using namespace std;
 
const int mod = 2017;
int n, k;
int dp[1111][1111];
 
void add(int& a, int b){
    a = (a + b % mod) % mod;
}
void init(){
    dp[2][0] = 1;
    dp[2][1] = 1;
    for(int i = 2; i <= 1000; i++){
        for(int j = 0; j <= i - 1; j++){
            add(dp[i + 1][j + 1], dp[i][j]);
            add(dp[i + 1][j], dp[i][j]);
            add(dp[i + 1][j], j * dp[i][j]);
            add(dp[i + 1][j + 1], (i - 1 - j) * dp[i][j]);
        }
    }
}
int main()
{
    init();
    scanf("%d%d", &n, &k);
    printf("%d\n", dp[n][k]);
    return 0;
}