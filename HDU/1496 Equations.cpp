/*
G++ TLE
C++ AC
*/

#include<cstdio>
#include<cstring>
using namespace std;

const int N = 2e6 + 10;
const int F = 1e6;
int a, b, c, d, cnt[N];

int main() {
    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
        memset(cnt, 0, sizeof(cnt));
        int l = -100, r = 100;
        for(int i = l; i <= r; i++)
            for(int j = l; j <= r; j++)
                if(i && j) cnt[F + (a*i*i+b*j*j)]++;
        int sum = 0;
        for(int i = l; i <= r; i++)
            for(int j = l; j <= r; j++) {
                if(i && j) {
                    sum += cnt[F - (c*i*i+d*j*j)];
                }
            }
        printf("%d\n", sum);
    }
    return 0;
}
