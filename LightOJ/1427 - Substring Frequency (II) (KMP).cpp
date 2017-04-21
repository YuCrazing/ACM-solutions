#include<bits/stdc++.h>
using namespace std;

/*
    Time Limit Exceeded.
*/

const int N = 505;
string text, word;
int next[N];

void initkmp() {
    next[1] = 0;
    int l = word.size(), j = 0;
    for(int i = 1; i < l; i++) {
        while(j && word[i] != word[j]) j = next[j];
        if(word[i] == word[j]) j++;
        next[i + 1] = j;
    }
}

int kmp() {
    initkmp();
    int l = text.size(), j = 0, sum = 0, lw = word.size();
    for(int i = 0; i < l; i++) {
        while(j && text[i] != word[j]) j = next[j];
        if(text[i] == word[j]) j++;
        if(j == lw) sum++;
    }
    return sum;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        cin >> n >> text;
        printf("Case %d:\n", ca);
        for(int i = 0; i < n; i++) {
            cin >> word;
            printf("%d\n", kmp());
        }
    }
    return 0;
}
