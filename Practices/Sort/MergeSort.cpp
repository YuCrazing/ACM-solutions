#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int temp[MAXN];

void MergeSort(int * a, int length) {

    if(length <= 1) return;

    int mid = length/2;
    MergeSort(a, mid);
    MergeSort(a+mid, length-mid);

    int i = 0, j = mid, n = 0;
    while(i < mid && j < length) {
        if(a[i] <= a[j]) temp[n++]=a[i++];
        else temp[n++]=a[j++];
    }
    while(i < mid) temp[n++]=a[i++];
    while(j < length) temp[n++]=a[j++];
    for(i = 0; i < length; ++i) a[i]=temp[i];
}

int main() {

    clock_t beginTime, endTime;

    int N=100000;
    int * a = new int [N];
    for(int i = 0; i < N; ++i) {
        a[i]=rand();
    }

    beginTime = clock();
    MergeSort(a, N);
    endTime = clock();

//    for(int i = 0; i < N; ++i) printf(i==N-1?"%d\n":"%d ", a[i]);
    printf("Sort time: %f\n", (double)(endTime-beginTime)/CLOCKS_PER_SEC);

    delete [] a;

    return 0;
}
