#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1111];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int ans = 1e9, anst;
    for(int t = 1; t <= 100; ++t){
        int sum = 0;
        for(int i = 0; i < n; ++i){
            if(abs(t-a[i]) <= 1) continue;
            else if(a[i] < t) sum += t-a[i]-1;
            else sum += a[i] - t - 1;
        }
        if(sum < ans){
            ans = sum;
            anst = t;
        }
    }
    printf("%d %d\n", anst, ans);
    return 0;
}
