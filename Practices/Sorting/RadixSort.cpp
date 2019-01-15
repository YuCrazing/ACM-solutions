// "radix" is a synonym of "base"
// https://en.wikipedia.org/wiki/Radix

// RadixSort vs QuickSort:
// https://www.geeksforgeeks.org/radix-sort/
// https://stackoverflow.com/questions/3539265/why-quicksort-is-more-popular-than-radix-sort
// 对于洛谷1177，RadixSort 速度最快

#include <bits/stdc++.h>
using namespace std;

// assume all numbers are nonnegative.
void RadixSort(int * a, int length) {

    if(length <= 1) return;

    int radix = 40000;

    int mx = a[0], dn=0;
    for(int i = 1; i < length; ++i) mx = max(mx, a[i]);
    while(mx) {
        ++dn;
        mx /= radix;
    }

    int * count = new int[radix];
    int * temp = new int[length];

    int divisor = 1;
    for(int d = 0; d < dn; ++d) {
        for(int i = 0; i < radix; ++i) count[i] = 0;
        for(int i = 0; i < length; ++i) {
            int num = a[i]/divisor%radix;
            count[num]++;
        }
        for(int i = 1; i < radix; ++i) count[i] += count[i-1];
        for(int i = length-1; i >= 0; --i) {
            int num = a[i]/divisor%radix;
            temp[--count[num]] = a[i];
        }
        for(int i = 0; i < length; ++i) a[i] = temp[i];
        divisor *= radix;
    }

    delete [] count;
    delete [] temp;

}


int main() {

    clock_t beginTime, endTime;

    int N=100000;
    int * a = new int [N];
    for(int i = 0; i < N; ++i) {
        a[i]=rand();
    }

    beginTime = clock();
    RadixSort(a, N);
    endTime = clock();

//    for(int i = 0; i < N; ++i) printf(i==N-1?"%d\n":"%d ", a[i]);
    printf("Sort time: %f\n", (double)(endTime-beginTime)/CLOCKS_PER_SEC);

    delete [] a;

    return 0;
}
