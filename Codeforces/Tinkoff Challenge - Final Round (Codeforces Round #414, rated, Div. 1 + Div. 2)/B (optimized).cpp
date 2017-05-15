#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, h;
    scanf("%d%d", &n, &h);
    for(int i = 1; i < n; i++) {
        printf("%.10f ", h * sqrt(i * 1.0 / n));
    }
    return 0;
}
