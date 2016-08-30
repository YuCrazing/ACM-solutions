#include <cstdio>
#include <cstring>
using namespace std;

char s[1111][11];
int main() {
    int n;
    bool ok = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%s", s[i]);
        if(!ok) {
            if(s[i][0] == s[i][1] && s[i][0] == 'O') {
                ok = 1;
                s[i][0] = s[i][1] = '+';
            }
        }
        if(!ok) {
            if(s[i][3] == s[i][4] && s[i][3] == 'O') {
                ok = 1;
                s[i][3] = s[i][4] = '+';
            }
        }
    }
    if(ok) {
        printf("YES\n");
        for(int i = 0;  i< n; i ++) printf("%s\n", s[i]);
    }else printf("NO\n");
    return 0;
}
