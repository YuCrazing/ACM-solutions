#include<bits/stdc++.h>
using namespace std;

/*
    ĸ����������Ż���
    ��ȫ������������
*/
const int N = 32768;
int f[N], n;

void init() {
    memset(f, 0, sizeof(f));
    for(int i = 0; i < N; i++) f[i] = i / 2 + 1;  // ���
    for(int num = 3; num <= 3; num++) {
        for(int i = N - 1; i >= 0; i--) {
            for(int j = num; j + i <= N - 1; j += num)
                f[i + j] += f[i];
        }
    }
}
int main() {

    init();

    while(scanf("%d", &n) != EOF) {

        printf("%d\n", f[n]);
    }
    return 0;
}
