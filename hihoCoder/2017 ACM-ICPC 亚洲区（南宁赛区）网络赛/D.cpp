#include<bits/stdc++.h>
using namespace std;

const int N=30;
pair<int, int> fa[N][N];
double dp[N][N], a, b;
int c[N][N], I=0, J=0;
int main(){
    fa[1][1]=pair<int, int>(0, 0);
    cin>>a>>b;
    stringstream ss;
    string s;
    getline(cin, s);
    while(!cin.eof()){
        getline(cin, s);
        if(!s.size()) break;
        ss.clear();
        ss.str(s);
        //cout<<"      " <<s.size()<<endl;
        J++;
        I=1;
        while(ss>>c[I][J]) {
            I++;
        }
    }
    I--;
//    printf("%d %d\n", I, J);
//    for(int i = 1; i <= I; i++){
//        for(int j = 1; j <= J; j++){
//            printf(j==J?"%d\n":"%d ", c[i][j]);
//        }
//    }
    for(int i = 0; i <= I; i++)
        for(int j = 0; j <= J; j++)
            dp[i][j]=1e10;
    dp[1][1]=c[1][1];
    for(int i = 1; i <= I; i++){
        for(int j = 1; j <= J; j++){
            if(i-2>=1&&j-1>=1){
                double t=dp[i-2][j-1]+a*(c[i-1][j]+c[i][j]);
                if(dp[i][j]>t){
                    dp[i][j]=t;
                    fa[i][j]=pair<int, int>(i-2, j-1);
                }
            }
            if(i-1>=1&&j-1>=1){
                double t=dp[i-1][j-1]+b*c[i][j];
                if(dp[i][j]>t){
                    dp[i][j]=t;
                    fa[i][j]=pair<int, int>(i-1, j-1);
                }
            }
            if(i-1>=1&&j-2>=1){
                double t=dp[i-1][j-2]+a*(c[i][j-1]+c[i][j]);
                if(dp[i][j]>t){
                    dp[i][j]=t;
                    fa[i][j]=pair<int, int>(i-1, j-2);
                }
            }
        }
    }
//    for(int i = 1; i <= I; i++)
//        for(int j = 1; j <= J; j++)
//            printf(j==J?"%10.3f\n":"%10.3f ", dp[i][j]);
    pair<int, int> t(I, J);
    stack<pair<int, int> >st;
    while(t.first!=0){
        st.push(t);
        int x=t.first;
        int y=t.second;
        if(t.first-fa[x][y].first==2){
            st.push(pair<int, int> (t.first-1, t.second));
        }else if(t.second-fa[x][y].second==2){
            st.push(pair<int, int> (t.first, t.second-1));
        }
        t=fa[x][y];
    }

    printf("%.6f\n", dp[I][J]);
    while(!st.empty()){
        printf("(%d,%d)\n",st.top().first, st.top().second);
        st.pop();
    }
    return 0;
}
