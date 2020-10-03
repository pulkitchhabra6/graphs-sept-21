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
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


vector<vi> adj;

int32_t main()
{
	FIO;
	int n; cin >> n;
	adj.resize(n + 1);

	w(m)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	vi ans;

	set<int> can;
	vi vis(n + 1, 0);

	ans.pb(1);
	vis[1] = 1;

	while (ans.size() < n)
	{
		int i = ans.back();

		for (int nb : adj[i])
			if (!vis[nb])
				can.insert(nb);

		auto it = can.begin();

		ans.pb((*it));
		vis[(*it)] = 1;
		can.erase(it);
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	return 0;
}
