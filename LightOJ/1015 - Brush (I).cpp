#include <cstdio>
using namespace std;

int main(){
    int T, sum, x, n, cas = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        sum = 0;
        while(n--){
            scanf("%d", &x);
            if(x > 0)sum += x;
        }
        printf("Case %d: %d\n", ++cas, sum);
    }
    return 0;
}
