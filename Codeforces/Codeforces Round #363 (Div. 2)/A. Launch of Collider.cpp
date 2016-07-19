#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
int a[200002];
int main(){
    int n;
    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i ++) cin >> a[i];
    int ans = 0x3f3f3f3f;
    if(n < 2) ans = -1;
    else{
        for(int i = 0; i< n - 1; i ++) if(s[i] == 'R'  && s[i + 1] == 'L') ans = min(ans, (a[i + 1] - a[i]) >> 1);
    }
    if(ans == 0x3f3f3f3f) ans = -1;
    cout << ans << endl;
    return 0;
}
