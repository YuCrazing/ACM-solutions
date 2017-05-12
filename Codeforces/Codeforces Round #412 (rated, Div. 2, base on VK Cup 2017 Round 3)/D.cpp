#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int a[120][5], num[5], n;

int gets(double rat){
    if(rat > 0.5) return 500;
    if(rat > 0.25) return 1000;
    if(rat > 1.0 / 8) return 1500;
    if(rat > 1.0 / 16) return 2000;
    if(rat > 1.0 / 32) return 2500;
    return 3000;
}

bool ok(int k){
    double rat;
    int s, sum = 0;
    for(int i = 0; i < 5; i++){
        if(a[0][i] == -1 && a[1][i] == -1) continue;
        else if(a[0][i] == -1) {
            rat = num[i] * 1.0 / (k + n);
            s = gets(rat);
            sum -= s / 250 * (250 - a[1][i]);
        }
        else if(a[1][i] == -1){
            rat = num[i] * 1.0 / (k + n);
            s = gets(rat);
            sum += s / 250 * (250 - a[0][i]);
            continue;
        }
        else if(a[0][i] > a[1][i]){
            rat = (k + num[i]) * 1.0 / (k + n);
            s = gets(rat);
            sum += s / 250 * (a[1][i] - a[0][i]);
        }else if(a[0][i] < a[1][i]){
            rat = num[i] * 1.0 / (k + n);
            s = gets(rat);
            sum += s / 250 * (a[1][i] - a[0][i]);
        }
//        printf("num[%d] = %d, rat = %f, s = %d, sum = %d\n",i, num[i], rat, s, sum);
    }
    if(sum > 0) return true;
    return false;
}

int BS() {
    for(int i = 0; i < 100000; i++){
        if(ok(i)) return i;
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < 5; j++){
        scanf("%d", &a[i][j]);
        if(a[i][j] != -1) num[j] ++;
    }

    printf("%d\n", BS());

    return 0;
}
