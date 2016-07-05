#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int t, n, p, m;
    scanf("%d", &t);
    while(t --) {
        scanf("%d%d", &n, &p);
        m = 2 * n + p;
        int dif = 1;
        int cnt = 0;
        while(m --) {
            int u = cnt % n;
            int v = (u + dif) % n;
            printf("%d %d\n", u + 1, v + 1);
            if(m == 0) break;
            if((++ cnt) % n == 0) dif ++;
        }
    }
    return 0;
}
