#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
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
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "star"

int n, q;
vi adj[(int)1e5 + 5];
int depth[(int)1e5 + 5];
int up[(int)1e5 + 5][20];
int f[(int)1e5 + 5];

void preDfs(int u) {
	for (int v : adj[u]) {
		if (v == up[u][0])continue;

		depth[v] = depth[u] + 1;
		up[v][0] = u;

		preDfs(v);
	}
}

void preprocess() {
	FOR(j, 1, 16)FOR(i, 1, n) {
		up[i][j] = up[up[i][j - 1]][j - 1];
	}
}

int lca(int u, int v) {
	if (depth[u] > depth[v])swap(u, v);

	FOD(i, 16, 0) {
		if (depth[v] - (1 << i) >= depth[u]) {
			v = up[v][i];
		}
	}

	if (u == v)return u;

	FOD(i, 16, 0) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}

	return up[u][0];
}

void dfs(int u) {
	for (int v : adj[u]) {
		if (v == up[u][0])continue;

		dfs(v);

		f[u] += f[v];
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

	cin >> n >> q;
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	preDfs(1);
	preprocess();

	while (q--) {
		int u, v;
		cin >> u >> v;

		int g = lca(u, v);

		f[u]++;
		f[v]++;
		f[g] -= 2;
	}

	dfs(1);

	int res = 0;
	FOR(i, 1, n) {
		res = max(res, f[i]);
	}
	cout << res;
}