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
#define Name "LIFECITY"

vi adj[(int)1e5 + 5];
int up[(int)1e5 + 5][20];
int depth[(int)1e5 + 5];
int st[(int)1e5 + 5];
int timeDfs = 0;

void dfs(int u) {
	st[u] = ++timeDfs;

	for (int v : adj[u]) {
		if (v == up[u][0])continue;

		depth[v] = depth[u] + 1;
		up[v][0] = u;
		dfs(v);
	}
}

int lca(int u, int v) {
	if (depth[v] < depth[u])swap(u, v);

	FOD(i, 16, 0)if (depth[v] - (1 << i) >= depth[u]) v = up[v][i];

	if (u == v)return u;

	FOD(i, 16, 0)if (up[v][i] != up[u][i]) {
		u = up[u][i];
		v = up[v][i];
	}

	return up[u][0];
}

int dist(int u, int v) {
	return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

bool inside(int a, int u, int v) {
	return dist(u, a) + dist(a, v) == dist(u, v);
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

	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);
	FOR(k, 1, 16)FOR(i, 1, n)up[i][k] = up[up[i][k - 1]][k - 1];

	while (q--) {
		int u, v, w;
		cin >> u >> v >> w;
		int g = lca(u, v);
		cout << inside(w, u, v) << endl;
	}
}
