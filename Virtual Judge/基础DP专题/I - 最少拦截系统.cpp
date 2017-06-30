#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N], num[N], k, n;

int BS(int x) {
    int l = 0, r = k;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(x > num[mid]) l = mid;
        else r = mid - 1;
    }
    return l + 1;
}

int solve() {
    k = 0;
    num[0] = -1;
    for(int i = 0; i < n; i++) {
        if(num[k] < a[i]) num[++k] = a[i];
        else num[BS(a[i])] = a[i];
    }
    return k;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        printf("%d\n", solve());
    }
    return 0;
}
