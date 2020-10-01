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

vector<vector<pii> > adj;
int n;

//0 -> red
//1 -> green

vi bfs(int src, int col)
{
	queue<int> q;
	vi dis(n + 1, -1);

	q.push(src);
	dis[src] = 0;

	while (!q.empty())
	{
		int i = q.front();
		q.pop();

		//cout << i << ' ';

		for (pii nb : adj[i])
		{
			if (dis[nb.ff] != -1 or nb.ss != col)
				continue;

			q.push(nb.ff);
			dis[nb.ff] = dis[i] + 1;
		}
	}

	return dis;
}

int32_t main()
{
	FIO;

	int m; cin >> n >> m;
	adj.resize(n + 1);

	while (m--)
	{
		int i, j, col; cin >> i >> j >> col;
		adj[i].pb({j, col});
		adj[j].pb({i, col});
	}

	int src, dest; cin >> src >> dest;

	vi ds = bfs(src, 0);
	vi dd = bfs(dest, 1);

	int ans = inf;

	for (int i = 1; i <= n; ++i)
	{
		if (i == src or i == dest or ds[i] == -1 or dd[i] == -1 or ds[dest] == -1)
			continue;

		ans = min(ans, ds[i] + dd[i]);
	}

	if (ans == inf)
		ans = -1;

	cout << ans << '\n';

	return 0;
}
