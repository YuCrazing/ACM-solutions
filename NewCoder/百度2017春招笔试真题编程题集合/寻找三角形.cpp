#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;
 
struct Point
{
    int x, y, z;
    char c[3];
    Point() {};
    Point(int _x, int _y, int _z):x(_x), y(_y), z(_z) {};
 
    void read()
    {
        scanf("%s%d%d%d", c, &x, &y, &z);
    }
 
    Point operator-(const Point& b)const
    {
        return Point(x - b.x, y - b.y, z - b.z);
    }
 
    double operator^(const Point& b)const
    {
        Point t = Point(y*b.z-z*b.y, z*b.x-x*b.z,x*b.y-y*b.x);
        return t.len();
    }
 
    double len()
    {
        return sqrt((double)x * (double)x + (double)y * (double)y + (double)z * (double)z);
    }
 
    bool operator<(const Point &b)const
    {
        return c[0] < b.c[0];
    }
 
    void print()
    {
        printf("%s %d %d %d\n", c, x, y, z);
    }
 
} p[55];
 
double calc(int l, int r)
{
    double ans = 0;
    for(int i = l; i <= r; i ++)
    {
        for(int j = i + 1; j <= r; j++)
        {
            for(int k = j + 1; k <= r; k++)
            {
                ans = max(ans, ((p[j] - p[i])^(p[k] - p[i])) * 1.0 / 2);
            }
        }
    }
    return ans;
}
 
char s[10];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        p[i].read();
    }
 
    sort(p, p + n);
 
//    for(int i = 0; i < n; i++)
//    {
//        p[i].print();
//    }
 
    int col = 0, pos[3];
    for(int i = 0; i < n - 1; i++)
    {
        if(strcmp(p[i].c, p[i+1].c))
        {
            pos[col++] = i;
        }
    }
 
    double ans = 0;
 
    if(col == 0)
    {
        ans = calc(0, n - 1);
    }
    else if(col == 1)
    {
        ans = max(ans, calc(0, pos[0]));
        ans = max(ans, calc(pos[0] + 1, n - 1));
    }
    else if(col == 2)
    {
        ans = max(ans, calc(0, pos[0]));
        ans = max(ans, calc(pos[0] + 1, pos[1]));
        ans = max(ans, calc(pos[1] + 1, n - 1));
 
        for(int i = 0; i <= pos[0]; i ++)
        {
            for(int j = pos[0] + 1; j <= pos[1]; j++)
            {
                for(int k = pos[1] + 1; k <= n - 1; k++)
                {
                    ans = max(ans, ((p[j] - p[i])^(p[k] - p[i])) * 1.0 / 2);
                }
            }
        }
    }
    else
    {
        assert(0);
    }
    printf("%.5f\n", ans);
 
    return 0;
}