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
    int n;
    scanf("%d", &n);
    int * a = new int[n];
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    RadixSort(a, n);
    for(int i = 0; i < n; ++i) printf(i==n-1?"%d\n":"%d ", a[i]);
    delete [] a;
    return 0;
}
