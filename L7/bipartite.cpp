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
vector<int> col;
//col->0 -> hasn't been visited
//col->1 -> the color assigned is 1
//col->2 -> the color assigned is 2

bool dfs(int i, int c)
{
	if (!col[i])
		col[i] = c;

	else
		return col[i] == c;

	//if col[i] was 0
	bool pos = true;

	for (int j : adj[i])
		pos &= dfs(j, 3 - c);

	return pos;
}

int check_if_bipartite(int n)
{
	col.assign(n + 1, 0);

	bool possible = 1;

	for (int i = 1; i <= n; ++i)
		if (!col[i])
			possible &= dfs(i, 1);

	return possible;
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

	cout << check_if_bipartite(n) << '\n';

	return 0;
}
