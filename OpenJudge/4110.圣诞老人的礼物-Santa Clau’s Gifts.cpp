#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    int v, w;
    bool operator<(const Node b)const {
        return v * 1.0 / w > b.v * 1.0 / b.w;
    }
} a[111];
int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    for(int i = 0; i < n; i ++) scanf("%d%d",&a[i].v, &a[i].w);
    sort(a, a + n);
    double sum = 0;
    for(int i = 0; i < n; i ++) {
        if(w >= a[i].w) {
            sum += a[i].v;
            w -= a[i].w;
        }else {
            sum += 1.0 * w / a[i].w * a[i].v;
            break;
        }
        if(w <= 0) break;
    }
    printf("%.1f\n",sum);
    return 0;
}
