#include <cstdio>
#include <algorithm>
using namespace std;

int divs[1111];
int a[1111];

bool cmp(int x, int y){
    if(divs[x] == divs[y]) return x > y;
    return divs[x] < divs[y];
}

int main(){

    for(int i = 1; i <= 1000; i++){
        a[i] = i;
        divs[i] = 0;
        for(int j = 1; j <= i; j++)
            if(i % j == 0) divs[i] ++;
    }
    sort(a + 1, a + 1001, cmp);

    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        printf("Case %d: %d\n", cas, a[n]);
    }
    return 0;
}
