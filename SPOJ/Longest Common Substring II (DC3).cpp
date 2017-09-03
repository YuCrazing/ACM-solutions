#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int L = 1e5+4;
const int N = 10;
const int MAXN = N*L;
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int ra[MAXN*3], sa[MAXN*3], height[MAXN*3], len[N], sum[N];
int wa[MAXN*3],wb[MAXN*3],wv[MAXN*3],wss[MAXN*3];
int c0(int *r,int a,int b) {
    return r[a] == r[b] && r[a+1] == r[b+1] && r[a+2] == r[b+2];
}
int c12(int k,int *r,int a,int b) {
    if(k == 2)
        return r[a] < r[b] || ( r[a] == r[b] && c12(1,r,a+1,b+1) );
    else return r[a] < r[b] || ( r[a] == r[b] && wv[a+1] < wv[b+1] );
}
void sort(int *r,int *a,int *b,int n,int m) {
    int i;
    for(i = 0; i < n; i++)wv[i] = r[a[i]];
    for(i = 0; i < m; i++)wss[i] = 0;
    for(i = 0; i < n; i++)wss[wv[i]]++;
    for(i = 1; i < m; i++)wss[i] += wss[i-1];
    for(i = n-1; i >= 0; i--)
        b[--wss[wv[i]]] = a[i];
}
void dc3(int *r,int *sa,int n,int m) {
    int i, j, *rn = r + n;
    int *san = sa + n, ta = 0, tb = (n+1)/3, tbc = 0, p;
    r[n] = r[n+1] = 0;
    for(i = 0; i < n; i++)if(i %3 != 0)wa[tbc++] = i;
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    for(p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i])] = c0(r, wb[i-1], wb[i]) ? p - 1 : p++;
    if(p < tbc)dc3(rn,san,tbc,p);
    else for(i = 0; i < tbc; i++)san[rn[i]] = i;
    for(i = 0; i < tbc; i++) if(san[i] < tb)wb[ta++] = san[i] * 3;
    if(n % 3 == 1)wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);

    for(i = 0; i < tbc; i++)wv[wb[i] = G(san[i])] = i;
    for(i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for(; i < ta; p++)sa[p] = wa[i++];
    for(; j < tbc; p++)sa[p] = wb[j++];
}
//str和sa也要三倍
void da(int str[],int sa[],int rank[],int height[],int n,int m) {
    for(int i = n; i < n*3; i++)
        str[i] = 0;
    dc3(str, sa, n+1, m);
    int i,j,k = 0;
    for(i = 0; i <= n; i++)rank[sa[i]] = i;
    for(i = 0; i < n; i++) {
        if(k) k--;
        j = sa[rank[i]-1];
        while(str[i+k] == str[j+k]) k++;
        height[rank[i]] = k;
    }
}

int l, minn, n, tol;
bool vis[N];

void mk(int x) {
    for(int i = 0; i < n; i++) {
        if(sa[x] < sum[i]) {
            vis[i] = 1;
            return;
        }
    }
}

bool ok(int x) {
    if(!x) return true;

    int i = 2;
    bool fi;
    while(i <= l) {
        fi = true;
        while(height[i] >= x && i <= l) {
            if(fi) {
                memset(vis, 0, sizeof(vis));
                mk(i - 1);
                mk(i);
                fi = false;
            } else mk(i);
            i++;
        }
        if(!fi) {
            int cnt = 0;
            for(int j = 0; j < n; j++) if(vis[j]) {
                    cnt++;
                }
            if(cnt >= n) {
                return true;
            }
            fi = true;
        }
        i++;
    }

    return false;
}

int BS() {
    int l = 0, r = minn;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(ok(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

char s[N][L];
int t[MAXN*3];

int main() {
    //freopen("in.in", "r", stdin);
    while(scanf("%s", s[n++]) != EOF);
    if(s[n-1][0]==0) n--;
    l = tol = 0;
    minn = L;
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < n; i++) {
        len[i] = strlen(s[i]);
        for(int j = 0; j < len[i]; j++) t[j + l] = s[i][j] + 101;
        minn = min(minn, len[i]);
        l += len[i];
        sum[i] = l;
        t[l++] = n-1-i;
    }
    l--;
    if(n == 1) {
        printf("%d\n", len[0]);
    } else {
        da(t, sa, ra, height, l, 400);
        printf("%d\n", BS());
    }

    return 0;
}
