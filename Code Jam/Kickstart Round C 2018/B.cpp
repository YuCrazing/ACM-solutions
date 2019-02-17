/*
    如何计算方案数上限： https://code.google.com/codejam/contest/4384486/dashboard#s=a&a=1

Let's try to prove the upper bound on the total number of different pairings. Let's consider the case in which the total number of nodes (N) is even and we have exactly N/2 pairings; let us denote the total number of ways to create these N / 2 pairings as f(N).

If we try to generate all possibilities via brute-force code, then one strategy can be to choose the minimum numbered (starting from 1) unused vertex and try to pair it with all the remaining vertices (see code in later section). We can say that at every level when we are forming a new pairing we are choosing one vertex of the pairing in exactly one way (i.e. minimum numbered (starting from 1) unused vertex) and the other vertex of pairing can be any of the remaining vertices. For example, if the unused vertices are (2,5,6,8,9,10), then we start by choosing 2 (the minimum number) as one vertex, and then we try to pair it with all 5 of the remaining vertices. Whenever we choose a particular pair, we mark both vertices as used, and then we recursively pair up the rest. In mathematical terms, we can represent the total number of ways to form such pairings as follows:

f(N) = (N - 1) * (N - 3) .... * 1

But in our problem there can be any number of edges in final polygon, not just N/2. It might be a good idea to try to derive a more general expression before you keep reading!

So we can calculate the total pairings by choosing any set of an even number of vertices and pairing them all up, which gives us the total number as:

g(N) = Σ C(N, i) * f(i), where i is even and C(N, i) is the number of ways of choosing i objects out of N different objects.

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 15;
vector< pair<int,int> > sticks;
int tol, selected[10], len[N][N], ans;

void dfs(int cur, int sta) {
    if(cur == sticks.size()) {
        if(tol <= 2) return;
        int sum = 0, mx = -1, l;
        for(int i = 0; i < tol; ++i) {
            l = len[sticks[selected[i]].first][sticks[selected[i]].second];
            sum += l;
            mx = max(mx, l);
        }
        if(sum - mx > mx) ++ans;
        return ;
    }
    dfs(cur+1, sta);
    int tmp = ((1<<sticks[cur].first) | (1<<sticks[cur].second));
    if(!(sta&tmp)) {
        selected[tol++] = cur;
        dfs(cur+1, sta|tmp);
        --tol;
    }
}

void init() {
    ans = tol = 0;
    sticks.clear();
}

int main() {

    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);

    int T, n;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca) {

        init();

        cin >> n;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                cin >> len[i][j];
                if(len[i][j] && i < j) sticks.push_back({i, j});
            }
        }
        dfs(0, 0);
        cerr << ca << endl;
        cout << "Case #" << ca << ": " << ans << endl;
    }
    return 0;
}
