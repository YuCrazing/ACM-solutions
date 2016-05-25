#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int T, N, C;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &N, &C);
        double x = 1.0 * C / (2 * N);
        printf("Case %d: ", cas);
        if(x < 0 || N == 0) printf("%d\n", 0);
        else{
            if(C%N==0 && (C/N)%2) printf("%.0f\n",floor(x)); // x = ***.5
            else printf("%.0f\n", x);
        }
    }
    return 0;
}
