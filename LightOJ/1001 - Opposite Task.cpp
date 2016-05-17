//======================================================
// Author: Yu Chang
// Date: 2016-03-07
// E:\ACM-solutions\ACM-solutions\LightOJ\1001 - Opposite Task.cpp
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
        pr("%d %d\n", n/2, n - n/2);
    }
    return 0;
}
