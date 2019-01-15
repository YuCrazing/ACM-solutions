// https://en.wikipedia.org/wiki/Introsort
// https://blog.csdn.net/insistGoGo/article/details/7785038
// https://www.sczyh30.com/posts/Algorithm/algorithm-quicksort/
//
// 最重要的是 1.进行 random_shuffle 和 2.防止递归深度过深，当深度太深时，使用另一种排序方法处理
// 使用其他排序方式时，使用插入排序可以通过，使用冒泡排序会超时
// 是否使用 median-of-3 策略区别不大

#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int * a, int length);
void InsertionSort(int * a, int length);
int pivot(int * a, int length);
void QuickSort(int * a, int length);

void BubbleSort(int * a, int length) {
    if(length <= 1) return;
    for(int time = 0; time < length-1; ++time) {
        for(int i = 0; i < length-1-time; ++i) {
            if(a[i] > a[i+1]) swap(a[i], a[i+1]);
        }
    }
}

void InsertionSort(int * a, int length) {
    if(length <= 1) return;
    for(int i = 1; i < length; ++i){
        for(int j = i-1; j >= 0; --j){
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
            else break;
        }
    }
}
// select the median of first, middle and last element.
int pivot(int * a, int length) {

//    int mid = length/2;
//
//    if((a[0] <= a[mid] && a[mid] <= a[length-1]) || (a[length-1] <= a[mid] && a[mid] <= a[0])) swap(a[length-1], a[mid]);
//    else if((a[mid] <= a[0] && a[0] <= a[length-1]) || (a[length-1] <= a[0] && a[0] <= a[mid])) swap(a[length-1], a[0]);

    int x = a[length-1], i = -1, j;
    for(j = 0; j < length-1; ++j){
        if(a[j] < x){
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap(a[i], a[length-1]);
    return i;
}

void QuickSort(int * a, int length, int depth) {

//    if(length <= 1) return;

    if(depth > 20){
//        BubbleSort(a, length);
        InsertionSort(a, length);
        return;
    }

    if(length <= 16) {
//        BubbleSort(a, length);
        InsertionSort(a, length);
        return ;
    }

    int p = pivot(a, length);
    QuickSort(a, p, depth+1);
    QuickSort(a+p+1, length-p-1, depth+1);
}

int main() {

    clock_t beginTime, endTime;
    int N;

    scanf("%d", &N);
    int * a = new int [N];
    for(int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    random_shuffle(a, a+N);

    beginTime = clock();
    QuickSort(a, N, 0);
    endTime = clock();

    for(int i = 0; i < N; ++i) printf(i==N-1?"%d\n":"%d ", a[i]);
    delete [] a;

//    printf("Sort time: %f\n", (double)(endTime-beginTime)/CLOCKS_PER_SEC);
    return 0;
}

