#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
int Next[N];
char s[N];

int KMP() {
    int n = strlen(s), j = 0;
    Next[0] = Next[1] = 0;
    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = Next[j];
        if(s[i] == s[j]) j++;
        Next[i + 1] = j;
    }

    int ans = 1;
    while(j > 0) {
        if(n%(n-j) == 0) ans = max(ans, n/(n-j));
        j = Next[j];
    }
    return ans;
}
int main() {
    while(scanf("%s", s) != EOF) {
        if(!strcmp(s, ".")) break;
        printf("%d\n", KMP());
    }
    return 0;
}
