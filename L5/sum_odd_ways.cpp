//https://codeforces.com/contest/1093/problem/D

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
vector<vi> adj;
vector<int> col;
int c1, c2;
 
int bfs(int i)
{
	queue<int> q;
	q.push(i);
	col[i] = 1;
 
	while (!q.empty())
	{
		int tp = q.front();
		q.pop();
 
		col[tp] == 1 ? c1++ : c2++;
 
		for (int nb : adj[tp])
		{
			if (!col[nb])
				q.push(nb), col[nb] = 3 - col[tp];
 
			else if (col[nb] == col[tp])
				return 0;
		}
	}
 
	return 1;
}
 
int pwmd(int a, int n = mod - 2)
{
	if (!n)
		return 1;
	int pt = pwmd(a, n / 2);
	pt *= pt, pt %= mod;
	if (n & 1)
		pt *= a, pt %= mod;
	return pt;
}
 
int32_t main()
{
	FIO;
	w(t)
	{
		int n, m; cin >> n >> m;
		adj.assign(n + 1, {});
		col.assign(n + 1, 0);
 
		while (m--)
		{
			int i, j; cin >> i >> j;
			adj[i].pb(j);
			adj[j].pb(i);
		}
 
		int ans = 1;
 
		for (int i = 1; i <= n; ++i)
		{
			if (!col[i])
			{
				c1 = 0, c2 = 0;
				ans *= bfs(i);
				ans *= (pwmd(2, c1) + pwmd(2, c2));
				ans %= mod;
			}
 
			if (!ans)
				break;
		}
 
		cout << ans << '\n';
	}
	return 0;
}
