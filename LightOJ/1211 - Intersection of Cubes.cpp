#include <cstdio>
#include <algorithm>
using namespace std;
int x, y, z, T, n;
int main(){
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca ++){
        scanf("%d", &n);
        int x_min, x_max, y_min, y_max, z_min, z_max;
        x_min = y_min = z_min = -1;
        x_max = y_max = z_max = 1001;
        for(int i = 0; i < 2*n; i ++){
            scanf("%d%d%d", &x, &y, &z);
            if(i&1){
                x_max = min(x_max, x);
                y_max = min(y_max, y);
                z_max = min(z_max, z);
            }else{
                x_min = max(x_min, x);
                y_min = max(y_min, y);
                z_min = max(z_min, z);
            }
        }
        printf("Case %d: %d\n", ca, max(0, x_max - x_min) * max(0, y_max - y_min) * max(0, z_max - z_min));
    }
    return 0;
}
