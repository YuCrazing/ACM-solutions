#include <cstdio>
using namespace std;

int dig[20], pos;
int main() {
    int T, n;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);

        pos = 0;
        bool ok = true;
        if(n >= 10) {
            while(n) {
                dig[pos++] = n % 10;
                n /= 10;
            }
            for(int i = 0; i < pos; i++)
                if(dig[i] != dig[pos - 1 - i])
                    ok = false;
        }

        printf("Case %d: ", ca);
        printf(ok ? "Yes\n" : "No\n");
    }
    return 0;
}
