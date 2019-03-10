#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h;
    int w1, h1;
    int w2, h2;
    cin >> w >> h;
    cin >> w1 >> h1;
    cin >> w2 >> h2;
    for(int i = h; i >= 0; --i) {
        w += i;
        if(i == h1) {
            w -= w1;

        } else if(i == h2) {
            w -= w2;
        }
        w = max(0, w);
    }
    cout << w << endl;

    return 0;
}
