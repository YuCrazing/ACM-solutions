#include <cstdio>
using namespace std;

int bin[44];
int binToDec(int len) {
    int res = 0;
    for(int i = len - 1; i > -1; i --) {
        res <<= 1;
        res += bin[i];
    }
    return res;
}
void show(int len) {
    for(int i = len-1; i > -1; i --) printf("%d", bin[i]);
    printf("\n");
}
int main() {
    int T, n, x, cnt, ans;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);

        cnt = 0;
        x = n;
        int ones = 0, zeros = 0;
        while(x) {
            if(x%2) {
                bin[cnt++] = 1;
                ones++;
            } else {
                bin[cnt++] = 0;
                zeros++;
            }
            x >>= 1;
        }

        x = n;
        int endZeros = 0;
        while(x%2 == 0) {
            endZeros ++;
            x >>= 1;
        }

        int pos = -1;
        for(int i = cnt - 1; i > 0; i--)
            if(bin[i] == 0 && bin[i-1] == 1) pos = i;

        if(ones == 1) ans = n << 1;
        else if(zeros == 0) ans = (1 << cnt) + (1 << cnt - 1) - 1;
        else if(endZeros > 0) {
            if(pos == -1) {
                cnt++;
                bin[cnt - 1] = 1;
                for(int i = 1; i < cnt; i ++) {
                    if(i <= zeros + 1)bin[cnt - 1 - i] = 0;
                    else bin[cnt - 1 - i] = 1;
                }
            } else {
                int ons = 0;
                for(int i = pos - 2; i > -1; i --) {
                    if(bin[i]) ons ++;
                    bin[i] = 0;
                }
                for(int i = 0; i < ons; i++) bin[i] = 1;
                bin[pos] = 1;
                bin[pos - 1] = 0;
            }
            ans = binToDec(cnt);
        } else {

            bin[pos] = 1;
            bin[pos - 1] = 0;

            ans = binToDec(cnt);
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
