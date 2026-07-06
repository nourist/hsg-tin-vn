#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll n, k;
ll w[(ll)2e5 + 5];
vector<ll>adj[(ll)2e5 + 5];
struct {
	ll u, v;
}ship[(ll)2e5 + 5];
ll h[(ll)2e5 + 5], up[(ll)2e5 + 5][20], max_w[(ll)2e5 + 5][20];
ll dp[(ll)2e5 + 5];

void init() {
	cin >> n;
	for (ll i = 1; i <= n; i++)cin >> w[i];
	for (ll u, v, i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
	adj[0] = { 1 };
	cin >> k;
	for (ll i = 1; i <= k; i++)cin >> ship[i].u >> ship[i].v;
}

void dfs(ll u = 0) {
	for (ll v : adj[u]) {
		if (v == up[u][0])continue;

		h[v] = h[u] + 1;
		up[v][0] = u;
		max_w[v][0] = max(w[v], w[u]);

		for (ll i = 1; i < 20; i++) {
			up[v][i] = up[up[v][i - 1]][i - 1];
			max_w[v][i] = max(max_w[v][i - 1], max_w[up[v][i - 1]][i - 1]);
		}
		dfs(v);
	}
}

ll reward(ll u, ll v) {
	ll res = 0;
	if (h[u] != h[v]) {
		if (h[u] < h[v])
			swap(u, v);

		ll k = h[u] - h[v];
		for (ll i = 0; (1 << i) <= k; i++) {
			if (k >> i & 1) {
				res = max(res, max_w[u][i]);
				u = up[u][i];
			}
		}
	}
	if (u == v) {
		return max(res, w[u]);
	}
	ll k = __lg(h[u]);
	for (ll i = k-1; i >= 0; i--) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
			res = max({ res, max_w[u][i], max_w[v][i] });
		}
	}
	return max({ res, max_w[u][0], max_w[v][0] });
}

void solve() {
	fill(dp + 1, dp + (int)2e5 + 1, -1e18);
	dp[1] = 0;

	ll res = 0;
	for (int i = 1; i <= k; i++) {
		dp[ship[i].v] = max(dp[ship[i].v], dp[ship[i].u] + reward(ship[i].u, ship[i].v));
		res = max(res, dp[ship[i].v]);
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("ship.inp", "r")) {
		freopen("ship.inp", "r", stdin);
		freopen("ship.out", "w", stdout);
	}

	init();
	dfs();
	solve();
}

//wa 3test