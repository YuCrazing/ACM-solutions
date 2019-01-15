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

void MaxHeapify_recursion(int * a, int root, int length) {
    int fa = root, son = root * 2 + 1;
    if(son >= length) return;
    if(son+1 < length && a[son] < a[son+1]) ++son;
    if(a[fa] >= a[son]) return;
    swap(a[fa], a[son]);
    MaxHeapify_recursion(a, son, length);
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

    clock_t beginTime, endTime;

    int N=100000;
    int * a = new int [N];
    for(int i = 0; i < N; ++i) {
        a[i]=rand();
    }

    beginTime = clock();
    HeapSort(a, N);
    endTime = clock();

//    for(int i = 0; i < N; ++i) printf(i==N-1?"%d\n":"%d ", a[i]);
    printf("Sort time: %f\n", (double)(endTime-beginTime)/CLOCKS_PER_SEC);

    delete [] a;

    return 0;
}
