#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
const int N=50020;
int a[N];
ll sum[N];
int main() {
    cout<<acos(-0.5);
    int T,k,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++)scanf("%d",a+i);
        if(n==k) {
            puts("0");
            continue;
        }
        sort(a+1,a+n+1);
        sum[0]=0;
        for(int i = 1; i <= n; i++) sum[i]=sum[i-1]+a[i];
        k=n-k;
        db avg=0.0, avg_new, ans=0.0, dif, dx;
        int i = 1, j = i+k-1;
        avg=(sum[j]-sum[i-1])*1.0/k;
        for(int l = i; l <= j; l++) {
            ans+=(a[l]-avg)*(a[l]-avg);
            //printf("%d %d\n",l,a[l]);
        }
        dif=ans;
        //ans;
        //printf("ans = %f\n", ans);

        while(j+1<=n) {
            avg_new=(sum[j+1]-sum[i])*1.0/k;
            dx=avg-avg_new;
            dif-=(a[i]-avg)*(a[i]-avg);
            dif+=dx*dx*(j-i);
            dif+=2*dx*(sum[j]*1.0-sum[i]*1.0-(j-i)*avg);
            dif+=(a[j+1]-avg_new)*(a[j+1]-avg_new);
            ans=min(ans, dif);
            //printf("ans = %f\n", ans);
            avg=avg_new;
            i++,j++;
        }
        printf("%.10f\n", ans);
    }
}
