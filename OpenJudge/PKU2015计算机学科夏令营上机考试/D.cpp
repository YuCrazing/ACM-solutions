#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct People{
    int sex;
    double h;
    bool operator<(const People b)const{
        if(sex == b.sex) {
            if(sex) return h > b.h;
            else return h < b.h;
        }
        return sex < b.sex;
    }
}p[50];
char s[10];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n;  i++) {
        scanf("%s%lf", s, &p[i].h);
        if(!strcmp(s, "male")) p[i].sex = 0;
        else  p[i].sex = 1;
    }
    sort(p, p + n);
    for(int i = 0; i < n; i ++) printf((i == n - 1) ? "%.2f\n" : "%.2f ", p[i].h);

    return 0;
}
