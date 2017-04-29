#include<bits/stdc++.h>
using namespace std;

const int N = 33;
int T, n, m, k, p;
int item[N];
vector<int> wishes[N];
string wish;

void init() {
    memset(item, -1, sizeof(item));
    for(int i = 0; i < N; i++) wishes[i].clear();
}

int s2n(string& s) {
    int it = 0, sign = 1, l = s.size();
    if(s[0] == '-') sign = -1;
    for(int i = 1; i < l; i++) {
        it *= 10;
        it += s[i] - '0';
    }
    return it *= sign;
}

int main() {

    ios::sync_with_stdio(false);

    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        init();
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                cin >> wish;
                wishes[i].push_back(s2n(wish));
            }
        }
        cin >> p;
        for(int i = 0; i < p; i++) {
            int it;
            cin >> it;
            item[it] = 1;
        }
        bool ok = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                int it = wishes[i][j];
                if(it * item[it > 0 ? it : -it] > 0) break;
                if(j == k - 1) ok = false;
            }
        }
        cout << "Case " << ca << ": " << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
