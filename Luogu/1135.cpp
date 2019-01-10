#include<bits/stdc++.h>
using namespace std;

int n, a[222], d[222], A, B;

void bfs(){
    queue<int> Q;
    Q.push(A);
    d[A]=1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        int v = u-a[u];
        if(v>=0 && !d[v]) {
            d[v] = d[u] + 1;
            Q.push(v);
        }
        v = u+a[u];
        if(v<n && !d[v]) {
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }
}
int main(){
    scanf("%d%d%d", &n, &A, &B);
    --A;
    --B;
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    bfs();
    printf("%d\n", d[B]-1);
}
