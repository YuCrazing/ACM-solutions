/*
    注意到最终选择的物品有这样的规律：
    1.按照物品的deadline顺序来解救的物品
    2.解救物品的时候，是从时间0开始，且中间没有间断。

    做法：
    按deadline排序，
    dp[i][j]表示从前i个物品中能解救的最大价值，且最后一个物品（可能不是第i个物品）救出的时间为j。
    若不选择救第i个物品，则dp[i][j]=dp[i-1][j]
    若选择救第i个物品，则dp[i][j]=dp[i-1][j-a[i].t]+a[i].p
    复杂度O(100*2000)
*/

#include<bits/stdc++.h>
using namespace std;

const int N=111;
const int M=2022;
struct Node {
    int t, d, p, id;
    bool operator<(const Node &t)const {
        return d<t.d;
    }
} a[N];

int fa[N][M], dp[N][M];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].p);
        a[i].id=i;
    }

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < a[i].d; j++) {
            dp[i][j]=dp[i-1][j];
            fa[i][j]=j;
            if(j>=a[i].t) {
                if(dp[i-1][j-a[i].t]+a[i].p>dp[i][j]) {
                    dp[i][j]=dp[i-1][j-a[i].t]+a[i].p;
                    fa[i][j]=j-a[i].t;
                }
            }
        }
    }

    int mx=-1, id;
    for(int i = 0; i <= a[n].d; i++) {
        if(dp[n][i]>mx) {
            mx=dp[n][i];
            id=i;
        }
    }

    stack<int> st;

    for(int i = n; i > 0; i--) {
        if(id!=fa[i][id]) {
            id=fa[i][id];
            st.push(i);
        }
    }

    printf("%d\n%d\n", mx, st.size());
    bool fi=true;
    while(!st.empty()) {
        printf(fi?"%d":" %d", a[st.top()].id),fi=false;
        st.pop();
    }
    puts("");
    return 0;
}
