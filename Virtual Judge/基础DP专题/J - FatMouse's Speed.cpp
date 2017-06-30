#include<bits/stdc++.h>
using namespace std;

const int N = 1011;

struct Pig {
    int w, v, id;
    Pig(int w=0, int v=0, int id=0):w(w),v(v),id(id) {};
    bool operator<(const Pig& t)const {
        return w < t.w;
    }
} p[N];

int n = 0, w, v, ans, las, dp[N][2];
stack<int> st;
int main() {

    while(scanf("%d%d", &w, &v) != EOF) {
        p[n++] = Pig(w, v, n);
    }

    sort(p, p + n);

    ans = 0;
    for(int i = 0; i < n; i++) {
        int maxx = 0;
        int id = -1;
        for(int j = 0; j < i; j++) {
            if(p[j].w < p[i].w && p[j].v > p[i].v && dp[j][0] > maxx) {
                maxx = dp[j][0];
                id = j;
            }
        }
        dp[i][0] = maxx + 1;
        dp[i][1] = id;
        if(dp[i][0] > ans) {
            ans = dp[i][0];
            las = i;
        }
    }
    while(las!=-1) {
        st.push(las);
        las=dp[las][1];
    }
    printf("%d\n", ans);
    while(!st.empty()) {
        printf("%d\n", p[st.top()].id);
        st.pop();
    }
}
