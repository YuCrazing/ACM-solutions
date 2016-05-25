#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cnt[55], num[55];
int _index[1011111];
int main(){
    int T, n, x;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d", &n);
        memset(_index, -1, sizeof(_index));
        memset(cnt, 0, sizeof(cnt));
        int id = 0;
        for(int i = 0; i < n; i ++){
            scanf("%d", &x);
            if(_index[x] == -1) {
                num[id] = x;
                _index[x] = id++;
            }
            cnt[_index[x]] ++;
        }
        int sum = 0;
        for(int i = 0; i < id; i ++)
            sum += (cnt[i] + num[i]) / (num[i] + 1) * (num[i] + 1);
        printf("Case %d: %d\n", cas, sum);
    }
    return 0;
}
