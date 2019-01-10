#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100003;

int a[MAXN], d[MAXN], LIS;

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
        d[0] = -1;

        for(int i = 0; i < n; i ++) {
            int l = find(a[i]);
            if(l == LIS) {
                d[++ LIS] = a[i];
            } else {
                d[l + 1] = a[i];
            }
        }

        printf("%d\n", LIS);
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
