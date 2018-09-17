/*
    奇数个负数并且有零时， 最大的负数跟所有的0乘起来就没有了。没有想到这一点。
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N];
int main() {
    int n, mxNeg=-1e9-7, zeroPos=-1, negPos = -1, posPos = -1, negNum=0, zeroNum=0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if(a[i] < 0) {
            negNum++;
            if(mxNeg < a[i]) {
                mxNeg=a[i];
                negPos = i;
            }
        } else if(a[i] == 0) {
            zeroPos = i;
            zeroNum++;
        } else if(a[i] > 0) posPos = i;
    }

    if(zeroNum==n ||(zeroNum==n-1 && negNum==1)) {
        for(int i = 2; i <= n; ++i) printf("1 %d 1\n", i);
    } else {
        if(negNum%2==1) {
            if(zeroPos==-1) {
                printf("2 %d\n", negPos);
                int dst = (negPos==1?2:1);
                for(int i = 1; i <= n; ++i) {
                    if(i!=negPos && i!=dst)
                        printf("1 %d %d\n", i, dst);
                }
            } else {
                a[negPos]=0;
                int dst = -1;
                for(int i = 1; i <= n; ++i) {
                    if(a[i]!=0) {
                        dst=i;
                        break;
                    }
                }
                a[zeroPos]=1;
                for(int i = 1; i <= n; ++i) {
                    if(a[i]==0) printf("1 %d %d\n", i, zeroPos);
                }
                printf("2 %d\n", zeroPos);
                for(int i = 1; i <= n; ++i) {
                    if(a[i]!=0 && i!=dst && i!=zeroPos) printf("1 %d %d\n", i, dst);
                }
            }
        } else {
            if(zeroPos!=-1) {
                int dst = -1;
                for(int i = 1; i <= n; ++i) {
                    if(a[i]!=0) {
                        dst=i;
                        break;
                    }
                }
                a[zeroPos]=1;
                for(int i = 1; i <= n; ++i) {
                    if(a[i]==0) printf("1 %d %d\n", i, zeroPos);
                }
                printf("2 %d\n", zeroPos);
                for(int i = 1; i <= n; ++i) {
                    if(a[i]!=0 && i!=dst && i!=zeroPos) printf("1 %d %d\n", i, dst);
                }
            } else {
                for(int i = 2; i <= n; ++i) {
                    printf("1 %d 1\n", i, 1);
                }
            }
        }
    }

    return 0;
}
