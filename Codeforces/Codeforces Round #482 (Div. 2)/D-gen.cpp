#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.in", "w", stdout);
    srand(time(0));
    int q=100;
    printf("%d\n", q);
    for(int i = 0; i < q; ++i){
        int op = rand()%2 + 1;
        if(op==1){
            printf("%d %d\n", op, rand()%100000 + 1);
        }
        else{
            int k = rand()%10 + 1;
            int s = rand()%100000 + 1;
            int x = rand()%s + 1;
            printf("%d %d %d %d\n", op, x, k, s);
        }
    }
    return 0;
}
