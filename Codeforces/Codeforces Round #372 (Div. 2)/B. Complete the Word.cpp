#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 50050;
char s[N];
int vis[27];
vector<int> vec;
int main() {
    scanf("%s", s);
    int n = strlen(s);
    if(n < 26) return printf("-1\n") * 0;
    bool ok = 0;
    for(int i = 0; i <= n - 26; i ++) {
        memset(vis, 0, sizeof(vis));
        vec.clear();
        for(int j = i; j < i + 26; j ++) {
            if(s[j] == '?') vis[26] ++;
            else vis[s[j] - 'A'] ++;
        }
        for(int j = 0; j < 26; j ++)
            if(vis[j] == 0) {
                vec.push_back(j);
            }
        int sz = vec.size();
        if(sz <= vis[26]) {
            ok = 1;
            int ct = 0;
            for(int j = i; j < i + 26; j ++)
                if(s[j] == '?') {
                    s[j] = vec[ct ++] + 'A';
                    if(ct >= sz) break;
                }
            break;

        }
    }
    if(!ok) printf("-1\n");
    else {
        for(int i = 0; i < n; i ++) {
            if(s[i] == '?') printf("A");
            else printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}
