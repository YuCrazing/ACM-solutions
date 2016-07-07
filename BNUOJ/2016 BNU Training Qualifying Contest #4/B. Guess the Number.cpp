#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

char s[5];
int main(){
    int l = 1, r = 1000000;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        printf("%d\n", mid);
        fflush(stdout);
        scanf("%s", s);
        if(s[0] == '<') r = mid - 1;
        else l = mid;
    }
    printf("! %d\n", l);
    fflush(stdout);
    return 0;
}
