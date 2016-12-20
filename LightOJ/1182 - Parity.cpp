#include <cstdio>
using namespace std;

int main(){
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        int cnt = 0;
        while(n){
            if(n%2) cnt ++;
            n >>= 1;
        }
        printf("Case %d: ", cas);
        printf((cnt%2) ? "odd\n" : "even\n");
    }
    return 0;
}
