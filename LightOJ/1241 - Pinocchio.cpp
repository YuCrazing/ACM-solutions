#include <cstdio>
#include <cstring>
using namespace std;

int a[11];
int main() {
    int T, n;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);

        int sum = 0;
        for(int i = 0; i < n; i++) {
            int diff;
            if(i == 0) diff = a[i] - 2;
            else diff = a[i] - a[i - 1];
            sum += (diff + 4) / 5;
        }
        printf("Case %d: %d\n", ca, sum);
    }
    return 0;
}
