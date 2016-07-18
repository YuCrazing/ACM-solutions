//#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string s, c, d;
void add(string a, string b){
    c.clear();
    d.clear();

    int l1 = a.size();
    int l2 = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    d += '0';
    for(int i = 0; i < l2;  i++) {
        int t = a[i] - '0' + b[i] - '0' + d[i] - '0';
        if(t >= 10) d += '1';
        else d += '0';
        c += t % 10 + '0';
    }

    for(int i = l2; i < l1;  i++){
        int t = d[i] - '0' + a[i] - '0';
        if(t >= 10) d += '1';
        else d += '0';
        c += t % 10 + '0';
    }

    if(d[l1] == '1') {
        c += '1';
        for(int i = l1; i > -1; i --) cout << c[i];
    }
    else for(int i = l1 - 1; i > -1; i --) cout << c[i];
    cout << endl;
    return ;
}
string a ,b;
int cnt[10];
int main(){
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        for(int i = 0; i < 10; i ++) cnt[i] = 0;
        int l = s.size();
        if(l == 1) cout << "Uncertain" << endl;
        else{
            int minn = 10;
            for(int i = 0; i < l; i ++) {
                cnt[s[i] - '0'] ++;
                if(s[i] != '0') minn = min(minn, s[i] - '0');
            }

            if(cnt[0] == l - 1) {
                cout << "Uncertain" << endl;
                continue;
            }
            a.clear();
            b.clear();
            for(int i = 9; i > 0; i --) {
                if(minn == i){
                    for(int j = 0; j < cnt[i] - 1; j ++) a += i + '0';
                }else{
                    for(int j = 0; j < cnt[i]; j ++) a += i + '0';
                }
            }

            b += minn + '0';

            for(int i = 0; i < cnt[0]; i ++) a += '0';

            if(a.size() > b.size()) add(a,  b);
            else add(b, a);
        }
    }
    return 0;
}
