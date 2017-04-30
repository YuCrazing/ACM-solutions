#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

/*
    之前的做法想复杂了。
*/

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

    void print()
    {
        printf("%s %d %d %d\n", c, x, y, z);
    }

} p[55];


char s[10];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) p[i].read();

    double ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
    for(int k = j + 1; k < n; k++){
        if
        (
           (p[i].c[0] == p[j].c[0] && p[i].c[0] == p[k].c[0])
           ||
           (p[i].c[0] != p[j].c[0] && p[i].c[0] != p[k].c[0] && p[j].c[0] != p[k].c[0])
        )
           {
                ans = max(ans, ((p[k] - p[i]) ^ (p[j] - p[i])) / 2);
           }
    }

    printf("%.5f\n", ans);

    return 0;
}
