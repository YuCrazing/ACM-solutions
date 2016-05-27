#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct point{
    int x, y;
};
point p[711];
ll dis[711*711];
int main(){
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        int cnt = 0;
        for(int i = 0; i < n; i ++){
            scanf("%d%d", &p[i].x, &p[i].y);
            for(int j = 0; j < i; j ++)
                dis[cnt++] =(p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (ll)(p[i].y - p[j].y);
        }
        sort(dis, dis + cnt); // essential
        int l = unique(dis, dis + cnt) - dis;
        printf("Case %d: %d\n", cas, l + 1);
    }
    return 0;
}
