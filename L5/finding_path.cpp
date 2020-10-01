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

vi get_path(int src, int dest)
{
	queue<int> q;
	vi dis(n + 1, -1);
	vi par(n + 1, -1);

	q.push(src);
	dis[src] = 0;

	while (!q.empty())
	{
		int i = q.front();
		q.pop();

		//cout << i << ' ';

		for (int nb : adj[i])
		{
			if (dis[nb] != -1)
				continue;

			q.push(nb);
			dis[nb] = dis[i] + 1;
			par[nb] = i;
		}
	}

	if (dis[dest] == -1)
		return {};

	vi path;

	int cur = dest;

	while (cur != -1)
		path.pb(cur), cur = par[cur];

	reverse(path.begin(), path.end());

	return path;
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

	int u, v; cin >> u >> v;

	vi path = get_path(u, v);

	for (int i : path)
		cout << i << ' ';

	cout << '\n';

	return 0;
}
