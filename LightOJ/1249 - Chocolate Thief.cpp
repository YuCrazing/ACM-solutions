#include <iostream>
#include <string>
using namespace std;

int main(){
    int T, n, a, b, c;
    cin >> T;
    for(int ca = 1; ca <= T; ca++){
        cin >> n;

        int maxx = 0, maxNum = 0, minn = 1e7;
        string name, thief, poorguy;
        for(int i = 0; i < n; i++){
            cin >> name >> a >> b >> c;
            int vol = a * b * c;
            if(vol > maxx){
                maxx = vol;
                maxNum = 1;
                thief = name;
            }else if (vol == maxx) maxNum ++;

            if(vol < minn){
                minn = vol;
                poorguy = name;
            }else if(vol == minn) poorguy = "all";
        }
        cout << "Case " << ca << ": ";
        if(maxNum > 1) cout << "no thief" << endl;
        else cout << thief << " took chocolate from " << poorguy << endl;
    }
    return 0;
}
