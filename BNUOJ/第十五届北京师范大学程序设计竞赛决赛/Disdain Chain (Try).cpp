#include<bits/stdc++.h>
using namespace std;

int n, T;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i < n; i++) printf("0\n");
        printf("%d\n", 1<<(n*(n-1)/2));
    }
    return 0;
}
