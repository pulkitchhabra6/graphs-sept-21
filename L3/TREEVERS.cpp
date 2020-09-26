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
vi w;

struct trio
{
	int inv, zeroes, ones;
};

bool comp(trio &a, trio &b)
{
	return a.ones * b.zeroes < b.ones * a.zeroes;
}

/*
bool def(int a,int b)
{
	return a<b;
}*/

trio dfs(int nd = 1, int pr = 0)
{
	trio cur;
	cur.inv = 0, cur.zeroes = 0, cur.ones = 0;

	vector<trio> subtr;

	for (int ch : adj[nd])
	{
		if (ch == pr)
			continue;

		subtr.pb(dfs(ch, nd));
	}

	sort(subtr.begin(), subtr.end(), comp);

	if (w[nd] == 1)
		cur.ones++;

	else
		cur.zeroes++;

	for (trio &t : subtr)
	{
		cur.inv += t.inv;
		cur.inv += cur.ones * t.zeroes;

		cur.zeroes += t.zeroes;
		cur.ones += t.ones;
	}

	return cur;

}

int32_t main()
{
	FIO;
	w(T)
	{
		int n; cin >> n;

		adj.clear();
		adj.resize(n + 1);
		w.resize(n + 1);

		for (int i = 1; i <= n; ++i)
			cin >> w[i];

		for (int i = 0; i < n - 1; ++i)
		{
			int u, v; cin >> u >> v;

			adj[u].pb(v);
			adj[v].pb(u);
		}

		trio ans = dfs();

		cout << ans.inv << '\n';
	}
	return 0;
}
