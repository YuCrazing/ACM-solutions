#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[210][210][2];
int v[20020];
int main()
{
    //cout<<sizeof(dp)<<endl;
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",v+i);
        memset(dp,0,sizeof(dp));
        for(int i=2;i<=n;i++)v[i]+=v[i-1];
        for(int i=0;i<=n;i++)
            for(int j=1;j<=200;j++)
        {
            if(i<j)break;
            if(i==j)dp[i%210][j][0]=v[n]-v[n-i],dp[i%210][j][1]=v[n-i]-v[n];
            else
            {
                dp[i%210][j][0]=max(dp[(i-j)%210][j][1]+v[n-i+j]-v[n-i],dp[(i-j-1)%210][j+1][1]+v[n-i+j+1]-v[n-i]);
                dp[i%210][j][1]=min(dp[(i-j)%210][j][0]-v[n-i+j]+v[n-i],dp[(i-j-1)%210][j+1][0]-v[n-i+j+1]+v[n-i]);
            }
        }
//        for(int i=0;i<=n;i++)
//            for(int j=1;j<=4;j++)
//            for(int k=0;k<2;k++)
//            printf("dp %d %d %d = %I64d\n",i,j,k,dp[i][j][k]);
        printf("%d\n",dp[n%210][1][0]);
    }
    return 0;
}
