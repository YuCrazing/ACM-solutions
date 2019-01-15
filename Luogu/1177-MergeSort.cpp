#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int temp[N];

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
    int n;
    scanf("%d", &n);
    int * a = new int[n];
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    MergeSort(a, n);
    for(int i = 0; i < n; ++i) printf(i==n-1?"%d\n":"%d ", a[i]);
    delete [] a;
    return 0;
}
