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
    int k, a, b, v;
    scanf("%d%d%d%d", &k, &a, &b, &v);
    int x = b / (k - 1);
    int v1 = k * v;
    int b_1 = b - x * (k - 1);
    int v2 = (b_1 + 1) * v;
    if(a <= x * v1) printf("%d\n",(a + v1 - 1)/v1);
    else {
        if(x * v1 + v2 >= a) printf("%d\n", x + 1);
        else {
            a -= v1 * x + v2;
            printf("%d\n",1 + x + (a + v - 1)/v);
        }
    }
    return 0;
}
