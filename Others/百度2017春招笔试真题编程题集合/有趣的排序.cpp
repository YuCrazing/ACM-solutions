#include<cstdio>
#include<list>
#include<algorithm>
using namespace std;
 
int n, x;
list<int> li;
int main()
{
    li.clear();
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &x);
        li.push_back(x);
    }
 
    list<int>::iterator it, mark, t;
    int ans = 0;
    while(1)
    {
        int minn = 111111;
        for(it = li.begin(); it != li.end(); it++)
        {
            int now = *it;
            bool ok = 0;
 
            for(t = ++it; t != li.end(); t++)
            {
                if(now > *t)
                {
                    ok = 1;
                    break;
                }
            }
            it--;
            if(ok)
            {
                if(now < minn)
                {
                    minn = now;
                    mark = it;
                }
            }
        }
//        printf("minn = %d\n", minn);
        if(minn == 111111) break;
        li.erase(mark);
        li.push_back(minn);
        ans++;
    }
    printf("%d\n", ans);
 
    return 0;
}