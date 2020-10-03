#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int l[1001], r[1001], v[1001];
vector<int> adj[1001];
int dir[1001];
int can = 1;

void dfs(int node)
{
	for (auto el : adj[node])
	{
		int req = (1 + 2) - dir[node];

		if (dir[el] != 0)
		{
			if (dir[el] == req)
				continue;

			else
			{
				can = 0;
				return;
			}
		}

		else
		{
			dir[el] = req;
			dfs(el);
		}
	}
}

bool common(int i, int j)
{

	int lv = max(l[i], l[j]);
	int rv = min(r[i], r[j]);

	return (lv <= rv);
}

int32_t main()
{
	c_p_c();
	int t; cin >> t;

	while (t--)
	{
		int n; cin >> n;

		for (int i = 1; i <= n; ++i)
			cin >> l[i] >> r[i] >> v[i];

		for (int i = 1; i <= n; ++i)
			adj[i].clear();

		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
			{
				if (v[i] == v[j] && common(i, j))
					adj[i].pb(j), adj[j].pb(i);
			}

		//We have our graph
		memset(dir, 0, sizeof(dir));
		can = 1;

		for (int i = 1; i <= n; ++i)
		{
			if (dir[i])
				continue;

			dir[i] = 1;

			dfs(i);
		}

		if (can == 1)
			cout << "YES\n";

		else
			cout << "NO\n";

	}
	return 0;
}
