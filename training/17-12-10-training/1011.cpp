#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, n;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++){
        scanf("%d", &n);
        unsigned long long ans=0;
        if(n==0) ans=1;
        else if(n==1) ans=9;
        else if(n==2) ans=41;
        else if(n==3) ans=109;
        else if(n==4) ans=205;
        else {
            unsigned long long t=n;
            ans=t*t*14-t*6+5;
        }
        cout<<"Case #" <<ca<<": "<<ans<<endl;
    }
    return 0;
}
