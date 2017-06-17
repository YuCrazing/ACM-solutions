#include<bits/stdc++.h>
using namespace std;

const int N = 1505;
int n, m, q, ans[N][26];
char s[N], ch[10];

int main() {

    for(int i = 0; i < N; i++)
        for(int j = 0; j < 26; j++) ans[i][j] = -1;

    scanf("%d%s%d", &n, s, &q);
    while(q--) {
        scanf("%d%s", &m, &ch);
        int k = m;
        int l, r, res;
        l = r = res = 0;
        while(r < n) {
            if(s[r] != ch[0])  {
                if(k > 0) {
                    k--;
                } else {
                    while(s[l] == ch[0]) l++;
                    l++;
                }
            }
            res = max(res, r - l + 1);
            r++;
        }
        ans[m][ch[0]-'a'] = res;
        printf("%d\n", res);
    }
    return 0;
}
