#include<bits/stdc++.h>
using namespace std;


const int N = 5e4;
const int M = 2e4;
const int I = 200;

char genChar(){
    int k = rand()%26;
    return 'a'+k;
}

char s[N];

int main(){

    freopen("in2.in", "w", stdout);

    srand(time(NULL));

    for(int i = 0; i < N; i++) s[i] = 'b';
    printf("%s\n", s);
    printf("%d\n", M);

    for(int i = 0; i < M; i++){
        if(i < I) printf("I %c %d\n", genChar(), rand()%N + 1);
        else printf("Q %d %d\n", rand()%N + 1, rand()%N + 1);
    }
}
