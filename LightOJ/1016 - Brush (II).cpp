#include <cstdio>
#include <algorithm>
using namespace std;

int y[50000];
int main(){
    int T, n, w, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &n, &w);
        for(int i = 0; i < n;  i++) scanf("%d%d", &x, &y[i]);
        sort(y, y + n);
        int l = unique(y, y + n) - y;

        int sum = 0, brush = y[0];
        while(1){
            sum ++;
            brush += w + 1;
            int i = lower_bound(y, y + l, brush) - y;
            if(i == l) break;
            brush = y[i];
        }
        printf("Case %d: %d\n", cas, sum);
    }
    return 0;
}
