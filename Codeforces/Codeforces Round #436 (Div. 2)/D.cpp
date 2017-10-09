#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N], n;
int vis[N];
bool tkn[N];
vector<int> v, p[N];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        vis[a[i]]++;
    }
    for(int i = 0; i < n; i++) {
        if(vis[a[i]]>=2) {
            v.push_back(i);
            p[a[i]].push_back(i);
        }
    }
    int ans=0, mx=-1;
    for(int i = 1; i <= n; i++) {
        if(vis[i]==1) continue;
        int pos, t, id;
        if(vis[i]>=2) {
            for(int j = 0; j < p[i].size(); j++){
                if(!tkn[p[i][j]]){
                    id=j;
                    break;
                }
            }
            pos = p[i][id];
        } else if(vis[i]==0) {
            ans++;
            while(1) {
                id=upper_bound(v.begin(), v.end(), mx)-v.begin();
                pos=v[id];
                t=a[pos];
                mx=pos;
                if((t>i&&pos==p[t][p[t].size()-1]) || tkn[pos]) {
                    continue;
                } else {
                    break;
                }
            }
        }
        tkn[pos]=true;
        a[pos]=i;
    }
    printf("%d\n", ans);
    for(int i = 0; i < n; i++) printf(i==n-1?"%d\n":"%d ", a[i]);
    return 0;
}
