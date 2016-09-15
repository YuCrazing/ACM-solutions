#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
#define N 5000010
int main()
{
    int sk;
    scanf("%d",&sk);
    while(sk --)
    {
        long long n;
        scanf("%I64d",&n);
        long long x=(n+1)/2;
        if(n%2==0) x++;

        long long ans=n-x+1;

        long long y = (n-1) / 3;
        if(3*y <= n - 1) y ++;
        if(y%2 == 0) y ++;
        if(n%2 == 0) n --;
        if(n - y >=0) ans += (n - y)/2 + 1;
        printf("%I64d\n",ans);
    }
}
