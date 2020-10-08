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
#define inf             1e9
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n;
vector<vector<pii> > adj;

int bfs01()
{
	vector<int> d(n + 1, inf);
	d[1] = 0;
	deque<int> q;
	q.push_front(1);

	while (!q.empty())
	{
		int v = q.front();
		q.pop_front();
		for (auto edge : adj[v]) {
			int u = edge.first;
			int w = edge.second;
			if (d[v] + w < d[u]) {
				d[u] = d[v] + w;
				if (w == 1)
					q.push_back(u);
				else
					q.push_front(u);
			}
		}
	}

	return d[n] == inf ? -1 : d[n];
}

int32_t main()
{
	FIO;
	int m; cin >> n >> m;

	adj.resize(n + 1);

	while (m--)
	{
		int i, j; cin >> i >> j;

		adj[i].pb({j, 0});
		adj[j].pb({i, 1});
	}

	cout << bfs01() << '\n';

	return 0;
}
