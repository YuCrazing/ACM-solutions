#include <cstdio>
using namespace std;

int a[111][111];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            scanf("%d", &a[i][j]);
    for(int k = 0; k < n + m - 1; k ++){
       if(k < m)for(int j = k; j > -1; j --) printf("%d\n", a[k - j][j]);
       else for(int i = k - m + 1; i < n; i ++) printf("%d\n", a[i][k - i]);
    }
    return 0;
}
