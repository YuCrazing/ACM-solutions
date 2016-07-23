#include <bits/stdc++.h>

int a[111];
bool vis[111];
int main(){
    int n;
    int sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sum /= (n/2);

    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        for(int j = i + 1; j < n; j ++)
        if(!vis[j] && a[i] + a[j] == sum) {
            vis[j]= 1;
            printf("%d %d\n", i + 1, j + 1);
            break;
        }
    }

}
