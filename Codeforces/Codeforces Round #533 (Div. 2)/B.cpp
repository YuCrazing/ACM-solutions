#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int cnt[26];
vector<int> pos[30];
char s[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
//    for(int i = 0; i < n; ++i) {
//        if(i >= k) cnt[s[i-k]-'a']--;
//        cnt[s[i]-'a']++;
//        if(i >= k-1) {
//            for(int j = 0; j < 26; ++j) if(cnt[j] == k) {
//                    pos[j].push_back(i);
//                }
//        }
//    }
//    int ans = 0;
//    for(int i = 0; i < 26; ++i) {
//        int las = -1000000;
//        int sum = 0;
//        for(int j = 0; j < pos[i].size(); ++j) {
//            if(pos[i][j]-las >= k) {
//                sum++;
//                las = pos[i][j];
//            }
//        }
//        ans = max(ans, sum);
//    }
//    printf("%d\n", ans);

    // 确定贪心的策略之后，可以化简为以下代码
    int ans = 0;
    for(char ch = 'a'; ch <= 'z'; ++ch) {
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == ch) {
                ++cnt;
                if(cnt == k) {
                    ++sum;
                    cnt = 0;
                }
            } else cnt = 0;
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}
