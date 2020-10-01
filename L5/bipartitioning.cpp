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
#define mod             1000000007
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
int n;

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

bool bfs(int src, vi &col)
{
	queue<int> q;
	q.push(src);

	col[src] = 0;

	while (!q.empty())
	{
		int tp = q.front();
		q.pop();

		for (int nb : adj[tp])
		{
			if (col[nb] == -1)
			{
				//if cur col is 1, col[nb]=0 else col[nb]=1
				col[nb] = 1 - col[tp];
				q.push(nb);
			}

			else if (col[nb] == col[tp])
				return 0;
		}
	}

	return 1;
}

int num_bipartitions()
{
	vi col(n + 1, -1);

	int cmp = 0;

	for (int i = 1; i <= n; ++i)
	{

		if (col[i] != -1)
			continue;

		bool poss = bfs(i, col);
		cmp++;

		if (!poss)
			return 0;
	}

	return pwmd(2, cmp);
}

int32_t main()
{
	FIO;

	int m; cin >> n >> m;
	adj.resize(n + 1);

	while (m--)
	{
		int i, j; cin >> i >> j;
		adj[i].pb(j);
		adj[j].pb(i);
	}

	cout << num_bipartitions();

	return 0;
}
