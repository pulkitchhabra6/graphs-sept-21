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


int n, m;
int arr[501][501];
vector<pii> adj[501][501];
vector<pii> spl;

bool check(int i, int j)
{
	return (i >= 1 && j >= 1 && i <= n && j <= m);
}

int get_ans()
{
	queue<pii> q;
	vector<vector<bool> > vis(n + 1, vector<bool>(m + 1, 0));
	vector<vi> d(n + 1, vi(m + 1));

	for (pii cell : spl)
	{
		d[cell.ff][cell.ss] = 0;
		vis[cell.ff][cell.ss] = 1;
		q.push(cell);
	}

	int ans = 0;

	while (!q.empty())
	{
		pii v = q.front();
		q.pop();

		for (pii u : adj[v.ff][v.ss])
		{
			if (!vis[u.ff][u.ss])
			{
				vis[u.ff][u.ss] = true;
				q.push(u);
				d[u.ff][u.ss] = d[v.ff][v.ss] + 1;
				ans = max(ans, d[u.ff][u.ss]);
			}
		}
	}

	return ans;
}

void add_edges()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			adj[i][j].clear();

			int di[] = { -1, -1, -1, 0, 0, 1, 1, 1};
			int dj[] = { -1, 0, 1, -1, 1, -1, 0, 1};

			for (int id = 0; id < 8; ++id)
			{
				if (check(i + di[id], j + dj[id]))
					adj[i][j].pb({i + di[id], j + dj[id]});
			}
		}
	}
}

int32_t main()
{
	FIO;
	w(t)
	{
		cin >> n >> m;
		int mx = 0;

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				cin >> arr[i][j];
				mx = max(mx, arr[i][j]);
			}

		add_edges();
		spl.clear();

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (arr[i][j] == mx)
					spl.pb({i, j});

		cout << get_ans() << '\n';
	}
	return 0;
}
