//======================================================
// Author: Yu Chang
// Date: 2016-03-07
// E:\ACM-solutions\ACM-solutions\LightOJ\1098 - A New Function.cpp
//======================================================
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define LL long long
#define pr printf
#define sc scanf
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int inf = 0x3f3f3f3f;
int main(){
    int T, n;
    sc("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        sc("%d", &n);
        LL sum = 0;
        for(int i = 1; i * i <= n; i++){
            int l = n/(i+1) + 1;
            int r = n/i;
            if(l<=r) sum += i * (r - l + 1) * (r + l) / 2;
        }
        sum -= n*(n+1)/2 + n - 1;
        pr("Case %d: %lld\n", cas, sum);
    }
    return 0;
}
