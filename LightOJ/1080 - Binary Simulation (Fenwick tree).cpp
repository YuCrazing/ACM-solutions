#include <cstdio>
#include <cstring>
using namespace std;


const int MAXN = 1e5 + 3;
int c[MAXN];
int lowbit(int x) {
    return x&(-x);
}

void add(int a) {
    for(int i = a; i < MAXN; i += lowbit(i)) {
        c[i] ^= 1;
    }
}

int query(int a) {
    int res = 0;
    for(int i = a; i > 0; i -= lowbit(i)) {
        res ^= c[i];
    }
    return res;
}

char s[MAXN], op[10];

int main() {
    int T, q, a, b;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        memset(c, 0, sizeof(c));
        scanf("%s%d", s, &q);
        printf("Case %d:\n", cas);
        for(int i = 0; i < q; i ++) {
            scanf("%s", op);
            if(!strcmp(op, "I")) {
                scanf("%d%d", &a, &b);
                add(a);
                add(b + 1);
            } else {
                scanf("%d", &a);
                printf("%d\n", (s[a - 1] - '0') ^ query(a));
            }
        }
    }
    return 0;
}
