/*
    套路题
    把每个数的平方因子都除掉后，剩下的数只能：
    相同的数可以在一组，不同的数不能在一组，即统计所有子区间中的不同数字个数。
    注意 0 可以和任何数在一组。
*/

#include<bits/stdc++.h>
using namespace std;

const int N=5005;
const int M=1e4+5;
int a[N], b[N], id[N], n, ans[N], np[M];
vector<int> primes;
//unordered_set<int> st; // 特别慢
bool vis[N];

int main(){

    memset(np, 0, sizeof(np));
    for(int i = 2; i < M; ++i){
        if(!np[i]){
            primes.push_back(i);
            for(int j = i*i; j < M; j+=i){
                np[j]=1;
            }
        }
    }

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        int t=abs(a[i]);
        if(a[i]==0) continue;
        for(int j = 0; j < primes.size(); ++j){
            int sq=primes[j]*primes[j];
            if(sq > t) break;
            while(t%sq==0){ // !!!!!!!!!!!!! 写成了 if ....
                t /= sq;
                a[i] /= sq;
            }
        }
        ans[i]=0;
        b[i]=a[i];
    }

    sort(b, b+n);
    int m=unique(b, b+n)-b;
    for(int i = 0; i < n; ++i){
        id[i] = lower_bound(b, b+m, a[i])-b;
    }

    memset(vis, 0, sizeof(vis));
    for(int l = 0; l < n; ++l){
        int ct=0;
        for(int r = l; r < n; ++r){
            if(a[r] && !vis[id[r]]){
                vis[id[r]]=true;
                ++ct;
            }
            if(ct) ++ans[ct];
            else ++ans[1];
        }
        for(int r = l; r < n; ++r) vis[id[r]]=false;
    }

    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";

    return 0;
}
