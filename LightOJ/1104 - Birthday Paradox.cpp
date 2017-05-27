#include<bits/stdc++.h>
using namespace std;
typedef double db;

const int N = 1e5 + 2;
int n, T;
db sumLog[N];

void init() {
    sumLog[1] = sumLog[0] = 0;
    for(int i = 2; i < N; i++) sumLog[i] = sumLog[i - 1] + log(i);
}

db calc(int x) {
    if(x > n) return -1e5;
    return - x * (sumLog[n] - sumLog[n - 1]) + sumLog[n] - sumLog[n - x];
}

int BS() {
    int l = 0, r = 400;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(calc(mid) <= log(0.5)) r = mid;
        else l = mid + 1;
    }
    return --r;
}

int main() {

    init();

    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++) {
        scanf("%d", &n);
        printf("Case %d: %d\n",ca, BS());
    }
}
