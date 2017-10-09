#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int x, y, n, m, T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &x, &y, &m, &n);
        int ans=0;
        //rintf("%d %d\n", m, n);
        if(n==0 && m==0) {
            ans=0;
        } else if(m==0) {
            while(n) {
                n--;
                n=(n+1)>>1;
                ans+=y;
            }
        } else if(n==0) {
            while(m) {
                m--;
                m=(m+1)>>1;
                ans+=x;
            }
        } else {
            while(n>1) {
                n-=2;
                n=(n+1)>>1;
                ans+=y;
            }
            //printf("ans=%d %d\n", ans, n);
            if(n==1) {
                if(m==1) ans+=x+y;
                else {
                    while(m) {
                        m--;
                        m=(m+1)>>1;
                        ans+=x;
                    }
                    ans+=y;
                }
            } else {
                while(m) {
                    m--;
                    m=(m+1)>>1;
                    ans+=x;
                }
            }
        }
        printf("%d\n", 11);
    }
    return 0;
}
/*

1
1 10 1 2

*/
