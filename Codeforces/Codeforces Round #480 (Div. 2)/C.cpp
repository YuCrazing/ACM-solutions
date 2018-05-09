/*
    IO:
        cin/cout: 404ms
        cin/cout(sync_with_stdio(false)): 109ms
        scanf/printf: 46ms

*/

#include<bits/stdc++.h>
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int x, c[256];

int main() {

//    ios::sync_with_stdio(false);
//    cin.tie(0);

    int n, k;
//    cin>>n>>k;
    scanf("%d%d", &n, &k);
    memset(c, -1, sizeof(c));
    for(int i = 0; i < n; i++) {
//        cin>>x;
        scanf("%d", &x);
        int j=x;
        if(c[j]!=-1) {

        } else {
            for(; j>=0; --j) if(c[j]!=-1 || x-j+1>k) break;
            if(j<0 || x-j+1>k) {
                ++j;
                for(int kk=j; kk<=x; ++kk) c[kk]=j;
            } else {
                if(x-c[j]+1 <= k) for(int kk=j; kk<=x; ++kk) c[kk]=c[j];
                else for(int kk=j+1; kk<=x; ++kk) c[kk]=j+1;
            }
        }
//        cout << c[x] <<" ";
        printf("%d ", c[x]);
    }

}
