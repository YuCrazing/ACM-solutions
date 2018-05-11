#include<bits/stdc++.h>
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

string s;
int main(){
    cin>>s;
    int a, b;
    a=b=0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i]=='o') ++a;
        else ++b;
    }
    if(a==0 || b%a==0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
