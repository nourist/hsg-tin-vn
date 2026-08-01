#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); ++i)
#define FOD(i,r,l) for (int i = (r); i >= (l); --i)
#define ll long long
#define db double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define BIT(x, i) (((x) >> (i)) & 1)
#define BIT_COUNT(x) __builtin_popcountll(x)
#define LOWEST_BIT(x) __builtin_ctzll(x)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "b2"

int a[(int)2e5 + 5];
vii adj[(int)2e5 + 5];
int st[(int)2e5 + 5][32];
pll dp[(int)2e5 + 5];

void dfs(int u, int par) {
	dp[u] = { 1e18, 1e18 };
	for (auto e : adj[u]) {
		int v = e.X;
		int w = e.Y;

		if (v == par)continue;

		dfs(v, u);
		dp[u] = min({ dp[u], {dp[v].X + w, dp[v].Y}, {-a[v] + w, v} });
	}
}

void reRoot(int u, int par) {
	st[u][0] = dp[u].Y;
	vector<pair<pll, pll>>edges;
	for (auto e : adj[u]) {
		int v = e.X;
		int w = e.Y;
		edges.push_back({ min(make_pair(dp[v].X + w, dp[v].Y), make_pair((ll)-a[v] + w, (ll)v)),  e });
	}
	sort(all(edges));

	FOR(i, 0, edges.size() - 1) {
		int v = edges[i].Y.X;
		int w = edges[i].Y.Y;

		if (v == par)continue;

		auto oldDpu = dp[u];
		auto oldDpv = dp[v];

		if (v == edges[0].Y.X) {
			if (edges.size() == 1)dp[u] = { 1e18, 1e18 };
			else dp[u] = edges[1].X;
		}
		else dp[u] = edges[0].X;

		dp[v] = min({ dp[v], { dp[u].X + w, dp[u].Y }, {-a[u] + w, u} });

		reRoot(v, u);

		dp[u] = oldDpu;
		dp[v] = oldDpv;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, q;
	cin >> n >> q;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}

	dfs(1, 0);
	reRoot(1, 0);

	FOR(i, 1, 30)FOR(j, 1, n)st[j][i] = st[st[j][i - 1]][i - 1];

	while (q--) {
		int s, k;
		cin >> s >> k;
		FOD(i, 30, 0) {
			if (k >= (1 << i)) {
				s = st[s][i];
				k -= (1 << i);
			}
		}
		cout << s << endl;
	}
}
