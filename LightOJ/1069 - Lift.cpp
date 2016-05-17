#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int T, posA, posB;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &posA, &posB);
        printf("Case %d: %d\n", cas, 3*3 + 2*5 + 4*(int)(abs(posA - posB) + abs(posA)));
    }
    return 0;
}
