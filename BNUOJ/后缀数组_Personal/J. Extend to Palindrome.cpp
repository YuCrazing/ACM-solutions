#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int Next[N];

void initKMP(char *s, int n) {
    Next[0] = Next[1] = 0;
    int j = 0;
    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = Next[j];
        if(s[i] == s[j]) j++;
        Next[i + 1] = j;
    }
}

int KMP(char *s, int ls, char *t, int lt) {
    int j = 0;
    for(int i = 0; i < lt; i++) {
        while(j > 0 && s[j] != t[i]) j = Next[j];
        if(t[i] == s[j]) j++;
    }
    return j;
}

char s[N], t[N];
int main() {
    while(scanf("%s", s) != EOF) {

        int n = strlen(s);
        strcpy(t, s);
        reverse(t, t + n);

        initKMP(t, n);
        int l = KMP(t, n, s, n);
        printf("%s", s);
        if(l < n) for(int i = n - l - 1; i >= 0; i--) printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
