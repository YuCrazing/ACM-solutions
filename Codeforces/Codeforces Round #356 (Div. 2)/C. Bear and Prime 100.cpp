#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100];
bool isp[111];
int prime[111];
int num = 0;
int main() {
    for(int i = 0; i < 101; i ++) isp[i] = 1;
    for(int i = 2; i < 101; i ++) {
        if(isp[i]) {
            prime[num ++] = i;
            //printf("%d %d\n",num,i);
            for(int j = 2; i * j <= 100; j ++) isp[i*j] = 0;
        }
    }


    bool com = false;
    int t = 20;
    for(int i = 0; i < 20; i ++) {
        t --;
        printf("%d\n", prime[i]);
        fflush(stdout);

        scanf("%s", s);
        if(strcmp("yes", s) == 0) {
            int sq = prime[i] * prime[i];
            if(sq <= 100) {
                t --;
                printf("%d\n", sq);
                fflush(stdout);

                scanf("%s", s);
                if(strcmp("yes", s) == 0) {
                    com = true;
                    break;
                }
                if(t == 0) break;
            }
            bool two = false;
            for(int j = 0 ; j < 20; j ++) {
                if(i != j) {
                    t--;
                    printf("%d\n", prime[j]);
                    fflush(stdout);

                    scanf("%s", s);
                    if(strcmp("yes", s) == 0) {
                        two = true;
                        break;
                    }
                    if(t == 0) break;
                }
            }
            if(two) {
                com = true;
                break;
            }
        }
        if(t == 0) break;
    }

    if(com) printf("composite\n");
    else printf("prime\n");
    fflush(stdout);

    return 0;
}
