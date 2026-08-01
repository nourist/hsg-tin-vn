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
#define Name "b3"

int n;
int c[(int)1e6 + 6];
int a[(int)1e6 + 6];
vi adj[(int)1e6 + 6];

int timeDfs = 0;
int depth[(int)1e6 + 6];
int st[(int)1e6 + 6];
int en[(int)1e6 + 6];
int up[(int)1e6 + 6][20];
int st_c[20][(int)1e6 + 6];
vi groups[(int)1e6 + 6];

int query_c(int L, int R) {
	if (L > R) return 2e9;
	int j = __lg(R - L + 1);
	return min(st_c[j][L], st_c[j][R - (1 << j) + 1]);
}

void preDfs(int u) {
	st[u] = ++timeDfs;
	if (a[u] == 0)
		groups[depth[u]].pb(u);
	for (int v : adj[u]) {
		if (v == up[u][0])continue;
		depth[v] = depth[u] + 1;
		up[v][0] = u;
		preDfs(v);
	}
	en[u] = timeDfs;
}

bool isAnc(int u, int v) {// u is ancestor of v
	return st[u] <= st[v] && en[v] <= en[u];
}

int lca(int u, int v) {
	if (depth[u] > depth[v])swap(u, v);
	FOD(i, 19, 0)if (depth[v] - (1 << i) >= depth[u])v = up[v][i];
	if (u == v)return u;
	FOD(i, 19, 0)if (up[u][i] != up[v][i]) {
		u = up[u][i];
		v = up[v][i];
	}
	return up[u][0];
}

vi adj_vt[(int)1e6 + 6];
ll dp[(int)1e6 + 6];

void dfs(int u, int par, int d) {
	dp[u] = 0;
	for (int v : adj_vt[u]) {
		if (v == par)continue;
		dfs(v, u, d);
		dp[u] += min(dp[v], (ll)query_c(d - depth[v], d - depth[u] - 1));
	}
	if (adj_vt[u].size() == 0)dp[u] = c[0];
	else dp[u] = min(dp[u], (ll)c[d - depth[u]]);
}

ll solveDepth(int d) {
	if (groups[d].size() == 0)return 0;
	vector<int>nodes = groups[d];
	FOR(i, 1, (int)groups[d].size() - 1)
		nodes.pb(lca(groups[d][i - 1], groups[d][i]));

	sort(all(nodes), [&](int u, int v) {
		return st[u] < st[v];
		});

	nodes.erase(unique(all(nodes)), nodes.end());

	vi s;
	for (int u : nodes) {
		while (s.size() >= 2 && !isAnc(s.back(), u)) {
			adj_vt[s[s.size() - 2]].pb(s.back());
			s.pop_back();
		}
		s.push_back(u);
	}
	while (s.size() >= 2) {
		adj_vt[s[s.size() - 2]].pb(s.back());
		s.pop_back();
	}

	dfs(nodes[0], 0, d);
	for (int u : nodes)adj_vt[u].clear();
	return min(dp[nodes[0]], (ll)query_c(d - depth[nodes[0]], d));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n;
	FOR(i, 0, n - 1)cin >> c[i];
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	preDfs(1);
	FOR(i, 1, 19)FOR(j, 1, n)up[j][i] = up[up[j][i - 1]][i - 1];

	for (int i = 0; i < n; i++) st_c[0][i] = c[i];
	for (int j = 1; j < 20; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			st_c[j][i] = min(st_c[j - 1][i], st_c[j - 1][i + (1 << (j - 1))]);
		}
	}

	ll res = 0;
	FOR(i, 0, *max_element(depth + 1, depth + n + 1))
		res += solveDepth(i);
	cout << res;
}
