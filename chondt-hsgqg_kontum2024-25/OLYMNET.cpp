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
#define Name "OLYMNET"

struct DSU {
	int par[1003];
	int sz[1003];

	DSU() {
		FOR(i, 1, 1000) { par[i] = i; sz[i] = 1; }
	}

	int find(int u) {
		if (par[u] == u)return u;
		return par[u] = find(par[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (sz[v] > sz[u])swap(u, v);

		par[v] = u;
		sz[u] += sz[v];
	}

	bool ok(int u, int v) {
		return find(u) == find(v);
	}
}dsu;

pair<int, pii>edges[(int)1e4 + 4];
vii adj[1003];
int depth[1003];
int up[1003][10];
int st[1003][10];
bool used[(int)1e4 + 4];

void dfs(int u) {
	for (auto e : adj[u]) {
		int v = e.X;
		int w = e.Y;
		if (v == up[u][0])continue;
		up[v][0] = u;
		st[v][0] = w;
		depth[v] = depth[u] + 1;
		dfs(v);
	}
}

int lca(int u, int v) {
	int res = 0;
	if (depth[u] > depth[v])swap(u, v);
	FOD(i, 9, 0)if (depth[v] - (1 << i) >= depth[u]) {
		res = max(res, st[v][i]);
		v = up[v][i];
	}

	if (u == v)return res;

	FOD(i, 9, 0)if (up[v][i] != up[u][i]) {
		res = max({ res, st[v][i], st[u][i] });
		u = up[u][i];
		v = up[v][i];
	}
	return max({ res, st[u][0], st[v][0] });
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	FOR(i, 1, m) {
		cin >> edges[i].Y.X >> edges[i].Y.Y >> edges[i].X;
	}

	sort(edges + 1, edges + m + 1);

	int res1 = 0;
	FOR(i, 1, m) {
		if (!dsu.ok(edges[i].Y.X, edges[i].Y.Y)) {
			dsu.merge(edges[i].Y.X, edges[i].Y.Y);
			res1 += edges[i].X;
			adj[edges[i].Y.X].pb({ edges[i].Y.Y, edges[i].X });
			adj[edges[i].Y.Y].pb({ edges[i].Y.X, edges[i].X });
			used[i] = 1;
		}
	}

	dfs(1);

	FOR(k, 1, 9)FOR(i, 1, n) {
		up[i][k] = up[up[i][k - 1]][k - 1];
		st[i][k] = max(st[i][k - 1], st[up[i][k - 1]][k - 1]);
	}

	int res2 = 1e9;

	FOR(i, 1, m) {
		if (used[i])continue;
		res2 = min(res2, res1 - lca(edges[i].Y.X, edges[i].Y.Y) + edges[i].X);
	}

	cout << res1 << ' ' << res2 << endl;
}
