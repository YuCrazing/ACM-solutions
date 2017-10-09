#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
double a[4][4];
int x;
int main(){
    for(int i = 1;  i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            cin>>a[i][j];
    stringstream ss;
    string s;
    getline(cin, s);
    getline(cin, s);
    ss.str(s);
    double ans=1.0;
    int pre=-1;
    while(ss>>x){
        if(pre!=-1){
            ans*=a[pre][x];
            //cout<<pre<<"  "<<x<<endl;
        }
        pre=x;
    }
    printf("%.8f\n", ans);
    getline(cin, s);
    ss.clear();
    ss.str(s);
    pre=-1;
    ans=1.0;
    while(ss>>x){
        if(pre!=-1){
            ans*=a[pre][x];
        }
        pre=x;
    }
    printf("%.8f\n", ans);
    cin>>x;
    printf("%.8f\n", 1.0/(1-a[x][x]));
    cin>>x;
    printf("%.8f\n", 1.0/(1-a[x][x]));

    return 0;
}
