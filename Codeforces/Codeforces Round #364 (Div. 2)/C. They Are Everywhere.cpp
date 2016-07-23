#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int INF = 0x3f3f3f3f;
int sum[N][60];
char s[N];
int kind(int l, int r){
    int res  = 0;
    for(int i = 0; i < 52; i ++) if(sum[r][i] - sum[l - 1][i] > 0) res ++;
    return res;
}
int find(int l, int r, int num){
    int s = l;
    while(l < r){
        int mid = (l + r) >> 1;
        if(kind(s, mid) >= num) r = mid;
        else l = mid + 1;
    }
    return l;
}
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < 52; j ++ ) sum[i][j] = sum[i - 1][j];
        if(s[i - 1] >= 'A' && s[i - 1] <= 'Z') sum[i][26 + s[i - 1] - 'A'] ++;
        else sum[i][s[i - 1] - 'a'] ++;
    }
    int tol = kind(1, n);

    int res = INF;
    for(int i = 1; i <= n; i ++){
        if(kind(i, n) < tol) continue;
        int pos = find(i, n, tol);

        res = min(res, pos - i + 1);
    }
    printf("%d\n", res);
    return 0;
}
