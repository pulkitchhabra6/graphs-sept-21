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

vi adj[100001];
bool vis[100001] = {};

int dfs(int cur)
{
	int num_of_nodes = 1;
	vis[cur] = 1;

	for (int ch : adj[cur])
	{
		if (vis[ch])
			continue;

		num_of_nodes += dfs(ch);
	}

	return num_of_nodes;
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
	int n, k; cin >> n >> k;

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v, col; cin >> u >> v >> col; //0->blue, 1->red

		if (col == 1)
			continue;

		adj[u].pb(v);
		adj[v].pb(u);
	}

	int ans = pwmd(n, k);

	for (int i = 1; i <= n; ++i)
	{
		if (vis[i])
			continue;

		int num = dfs(i);

		ans -= pwmd(num, k);

		//will understand in modular arithmetic class
		ans = (ans + mod) % mod;
	}

	cout << ans << '\n';
	return 0;
}
