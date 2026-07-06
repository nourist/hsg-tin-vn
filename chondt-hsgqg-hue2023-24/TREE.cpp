#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define int long long 

const int mod = 1e9 + 7;
int n, q, a[(int)1e5 + 5];
vector<int>adj[(int)1e5 + 5];
int p[(int)1e5 + 5];
int sz[(int)1e5 + 5];
int f[(int)1e5 + 5];
int res[(int)1e5 + 5];
int inv[(int)2e6 + 6];
int curRes = 1;

void factor(int n, int delta) {
	while (n != 1) {
		curRes = curRes * inv[f[p[n]] + 1] % mod;
		f[p[n]] += delta;
		curRes = curRes * (f[p[n]] + 1) % mod;
		n /= p[n];
	}
}

void add(int u, int par, int delta) {
	factor(a[u], delta);
	for (int v : adj[u])if (v != par)add(v, u, delta);
}

void preDfs(int u, int par) {
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v == par)continue;
		preDfs(v, u);
		sz[u] += sz[v];
	}
}

void dfs(int u, int par) {
	int bigChild = -1;
	for (int v : adj[u])if (v != par && (bigChild == -1 || sz[v] > sz[bigChild]))bigChild = v;

	for (int v : adj[u])if (v != bigChild && v != par) {
		dfs(v, u);
		add(v, u, -1);
	}

	if (bigChild != -1)dfs(bigChild, u);

	for (int v : adj[u])if (v != bigChild && v != par) {
		add(v, u, 1);
	}

	factor(a[u], 1);

	res[u] = curRes;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("TREE.inp", "r")) {
		freopen("TREE.inp", "r", stdin);
		freopen("TREE.out", "w", stdout);
	}

	FOR(i, 1, 1e5)p[i] = i;
	for (int i = 2; i * i <= 1e5; i++)if (p[i] == i)for (int j = i * i; j <= 1e5; j += i)if (p[j] == j)p[j] = i;

	inv[1] = 1;
	FOR(i, 2, 2e6)inv[i] = mod - (mod / i) * inv[mod % i] % mod;

	cin >> n >> q;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	preDfs(1, 0);
	dfs(1, 0);

	FOR(i, 1, q) {
		int u;
		cin >> u;
		cout << res[u] << ' ';
	}
}

