#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
#define N 100010
int a[N];
int n;
int main()
{
    int sk;
    scanf("%d",&sk);
    while(sk--)
    {
        scanf("%d",&n);
        int odd=0;
        int even=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            if(a[i]&1) odd++;
            even+=a[i]/2;
        }
        if(odd==0) printf("%d\n",even*2);
        else
        {
            printf("%d\n",1+even/odd*2);
        }
    }
}
