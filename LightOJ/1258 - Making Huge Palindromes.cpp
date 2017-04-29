#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;

char s[N], t[N];
int next[N];

void initKmp() {
    int ls = strlen(s), j = 0;
    next[1] = 0;
    for(int i = 1; i < ls; i++) {
        while(j > 0 && s[i] != s[j]) j = next[j];
        if(s[i] == s[j]) j++;
        next[i + 1] = j;
    }
}

int Kmp() {
    initKmp();
    int ls = strlen(s), lt = strlen(t), j = 0;
    for(int i = 0; i < lt; i++) {
        while(j > 0 && t[i] != s[j]) j = next[j];
        if(t[i] == s[j]) j++;
    }
    return j;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%s", t);
        int l = strlen(t);
        for(int i = 0; i < l; i++) s[i] = t[l - 1 - i];
        s[l] = 0;
        printf("Case %d: %d\n", ca, 2 * l - Kmp());
    }
    return 0;
}
