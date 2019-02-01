/*
    其他做法：
    将每段连续相同字符去除，排序后取前 k 个
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define lson (rt<<1)
#define rson (rt<<1|1)

const int N = 2e5 + 5;
priority_queue<int, vector<int>, greater<int> > Q;

char s[N];
int a[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%s", s+1);

    ll sum = 0;

    Q.push(a[1]);
    for(int i = 2; i <= n; ++i) {
        if(s[i]==s[i-1]) {
            if(Q.size() < k) {
                Q.push(a[i]);
            } else {
                if(Q.top() < a[i]) {
                    Q.pop();
                    Q.push(a[i]);
                }
            }
        } else {
            while(!Q.empty()) {
                sum += Q.top();
                Q.pop();
            }
            Q.push(a[i]);
        }

    }

    while(!Q.empty()) {
        sum += Q.top();
        Q.pop();
    }

    printf("%I64d\n", sum);

    return 0;
}

