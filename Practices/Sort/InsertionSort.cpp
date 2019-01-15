#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int * a, int length) {
    if(length <= 1) return;
    for(int i = 1; i < length; ++i) {
        for(int j = i-1; j >= 0; --j) {
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
            else break;
        }
    }
}

// swap() is unnecessary, a faster version without swap()
// https://en.wikipedia.org/wiki/Insertion_sort
void InsertionSort_faster(int * a, int length) {
    if(length <= 1) return;
    int i, j, x;
    for(i = 1; i < length; ++i) {
        x = a[i];
        for(j = i-1; j >= 0; --j) {
            if(a[j] > x) a[j+1]=a[j];
            else break;
        }
        a[j+1]=x;
    }
}

int main() {

    clock_t beginTime, endTime;

    int N=50000;
    int * a = new int [N];
    for(int i = 0; i < N; ++i) {
        a[i]=rand();
    }

    beginTime = clock();
    InsertionSort(a, N);
//    InsertionSort_faster(a, N);
    endTime = clock();

//    for(int i = 0; i < N; ++i) printf(i==N-1?"%d\n":"%d ", a[i]);
    printf("Sort time: %f\n", (double)(endTime-beginTime)/CLOCKS_PER_SEC);

    delete [] a;

    return 0;
}
