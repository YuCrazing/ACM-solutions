#include<bits/stdc++.h>
using namespace std;

const int N=110;
struct Node{
    int id, r;
};
int a[N],  m, n, p, s[N];
bool check(int ddl){


}
int bs(int ll, int rr){
    while(ll<rr){
        int mid=(ll+rr+1)>>1;
        if(check(mid)) ll=mid;
        else rr=mid-1;
    }
    return ll;
}
int main(){
    scanf("%d%d%d", &m, &n, &p);
    for(int i = 1; i <= m; i++) scanf("%d", &s[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &r[i]);

    bs()
    return 0;
}
