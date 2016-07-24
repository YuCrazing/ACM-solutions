//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int p[33];
ll gao(int n, int m){
    ll res = 0;
    for(int i = min(m, 30) ; i >= 0; i --){
        int t = n / p[i];
        n -= t * p[i];
        res += t;
        if(n <= 0) break;
    }
    return res;
}
int main(){
    p[0] = 1;
    for(int i = 1; i < 31; i ++) p[i] = 2 * p[i - 1];
    int T, n, m;
    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &n, &m);
        printf("%I64d\n", gao(n, m));
    }
    return 0;
}
