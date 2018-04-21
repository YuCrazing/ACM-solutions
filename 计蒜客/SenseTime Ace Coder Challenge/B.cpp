#include<bits/stdc++.h>

using namespace std;

const int N = 202;
int T, n, cnt[N];
bitset<N> bit[N][N], st, si, sj;
char s[N][N];
int main() {

//    freopen("in.in", "r", stdin);

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            cnt[i]=0;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i==j) continue;
                bit[i][j].reset();
                for(int k = 0; k < n; k++) {
                    if(i==k || j==k) continue;
                    if(s[i][k] == '1' && s[k][j] == '1') bit[i][j].set(k);
                }
                if(s[i][j] == '1') cnt[i]++;
            }
        }

        bool ok = false;
        for(int i = 0; i < n; ++i) {
            if(cnt[i]<2) continue;
            for(int j = 0; j < n; ++j) {
                if(i==j || cnt[j]<2 || s[i][j]!='1') continue;

                for(int k = 0; k < n; ++k) {
                    if(i==k || j==k || cnt[k]<2) continue;

                    si = bit[i][k];
                    sj = bit[j][k];
                    si.reset(j);
                    sj.reset(i);
                    if(si.none() || sj.none()) continue;

                    st = (si | sj);
                    if(st.count()>1) ok=true;

                    if(ok) break;
                }

                if(ok) break;
            }
            if(ok) break;
        }

        printf("Case #%d: ", ca);
        if(ok) puts("Starfish!");
        else puts("Walk Walk");
    }
    return 0;
}
/*

5
01011
10100
01010
00101
10010

*/
