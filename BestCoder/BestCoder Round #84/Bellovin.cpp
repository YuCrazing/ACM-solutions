#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100010;
int a[MAXN], d[MAXN], LIS, b[MAXN];
int find(int x){
    int l = 0, r = LIS;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(d[mid] < x) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main(){
    int T, n;
    scanf("%d", &T);
    while(T --){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);


        LIS = 0;
        d[0] = 0;
        for(int i = 1; i <= n; i++){
            int pos = find(a[i]);
            if(pos == LIS){
                LIS ++;
                d[LIS] = a[i];
                b[i] = LIS;
            }else{
                d[pos + 1] = a[i];
                b[i] = pos + 1;
            }
        }

        for(int i = 1; i <= n; i ++)printf((i == n) ? "%d\n" : "%d ", b[i]);

    }
    return 0;
}
