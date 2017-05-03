#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x, sum = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += (x + k - 1) / k;
    }
    printf("%d\n", (sum + 1) / 2);
    return 0;
}
