#include<bits/stdc++.h>
using namespace std;

int getNum(char x) {
    if(x >= 'A' && x <= 'Z') return x - 'A';
    if(x >= 'a' && x <= 'z') return x - 'a' + 26;
    if(x >= '0' && x <= '9') return x - '0' + 52;

    if(x == '=') return 0;
    if(x == '+') return 62;
    if(x == '/') return 63;
}

string d2b(int x) {
    string s = "";
    for(int i = 0; i < 6; i++)
        if((1<<i) & x) {
            s += '1';
        } else {
            s += '0';
        }

    reverse(s.begin(), s.end());
    return s;
}

int b2d(string s) {
    int x = 0;
    int l = s.size();
    assert(l == 8);
    for(int i = 0; i < l; i++) {
        x <<= 1;
        if(s[i] == '1') {
            x += 1;
        }
    }
    return x;
}

void decode(string s) {

    string bin = "";

    int l = s.size(), zeros = 0;
    for(int i = 0; i < l; i++) {
        bin += d2b(getNum(s[i]));
    }

    l = bin.size();
    assert(l % 8 == 0);

    string origin = "";
    for(int i = 0; i < l; i += 8) {
        char ch = (b2d(bin.substr(i, 8)) + '\0'); // substr(pos, len)
        if(ch == '\0') continue;
        origin += ch;
    }

    printf("%s\n", origin.c_str());
}

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> s) {
        decode(s);
    }
    return 0;
}
