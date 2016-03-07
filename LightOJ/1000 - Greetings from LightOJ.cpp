//======================================================
// Author: Yu Chang
// Date: 2016-03-07
// E:\ACM-solutions\LightOJ\1000 - Greetings from LightOJ.cpp
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
    int T, a, b;
    sc("%d",&T);
    for(int cas = 1; cas <= T; cas++){
        sc("%d%d", &a, &b);
        pr("Case %d: %d\n", cas, a + b);
    }
    return 0;
}
