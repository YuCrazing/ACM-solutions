#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 3000010;

struct Node {

    int id, time;

    bool operator<(const Node &t)const {
        if(time == t.time) return id < t.id;
        return time < t.time;
    }

} a[N];

int main() {
    int T, n, k, q, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {

        scanf("%d%d%d", &n, &k, &q);
        for(int i = 1; i <= n; i ++) a[i].id = i;

        if(k > 1 && k < n) {
            for(int i = 1; i <= n; i ++) {
                if(i % k != 1) a[i].time = 1 + a[i - (i + k - 1) / k].time;
                else a[i].time = 1;
            }
            sort(a + 1, a + n + 1);
        }

        while(q --) {
            scanf("%d", &x);
            printf("%d\n", a[x].id);
        }
    }
    return 0;
}
