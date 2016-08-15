#include <cstdio>
#include <cstring>
using namespace std;

char s[111111];
int vis[30];
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%s", s);
        memset(vis, 0, sizeof(vis));
        int l = strlen(s);
        for(int i = 0; i < l; i ++) {
            vis[s[i] - 'a'] ++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i ++) if(vis[i]) ans ++;
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
