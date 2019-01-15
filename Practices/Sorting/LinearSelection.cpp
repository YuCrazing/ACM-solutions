#include <bits/stdc++.h>

using namespace std;

// return value is 0 based
int partition(int * a, int value, int n) {
    int pos = -1;
    for(int i = 0; i < n; ++i)
        if(a[i] == value) {
            pos = i;
            break;
        }
    swap(a[pos], a[n-1]);
    int i = -1, j;
    for(j = 0; j < n-1; ++j) {
        if(a[j] < value) {
            swap(a[++i], a[j]);
        }
    }
    swap(a[++i], a[n-1]);
    return i;
}

// assume all numbers are nonnegative
// select k-th small number
// k is 0 based
int LinearSelection(int * a, int k, int n) {

    if(k < 0 || k >= n) return -1;
    if(n <= 5) {
        sort(a, a+n);
        return a[k];
    }

    int m = (n+4)/5;
    int * medians = new int[m];
    for(int i = 0; i < n/5; ++i) {
        medians[i] = LinearSelection(a+i*5, 2, 5);
    }
    if(n%5) medians[m-1] = LinearSelection(a+n-n%5, n%5/2, n%5);

    int pivot = partition(a, LinearSelection(medians, m/2, m), n);
    delete [] medians;

    if(k == pivot) return a[pivot];
    else if(k < pivot) return LinearSelection(a, k, pivot);
    else return LinearSelection(a+pivot+1, k-pivot-1, n-pivot-1);
}

int main() {
    int N = 10000000;
    int K = rand();
    int * a = new int[N];
    for(int i = 0; i < N; ++i) a[i] = rand();
    int ans = LinearSelection(a, K, N);
    printf("%d\n", ans);
    delete [] a;
    return 0;
}
