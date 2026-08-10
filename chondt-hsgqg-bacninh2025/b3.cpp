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
#define Name "backup"

struct DSU {
	int par[(int)1e5 + 5];
	int sz[(int)1e5 + 5];

	DSU() {
		FOR(i, 1, 1e5) { par[i] = i; sz[i] = 1; }
	}

	int find(int u) {
		if (u == par[u])return u;
		return par[u] = find(par[u]);
	}

	bool connect(int u, int v) {
		return find(u) == find(v);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v) return;

		if (sz[u] < sz[v])swap(u, v);

		par[v] = u;
		sz[u] += sz[v];
	}
}dsu;

int n, q;
vii adj[(int)1e5 + 5];

namespace LCA {
	int depth[(int)1e5 + 5];
	int up[(int)1e5 + 5][17];
	int st[(int)1e5 + 5][17];

	void dfs(int u) {
		for (auto e : adj[u]) {
			int v = e.X;
			int w = e.Y;

			if (v == up[u][0])continue;

			depth[v] = depth[u] + 1;
			up[v][0] = u;
			st[v][0] = w;
			dfs(v);
		}
	}

	void build() {
		FOR(i, 0, n) FOR(k, 0, 16) {
			if (i == 0 || k > 0) st[i][k] = 1e9 + 7;
		}
		FOR(k, 1, 16)FOR(i, 1, n) {
			up[i][k] = up[up[i][k - 1]][k - 1];
			st[i][k] = min(st[i][k - 1], st[up[i][k - 1]][k - 1]);
		}
	}

	int lca(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		int res = 1e9;
		FOD(i, 16, 0)if (depth[v] - (1 << i) >= depth[u]) {
			res = min(res, st[v][i]);
			v = up[v][i];
		}
		if (u == v)return res;
		FOD(i, 16, 0) {
			if (up[v][i] != up[u][i]) {
				res = min({ res, st[v][i], st[u][i] });
				v = up[v][i];
				u = up[u][i];
			}
		}
		res = min({ res, st[v][0], st[u][0] });
		return res;
	}
}

struct Query {
	int t, u, v, res;
}qr[(int)1e5 + 5];

int dest[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> q;

	FOR(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}

	LCA::dfs(1);
	LCA::build();

	FOR(i, 1, q) {
		cin >> qr[i].t;
		if (qr[i].t == 1)cin >> qr[i].u >> qr[i].v;
		else {
			cin >> qr[i].u;
			dest[qr[i].u]++;
		}
	}

	FOR(u, 1, n) {
		if (dest[u] == 0) {
			for (auto e : adj[u]) {
				int v = e.X;
				if (dest[v] == 0) {
					dsu.merge(u, v);
				}
			}
		}
	}

	FOD(i, q, 1) {
		if (qr[i].t == 2) {
			dest[qr[i].u]--; if (dest[qr[i].u] == 0)
				for (auto e : adj[qr[i].u]) {
					int v = e.X;
					if (dest[v] == 0)
						dsu.merge(qr[i].u, v);
				}
		}
		else {
			if (qr[i].u == qr[i].v) {
				qr[i].res = 0;
			}
			else if ((dest[qr[i].u] != 0) || (dest[qr[i].v] != 0)) {
				qr[i].res = -1;
			}
			else if (!dsu.connect(qr[i].u, qr[i].v)) {
				qr[i].res = -1;
			}
			else {
				qr[i].res = LCA::lca(qr[i].u, qr[i].v);
			}
		}
	}
	FOR(i, 1, q)if (qr[i].t == 1)cout << qr[i].res << endl;
}
