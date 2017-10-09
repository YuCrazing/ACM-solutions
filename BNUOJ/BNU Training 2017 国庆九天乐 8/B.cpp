#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#define N 2010
#define LL long long
#define M 20010
#define INF (int)1e9


using namespace std;
struct ALIS
{
	int n , e , l;

}alis[M];

vector <int> ans;
int fir[N] , tot , s , t , dep[N] , v[N] , n;
int a[40][40];
char stem[10001];

string Name[40];
void add(int u , int v , int l)
{
	alis[++ tot].n = fir[u];
	fir[u] = tot;
	alis[tot].e = v;
	alis[tot].l = l;
}
int DFS(int x , int maxn)
{
	if(x == t)return maxn;

	int ret = 0;

	for(int u = fir[x];u;u = alis[u].n)
	{
		if(dep[alis[u].e] == dep[x] + 1 && alis[u].l)
		{
			int tem = DFS(alis[u].e , min(maxn , alis[u].l));
			ret += tem;
			maxn -= tem;
			alis[u].l -= tem;
			alis[u ^ 1].l += tem;
		}
	}
	if(ret == 0)dep[x] = -1;
	return ret;
}
bool BFS()
{
	memset(dep , 0 , sizeof(dep));
	int head = 0 , tail = 0;
	int q[N];
	q[tail ++] = s;
	dep[s] = 1;
	while(head ^ tail)
	{
		int x = q[head];
		for(int u = fir[x];u;u = alis[u].n)if(alis[u].l && !dep[alis[u].e])
		{
			dep[alis[u].e] = dep[x] + 1;
			q[tail ++] = alis[u].e;
		}
		head ++;
	}
	return dep[t] > 0;

}
int Dinic()
{
	int ret = 0;
	while(BFS())ret += DFS(s , INF);
	return ret;
}
void Ans()
{
	int head = 0 , tail = 0;
	int q[N];
	q[tail ++] = t;
	while(head ^ tail)
	{
		int x = q[head];
		if(x >= 1 && x <= n)ans.push_back(x);
		for(int u = fir[x];u;u = alis[u].n)
		{
			if(alis[u ^ 1].l != 0 && dep[alis[u].e] == dep[x] - 1)
			{
				q[tail ++] = alis[u].e;
			}
		}
		head ++;
	}
}
bool solve(int boss)
{
	int x = v[boss];
	int sum = 0;

	ans.clear();
	memset(fir , 0 , sizeof(fir));
	s = 0 , t = n * n + n + 1;
	tot = 1;

	for(int i = 1;i <= n;i ++)if(i != boss)x += a[i][boss];

	for(int i = 1;i <= n;i ++)if(i != boss)
	{
		if(v[i] - x > 0)
		{
			ans.push_back(i);
			return 0;
		}
		if(x == v[i])continue;
		//add(s , i , x - v[i]);
		//add(i , s , 0);

		add(i, t, x-v[i]);
		add(t, i, 0)
	}

	for(int i = 1;i <= n;i ++)if(i != boss)
		for(int j = i + 1;j <= n;j ++)if(j != boss)
		{
			if(a[i][j] == 0)continue;
			//add((i - 1) * n + j + n , t , a[i][j]);
			//add(t , (i - 1) * n + j + n , 0);

			add(s, (i - 1) * n + j + n, a[i][j]);
			add((i - 1) * n + j + n, s, 0);

			//add(i , (i - 1) * n + j + n , INF);
			//add((i - 1) * n + j + n , i , 0);

			add((i - 1) * n + j + n, i, INF);
			add(i, (i - 1) * n + j + n, 0);

			//add(j , (i - 1) * n + j + n , INF);
			//add((i - 1) * n + j + n , j , 0);

			add((i - 1) * n + j + n, j, INF);
			add(j, (i - 1) * n + j + n, 0);

			sum += a[i][j];
		}
	if(sum - Dinic() <= 0)return 1;
	Ans();

//	for(int u = fir[s];u;u = alis[u].n)
//	{
//		if(!alis[u].l)
//		{
//			ans.push_back(alis[u].e);
//		}
//	}
	return 0;
}
int main ()
{
	freopen("high.in","r",stdin);
	freopen("high.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%s",stem);
		Name[i] += stem;
		scanf("%d",&v[i]);
	}
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
			scanf("%d",&a[i][j]);

	for(int i = 1;i <= n;i ++)
	{
		if(solve(i))cout << Name[i] << " can win" << endl;
		else
		{
			cout << Name[i] << " cannot win because of the following teams:" << endl;
			cout << "  " ;
			for(int j = (int)ans.size() - 1;j > 0;j --)
				cout << Name[ans[j]] << ", ";
			cout << Name[ans[0]] << endl;
		}
	}
	return 0;
}
