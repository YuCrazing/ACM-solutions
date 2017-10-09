#include<bits/stdc++.h>
using namespace std;

const int N=1010;
bool g[N][N];
int main(){
    freopen("in.in", "w", stdout);
    srand(time(0));
    int n=rand()%10;
    int m=0;
    int q=rand()%100;
    int k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(i!=j) g[i][j]=rand()%2;
            if(g[i][j]) m++;
        }
    printf("%d %d %d\n", n, m, q);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(g[i][j]) printf("%d %d\n", i, j);
    for(int i = 1; i <= q; i++){
        printf("%d %d %d\n", rand()%n+1, rand()%n+1, rand()%n+1);
    }
    return 0;
}
