#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char genChar(){
    return 'a' + rand() % 26;
}

void genData(int n){
    srand(time(NULL));
    for(int i = 1; i <= n; i++){
        printf("%c%c%c%c%d\n", genChar(), genChar(), genChar(), genChar(), rand());
    }
}

char s[100];
int x;

int main(){

#ifdef YU
    freopen("in.in", "r", stdin);
#endif // YU

    int N = 10;

//    genData(N);

    for(int i = 0; i < N; i++){
        scanf("%4s%d", s, &x); // read first 4 characters as string.
        printf("%s %d\n", s, x);
    }


    return 0;
}
