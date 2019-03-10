// 从右往左，维护一个单调递减栈也可以

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];
int main() {

//    ios::sync_with_stdio(false);
//    cout.tie(0);

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    b[n] = 0;
    for(int i = n-1; i > 0; --i) {
        if(a[i] < a[i+1]) b[i] = i+1;
        else if(a[i] == a[i+1]) b[i] = b[i+1];
        else {
            int k = i+1;
            while(k && a[k] < a[i]) k = b[k];
            if(k == 0) b[i] = 0;
            else if(a[k] == a[i]) b[i] = b[k];
            else if(a[k] > a[i]) b[i] = k;
        }
    }

    for(int i = 1; i <= n; ++i) printf("%d\n", b[i]);

    return 0;
}

