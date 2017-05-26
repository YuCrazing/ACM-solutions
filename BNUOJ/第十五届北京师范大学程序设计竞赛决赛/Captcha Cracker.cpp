#include<bits/stdc++.h>
using namespace std;

int T;
string s;
string word[6];

int num[5] = {
    0,
    2,
    4,
    6,
    9
};

int len[5] = {
    4,
    3,
    4,
    3,
    4
};

void init() {
    word[0] = "zero";
    word[1] = "two";
    word[2] = "four";
    word[3] = "six";
    word[4] = "nine";
}

int main() {

    init();

    scanf("%d", &T);
    while(T--) {
        cin >> s;
        string ans = "";
        int l = s.size();
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < 5; j++) {
                if(s[i] == num[j] + '0') {
                    ans += (num[j] + '0');
                    break;
                }
            }
            for(int j = 0; j < 5; j++) {
                if(i + len[j] > l) continue;
                if(s.substr(i, len[j]) == word[j]) {
                    ans += (num[j] + '0');
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
