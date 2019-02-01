/*
    Proof:  https://codeforces.com/blog/entry/64833
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

//int get(int x) {
//    int sum = x;
//    while(sum >= 10) {
//        x = sum;
//        sum = 0;
//        while(x) {
//            sum += x%10;
//            x /= 10;
//        }
//    }
//    return sum;
//}

int main() {
//    for(int i = 1; i <= 111; ++i) printf("%d %d\n", i, get(i));
    int t;
    scanf("%d", &t);
    while(t--) {
        ll k;
        int x;
        scanf("%I64d%d", &k, &x);
        printf("%I64d\n", (k-1)*9+x);
    }
    return 0;
}

