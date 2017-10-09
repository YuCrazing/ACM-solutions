#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int LIS[N], k;

int BS(int x) {
    if(LIS[k]<x) {
        LIS[++k]=x;
        return k;
    }
    int l=0, r=k;
    while(l<r) {
        int mid=(l+r)>>1;
        if(LIS[mid]>x) r=mid;
        else l=mid+1;
    }
    LIS[l]=x;
    return l;
}

void init() {
    LIS[0]=k=0;
}

int n, x;

int main() {
    while(scanf("%d", &n)!=EOF) {
        init();
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            BS(x);
        }
        printf("%d\n", k);
    }
    return 0;
}
