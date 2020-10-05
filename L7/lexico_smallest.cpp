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
vector<bool> vis;

void dfs(int i, int dest, stack<int> &s)
{
	vis[i] = true;
	//cout << i << ' ';
	s.push(i);

	//We have the path till i, in the stack
	if (i == dest)
	{
		vi v;
		while (!s.empty())
			v.pb(s.top()), s.pop();

		reverse(v.begin(), v.end());

		for (int cur : v)
			cout << cur << ' ';

		exit(0);
	}

	for (int j : adj[i])
		if (!vis[j])
			dfs(j, dest, s);

	s.pop();
}

int32_t main()
{
	FIO;
	int n, m; cin >> n >> m;

	int src, dest; cin >> src >> dest;

	adj.resize(n + 1);

	while (m--)
	{
		int i, j; cin >> i >> j;

		adj[i].pb(j);
		adj[j].pb(i);
	}

	for (int i = 1; i <= n; ++i)
		sort(adj[i].begin(), adj[i].end());

	vis.assign(n + 1, 0);

	stack<int> s;
	dfs(src, dest, s);

	cout << -1 << '\n';

	return 0;
}
