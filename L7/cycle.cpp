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
vector<int> vis;

bool dfs(int i, int par)
{
	if (vis[i])
		return 1;

	vis[i] = true;
	bool cycle_found = 0;

	for (int nb : adj[i])
		if (nb != par)
			cycle_found |= dfs(nb, i);

	return cycle_found;
}

bool detect_cycle(int n)
{
	vis.assign(n + 1, 0);

	bool cycle_found = 0;

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			cycle_found |= dfs(i, -1);

	return cycle_found;
}

vi par;
int cyc_end, cyc_st;

bool dfs1(int i)
{
	vis[i] = 1;
	for (int nb : adj[i])
	{
		if (nb == par[i])
			continue;

		if (!vis[nb])
		{
			par[nb] = i;
			bool cf = dfs1(nb);

			if (cf)
				return true;
		}

		else
		{
			cyc_end = i;
			cyc_st = nb;
			return true;
		}
	}

	return false;
}

vector<int> get_cycle(int n)
{
	par.assign(n + 1, -1);
	vis.assign(n + 1, false);

	for (int i = 1; i <= n; ++i)
		if (vis[i] == 0)
		{
			if (dfs1(i))
			{
				//return the cycle
				vector<int> v;

				while (cyc_end != cyc_st)
					v.pb(cyc_end), cyc_end = par[cyc_end];

				v.pb(cyc_st);

				return v;
			}
		}

	return {};
}

int32_t main()
{
	FIO;
	int n, m; cin >> n >> m;
	adj.resize(n + 1);

	while (m--)
	{
		int i, j; cin >> i >> j;

		adj[i].pb(j);
		adj[j].pb(i);
	}

	vi v = get_cycle(n);

	for (int i : v)
		cout << i << ' ';

	return 0;
}
