#include <bits/stdc++.h>
using namespace std;

void MaxHeapify(int * a, int root, int length) {
    int fa = root, son = root * 2 + 1;
    while(son < length) {
        if(son+1 < length && a[son] < a[son+1]) ++son;
        if(a[fa] < a[son]) swap(a[fa], a[son]);
        fa = son;
        son = fa * 2 + 1;
    }
}

void HeapSort(int * a, int length) {
    if(length <= 1) return;
    for(int i = length/2; i >= 0; --i)
        MaxHeapify(a, i, length);
    for(int i = length-1; i >= 0; --i) {
        swap(a[0], a[i]);
        MaxHeapify(a, 0, i);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int * a = new int[n];
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    HeapSort(a, n);
    for(int i = 0; i < n; ++i) printf(i==n-1?"%d\n":"%d ", a[i]);
    delete [] a;
    return 0;
}
