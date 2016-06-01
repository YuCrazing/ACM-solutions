#include <cstdio>
using namespace std;

const int MAXN = 111;
int W[MAXN], B[MAXN];
int main(){
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) scanf("%d", &W[i]);
        for(int i = 0; i < n; i ++) scanf("%d", &B[i]);

        int sum = 0;
        for(int i = 0; i < n; i ++) sum ^= B[i] - W[i] - 1;

        printf("Case %d: ", cas);
        if(sum) printf("white wins\n");
        else printf("black wins\n");
    }
    return 0;
}
