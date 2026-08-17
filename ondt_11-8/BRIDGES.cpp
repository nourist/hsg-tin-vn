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
#define Name "BRIDGES"

int n, k, p, c;
vector<pair<pll, pll>>edges;
vll adj[(int)1e4 + 4];
int id[(int)1e4 + 4];

namespace calcSz {
	int up[(int)1e4 + 4];
	int down[(int)1e4 + 4];

	void dfs(int u, int par) {
		down[u] = 1;
		for (auto e : adj[u]) {
			int v = e.X;

			if (v == par)continue;

			dfs(v, u);
			down[u] += down[v];
		}
	}

	void reroot(int u, int par) {
		up[u] += 1;
		int sum = 0;
		for (auto e : adj[u]) {
			int v = e.X;

			if (v == par)continue;

			sum += down[v];
		}
		for (auto e : adj[u]) {
			int v = e.X;
			int id = e.Y;

			if (v == par)continue;

			up[v] = up[u] + sum - down[v];
			edges[id].Y.Y = 1LL * (up[u] + sum - down[v]) * down[v];
			reroot(v, u);
		}
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

	cin >> n >> k >> p >> c;
	FOR(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.pb({ {u, v}, {w, 0} });
		adj[u].pb({ v, edges.size() - 1 });
		adj[v].pb({ u, edges.size() - 1 });
	}

	calcSz::dfs(1, 0);
	calcSz::reroot(1, 0);

	FOR(i, 1, n - 1)id[i] = i - 1;

	sort(id + 1, id + n, [&](int a, int b) {
		if (1LL * edges[a].Y.Y * edges[a].Y.X == 1LL * edges[b].Y.Y * edges[b].Y.X)return a < b;
		if (c < p)
			return 1LL * edges[a].Y.Y * edges[a].Y.X < 1LL * edges[b].Y.Y * edges[b].Y.X;
		return 1LL * edges[a].Y.Y * edges[a].Y.X > 1LL * edges[b].Y.Y * edges[b].Y.X;
		});

	FOR(i, 1, k) {
		cout << id[i] + 1 << endl;
	}
}
