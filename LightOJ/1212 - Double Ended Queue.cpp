#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int T, n, m, x;
string op;
deque<int> deq;
int main() {
    cin >> T;
    for(int ca = 1; ca <= T; ca ++) {
        deq.clear();
        cin >> n >> m;
        cout << "Case " << ca << ":" << endl;
        while(m --) {
            cin >> op;
            if(op == "pushLeft" || op == "pushRight") {
                cin >> x;
                if(deq.size() >= n) {
                    cout << "The queue is full" << endl;
                } else {
                    if(op == "pushLeft") {
                        deq.push_front(x);
                        cout << "Pushed in left: " << x << endl;
                    } else {
                        deq.push_back(x);
                        cout << "Pushed in right: " << x << endl;
                    }
                }
            } else if(op == "popLeft" || op == "popRight") {
                if(deq.empty()) {
                    cout << "The queue is empty" << endl;
                } else {
                    if(op == "popLeft") {
                        cout << "Popped from left: " << deq.front() << endl;
                        deq.pop_front();
                    } else {
                        cout << "Popped from right: " << deq.back() << endl;
                        deq.pop_back();
                    }
                }
            }
        }
    }
    return 0;
}
