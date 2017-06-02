//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 1e6 + 2;
//int a[N];
//int main() {
//    int n, m, x;
//    while(scanf("%d%d", &n, &m) != EOF) {
//        assert(n >= m);
//        for(int i = 0; i < n; i++)  scanf("%d", &a[i]);
//
//        sort(a, a + n);
//
//        for(int i = n - 1; i >= n - m; i--) printf((i == n - m) ? "%d\n" : "%d ", a[i]);
//    }
//
//    return 0;
//}

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;
bool a[N];
int main() {
    int n, m, x;
    while(scanf("%d%d", &n, &m) != EOF) {
        assert(n >= m);
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            a[x+500000] = 1;
        }

        for(int i = N - 1; i >= 0; i--) if(a[i]) {
                m--;
                printf(m ? "%d " : "%d\n", i - 500000);
                if(m <= 0) break;
            }
    }

    return 0;
}

