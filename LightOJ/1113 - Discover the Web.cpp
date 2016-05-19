#include <string>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int T;
string web, op, now;
stack<string> backs, forwards;

void init() {
    now = "http://www.lightoj.com/";
    while(!backs.empty()) backs.pop();
    while(!forwards.empty()) forwards.pop();
}

int main() {
    ios_base::sync_with_stdio(0);

    cin>>T;
    for(int cas = 1; cas <= T; cas ++) {
        cout << "Case " << cas << ":" << endl;
        init();
        while(cin >> op) {
            if(op == "VISIT") {
                cin >> web;
                backs.push(now);
                now = web;
                while(!forwards.empty()) forwards.pop();
                cout << now << endl;
            } else if(op == "BACK") {
                if(backs.empty()) {
                    cout << "Ignored" << endl;
                    continue;
                }
                forwards.push(now);
                now = backs.top();
                backs.pop();
                cout << now << endl;
            } else if(op == "FORWARD") {
                if(forwards.empty()) {
                    cout << "Ignored" << endl;
                    continue;
                }
                backs.push(now);
                now = forwards.top();
                forwards.pop();
                cout << now << endl;
            } else break;
        }
    }
    return 0;
}
