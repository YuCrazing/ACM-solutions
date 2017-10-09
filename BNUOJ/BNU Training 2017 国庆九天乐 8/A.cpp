#include<bits/stdc++.h>
using namespace std;


const int N=2e5+5;
double avg[N];
int tol=0;
int n, x, num[N];

void push(int x){
    if(tol==0){
        avg[++tol]=x;
        num[tol]=1;
    }
    else{
        if(avg[tol]==x){
            num[tol]++;
        }
        else{
            avg[++tol]=x;
            num[tol]=1;
            while(tol>1&&avg[tol]<avg[tol-1]){
                double las=avg[tol];
                int ct=num[tol];
                tol--;
                avg[tol]=(avg[tol]*num[tol]+las*ct)/(num[tol]+ct);
                num[tol]+=ct;
            }
        }
    }
}
int main(){
    freopen("approximation.in", "r", stdin);
    freopen("approximation.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        push(x);
    }
    for(int i = 1; i <= tol; i++){
        int j=num[i];
        while(j--){
            printf("%.10f ", avg[i]);
        }
    }
    puts("");
}
/*
    6
    6 5 4 5 4 3
*/
