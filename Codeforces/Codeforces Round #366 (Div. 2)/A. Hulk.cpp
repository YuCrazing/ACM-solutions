#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string s;
int main(){
    int n;
    scanf("%d", &n);
    s.clear();
    for(int i = n;  i >= 1; i --){
        if(i == n) {
            if(i & 1) s += "I hate it";
            else s += "I love it";
        }else{
            if(i & 1) s = "I hate that " + s;
            else s = "I love that " + s;
        }
    }
    cout << s <<endl;
    return 0;
}
