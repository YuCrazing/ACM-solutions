#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
int n,m;
uint a[10000001];
struct node
{
    int x,o;
} p[105];
uint ans[105],x,y,z;
unsigned rng61()
{
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}
bool cmp(const node &a,const node &b)
{
    return a.x<b.x;
}
int main()
{
    int cas=0;
    while(scanf("%d%d%u%u%u",&n,&m,&x,&y,&z)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            a[i]=rng61();
        }
        //assert(0);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&p[i].x);
            p[i].x++;
            p[i].o=i;
        }
        sort(p+1,p+m+1,cmp);
        reverse(p+1, p+m+1);
        for(int i=1;i<=m;i++)
        {
            if(p[i].x!=p[i-1].x||i==1)
            {
                nth_element(a+1,a+p[i].x,i==1?a+n+1:a+p[i-1].x);
                ans[p[i].o]=a[p[i].x];
            }
            else
            {
                ans[p[i].o]=ans[p[i-1].o];
            }
        }
        printf("Case #%d:",++cas);
        for(int i=1;i<=m;i++)
            printf(" %u",ans[i]);
        printf("\n");
    }
}
