#include<cstdio>
#include<cassert>
#include<algorithm>
using namespace std;
 
int a[55];
int main()
{
 
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
 
    int ans = 0;
    assert(n >= 2);
 
    for(int i = 0; i < n - 1; i++)
    {
        ans += abs(a[i]-a[i + 1]);
    }
 
    int maxx = 0;
    for(int i = 1; i < n - 1; i++)
    {
        maxx = max(maxx, abs(a[i] - a[i-1]) + abs(a[i] - a[i+1]) - abs(a[i+1] - a[i-1]));
    }
 
    printf("%d\n", ans - maxx);
 
 
    return 0;
}