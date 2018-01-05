#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

vector<int> v;
vector<long long> ans;
int main() {
    int n, x;
    ull sum;
    ull one=1;
    long long t;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.push_back(x);
        if(x<128) {
            sum=0;
            for(int i = 0; i < v.size(); i++) {
                if(v[i]>=128) v[i]-=128;
                sum+=v[i]*(one<<(i*7));
            }
            if(sum%2==1) {
                sum/=2;
                sum++;
                t=sum;
                t=-t;
            } else {
                t=sum/2;
            }
            ans.push_back(t);
            v.clear();
        }
    }
    for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
