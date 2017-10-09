#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, f, k;
    scanf("%d%d%d%d", &a, &b, &f, &k);
    bool ok=true;
    int ans=0;
    if(f>b) ok=false;
    if(k==1) {
        if(a-f>b) ok=false;
    } else if(k==2) {
        if(a-f>b) ok=false;
        if(2*(a-f)>b) ok=false;
    } else if(k>=3) {
        if(a-f>b) ok=false;
        if(2*(a-f)>b) ok=false;
        if(2*f>b) ok=false;
    }
    if(ok) {
        int t=b;
        int ct=0;
        while(k) {
            if(ct%4==0) {
                b-=f;
                if(k>1&&b<2*(a-f)) {
                    ans++;
                    b=t;
                } else if(k==1&&b<a-f) {
                    ans++;
                    b=t;
                }
            } else if(ct%4==1) {
                k--;
                b-=a-f;
            } else if(ct%4==2) {
                b-=a-f;
                if(k>1 && b<2*f) {
                    ans++;
                    b=t;
                } else if(k==1&&b<f) {
                    ans++;
                    b=t;
                }
            } else if(ct%4==3) {
                k--;
                b-=f;
            }
            //printf("%d %d\n",ct%4,ans);
            ct++;

        }
    }

    if(!ok)ans=-1;
    printf("%d\n", ans);
    return 0;
}
