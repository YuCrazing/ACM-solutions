
// http://blog.sina.com.cn/s/blog_76344aef0100scyq.html (LIS--O(nlogn))
// http://blog.csdn.net/acdreamers/article/details/7626671 (Dilworth)

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100003;

int a[MAXN], d[MAXN], LIS, path[MAXN], len[MAXN];
int find(int x) {
    int l = 0, r = LIS;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(d[mid] < x) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main() {
    int T, n, dst;
    scanf("%d", &T);
    while(T --) {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) scanf("%d", &a[i]);

        LIS = 0;
        d[0] =  -1;

        for(int i = 0; i < n; i ++) {
            int l = find(a[i]);
            if(l == LIS) {
                d[++ LIS] = a[i];
                len[i] = LIS; //×ÖµäÐò×îÐ¡
            }
            else {
                d[l + 1] = a[i];
                len[i] = l + 1;
            }
        }

        printf("%d\n", LIS);
        int ct = 0;
        int l = LIS, lim = 1e9;
        for(int i = n - 1; i >= 0; i --){
            if(len[i] == l && a[i] < lim) {
                l --;
                lim = a[i];
                path[ct ++] = a[i];
            }
        }

        for(int i = ct - 1; i > -1; i --) printf((i == 0) ? "%d\n" : "%d ", path[i]);
    }
    return 0;
}

/*
10
4
3 4 1 2
6
2 5 3 1 2 6
6
2 3 4 1 2 5
*/
