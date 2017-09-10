#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000010;

char buff[10];
//inline int read()
//{
//    int x=0;
//    scanf("%s",buff);
//    int len=strlen(buff);
//    for(int i=0;i<len;i++)x=x*10+buff[i]-'0';
//    return x;
//}
template <class T>
inline bool scan_d(T &ret) {
char c; int sgn;
if(c=getchar(),c==EOF) return 0; //EOF
while(c!='-'&&(c<'0'||c>'9')) c=getchar();
sgn=(c=='-')?-1:1;
ret=(c=='-')?0:(c-'0');
while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
ret*=sgn;
return 1;
}

int a[MAXN],b[MAXN];


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)scan_d(a[i]);
        for(int i=0;i<n;i++)scan_d(b[i]);
        int sum=0,res=0,flg=0;
        int mx=-1,mxi=-1;
        for(int i=0;i<n;i++)
        {
            if(sum<0)
            {
                sum-=a[i]-b[i];
                res-=a[i];
                continue;
            }
            while(1)
            {
                sum+=a[flg]-b[flg];
                res+=a[flg];
                flg=(flg+1)%n;
                if(flg==i)break;
                if(sum<0)break;
            }
            //printf("%d %d %d %d\n",i,sum,res,flg);
            if(res>mx){mx=res;mxi=i;}
            sum-=a[i]-b[i];
            res-=a[i];
        }
        printf("%d\n",mxi);
    }
    return 0;
}
