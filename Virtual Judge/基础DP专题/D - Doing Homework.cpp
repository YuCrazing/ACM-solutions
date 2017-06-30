#include<bits/stdc++.h>
using namespace std;

const int N = 15;
const int INF = 0x3f3f3f3f;

struct work {

    string name;
    int ddl, time;

    void read() {
        cin>>name>>ddl>>time;
    }

} w[N];

int T, n, ans, dp[1<<N][3];

void init() {
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = -1;
}

int dfs(int s) {
    int& dp0 = dp[s][0];
    if(dp0!=INF) return dp0;
    int& dp1 = dp[s][1];
    int& dp2 = dp[s][2];

    for(int x = 0; x < n; x++) {
        if(s&(1<<x)) {
            int ss = s^(1<<x);
            int t = dfs(ss) + max(dp[ss][1]+w[x].time-w[x].ddl, 0);
            if(t < dp0) {
                dp0 = t;
                dp1 = dp[ss][1]+w[x].time;
                dp2 = x;
            } else if(t == dp0 && w[x].name > w[dp2].name) {
                dp1 = dp[ss][1]+w[x].time;
                dp2 = x;
            }
        }
    }
    return dp0;
}

int main() {

    ios::sync_with_stdio(false);

    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; i++) w[i].read();

        init();

        int sta = (1<<n)-1;
        ans = dfs(sta);
        int las = dp[sta][2];

        stack<int> st;
        while(las!=-1) {
            st.push(las);
            sta ^= (1<<las);
            las = dp[sta][2];
        }

        cout << ans << endl;
        while(!st.empty()) {
            cout << w[st.top()].name << endl;
            st.pop();
        }
    }
    return 0;
}
