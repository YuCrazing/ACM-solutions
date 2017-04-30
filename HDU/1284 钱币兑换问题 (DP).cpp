#include<bits/stdc++.h>
using namespace std;

/*
    dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i]];

    dp[i - 1][j] ��ʾֻʹ��ǰ i - 1 ��Ӳ����ϳ� j ��
    dp[i][j - coin[i]] ��ʾ����ʹ�� 1 ���� i ��Ӳ����ϳ� j ��
*/

const int N = 32768;
int dp[N], n;

void init() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= 3; i++)
        for(int j = i; j < N; j++)
            dp[j] += dp[j - i];
}

int main() {

    init();

    while(scanf("%d", &n) != EOF) {
        printf("%d\n", dp[n]);
    }
    return 0;
}
