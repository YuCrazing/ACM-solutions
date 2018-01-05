#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int q[2000];

int main() {
    int n;
    ll k;
    scanf("%d%I64d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &q[i]);
    }
    int l=1, r=2, ans=-1;
    int ct=0;
    while(1) {
        if(q[l]==n) {
            ans=n;
            break;
        }
        //int ct=0;
        while(q[l]>q[r]) {
            r++;
            ct++;
        }
        if(ct>=k) {
            ans=q[l];
            break;
        }
        ct=1;
        l=r;
        r++;
    }
    printf("%d\n", ans);
    return 0;
}
