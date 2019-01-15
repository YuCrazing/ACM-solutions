// https://stackoverflow.com/questions/17270628/insertion-sort-vs-bubble-sort-algorithms

#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int * a, int length) {
    if(length <= 1) return;
    for(int time = 0; time < length-1; ++time) {
        for(int i = 0; i < length-1-time; ++i) {
            if(a[i] > a[i+1]) swap(a[i], a[i+1]);
        }
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
    BubbleSort(a, N);
    endTime = clock();

//    for(int i = 0; i < N; ++i) printf(i==N-1?"%d\n":"%d ", a[i]);
    printf("Sort time: %f\n", (double)(endTime-beginTime)/CLOCKS_PER_SEC);

    delete [] a;

    return 0;
}
