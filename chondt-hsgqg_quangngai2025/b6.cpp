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
#define Name "b6"

int n, m, k;
vi adj[(int)1e5 + 5];

namespace Tarjan {
	int timeDfs = 0;
	int num[(int)1e5 + 5];
	int low[(int)1e5 + 5];

	bool deleted[(int)1e5 + 5];
	stack<int>st;
	int scc[(int)1e5 + 5];
	int sccCnt[(int)1e5 + 5];
	int timeScc;

	void dfs(int u, int par) {
		num[u] = low[u] = ++timeDfs;
		st.push(u);

		bool skipped_par = false;
		for (int v : adj[u]) {
			if (v == par && !skipped_par) {
				skipped_par = true;
				continue;
			}

			if (!num[v]) {
				dfs(v, u);
				low[u] = min(low[u], low[v]);
			}
			else if (!deleted[v]) {
				low[u] = min(low[u], num[v]);
			}
		}

		if (num[u] == low[u]) {
			timeScc++;
			while (1) {
				int v = st.top();
				st.pop();

				deleted[v] = 1;
				scc[v] = timeScc;
				sccCnt[timeScc]++;

				if (v == u)break;
			}
		}
	}
}

namespace Centroid {
	int n;
	vi adj[(int)1e5 + 5];
	int cnt[(int)1e5 + 5];
	int sz[(int)1e5 + 5];
	bool del[(int)1e5 + 5];

	void calcSz(int u, int par) {
		sz[u] = 1;
		for (int v : adj[u]) {
			if (v != par && !del[v]) {
				calcSz(v, u);
				sz[u] += sz[v];
			}
		}
	}

	int centroid(int u, int par, int n) {
		for (int v : adj[u]) {
			if (v != par && !del[v] && sz[v] > n / 2) {
				return centroid(v, u, n);
			}
		}
		return u;
	}

	void getDist(int u, int par, int dist, vii& cur) {
		cur.push_back({ dist, cnt[u] });
		for (int v : adj[u]) {
			if (v != par && !del[v]) {
				getDist(v, u, dist + 1, cur);
			}
		}
	}

	ll calc(vii& a) {
		sort(a.begin(), a.end());

		vi f(a.size());

		FOR(i, 0, (int)a.size() - 1) {
			f[i] = a[i].Y;
			if (i != 0)f[i] += f[i - 1];
		}

		ll res = 0;

		int l = 0;
		int r = (int)a.size() - 1;

		while (l < r) {
			if (a[l].X + a[r].X >= k) {
				ll sum_Y = f[r - 1] - (l > 0 ? f[l - 1] : 0);
				res += 1LL * a[r].Y * sum_Y;
				r--;
			}
			else {
				l++;
			}
		}

		return res;
	}


	ll solveCentroid(int c) {
		ll res = 0;

		vii all;
		all.push_back({ 0, cnt[c] });

		for (int v : adj[c]) {
			if (del[v]) continue;

			vii cur;

			getDist(v, c, 1, cur);

			res -= calc(cur);

			for (auto d : cur)
				all.push_back(d);
		}

		res += calc(all);

		return res;
	}

	ll solve(int u) {
		calcSz(u, 0);

		int n = sz[u];
		int root = centroid(u, 0, n);

		ll res = solveCentroid(root);

		del[root] = 1;
		for (int v : adj[root]) {
			if (!del[v]) {
				res += solve(v);
			}
		}
		return res;
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

	cin >> n >> m >> k;
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	if (k < 0) {
		cout << 0;
		return 0;
	}
	else if (k == 0) {
		cout << 1LL * n * (n - 1) / 2;
		return 0;
	}

	Tarjan::dfs(1, 0);

	Centroid::n = Tarjan::timeScc;
	FOR(u, 1, n) {
		for (int v : adj[u]) {
			if (Tarjan::scc[u] != Tarjan::scc[v]) {
				Centroid::adj[Tarjan::scc[u]].pb(Tarjan::scc[v]);
			}
		}
	}
	FOR(i, 1, Tarjan::timeScc) {
		Centroid::cnt[i] = Tarjan::sccCnt[i];
	}

	cout << Centroid::solve(1);
}
