#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int p[1011];
int ask(int n){

    if(p[n] != -1) return p[n];

    int ans = 0;
    if(n >= 100){
        int t = n / 100;
        ans += ask(t) + 7;
        if(n%100 > 0) {
            ans += 3;
            ans += ask(n%100);
        }
    }else{
        int t = n / 10;
        ans += ask(t * 10);
        if(n%10 > 0)
        ans += ask(n%10);
    }
    return p[n] = ans;
}

void init(){

    memset(p, -1, sizeof(p));

    p[1] = 3;
    p[2] = 3;
    p[3] = 5;
    p[4] = 4;
    p[5] = 4;
    p[6] = 3;
    p[7] = 5;
    p[8] = 5;
    p[9] = 4;
    p[10] = 3;

    p[11] = 6;
    p[12] = 6;
    p[13] = 8;
    p[14] = 8;
    p[15] = 7;
    p[16] = 7;
    p[17] = 9;
    p[18] = 8;
    p[19] = 8;

    p[20] = 6;
    p[30] = 6;
    p[40] = 5;
    p[50] = 5;
    p[60] = 5;
    p[70] = 7;
    p[80] = 6;
    p[90] = 6;

    p[1000] = 11;
}

int main(){
    init();
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        int sum = 0;
        for(int i = 1; i <= n; i ++) sum += ask(i);
        printf("%d\n", sum);
    }
    return 0;
}
