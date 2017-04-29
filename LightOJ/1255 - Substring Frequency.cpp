#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e6 + 5;
int next[N];

void initKMP(char* s) {
    next[1] = 0;
    int j = 0, l = strlen(s);
    for(int i = 1; i < l; i++) {
        while(j > 0 && s[i] != s[j]) j = next[j];
        if(s[i] == s[j]) j ++;
        next[i + 1] = j;
    }
}

int KMP(char* s, char* t) {
    initKMP(s);
    int lt = strlen(t), ls = strlen(s), j = 0, ans = 0;
    for(int i = 0; i < lt; i++) {
        while(j > 0 && t[i] != s[j]) j = next[j];
        if(t[i] == s[j]) j ++;
        if(j == ls) ans ++;
    }
    return ans;
}

char a[N], b[N];

int main() {
    int T, ca;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca ++) {
        scanf("%s%s", b, a);
        printf("Case %d: %d\n", ca, KMP(a, b));
    }
    return 0;
}
