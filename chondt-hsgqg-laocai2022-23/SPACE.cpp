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
#define pib pair<int,bool>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vib vector<pib>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "space"

ll n, k, R;
ll d[(int)1e6 + 6];
ll v[(int)1e6 + 6];
vll adj[(int)1e6 + 6];

namespace buildGraph {
	ll fd[(int)1e6 + 6];
	ll fv[(int)1e6 + 6];

	void process() {
		FOR(i, 1, n)fd[i] = fd[i - 1] + d[i];
		FOR(i, 1, n)fv[i] = fv[i - 1] + v[i];

		int l = 1, mid = 1, r = 1;

		for (l; l <= n; l++) {
			while (mid + 1 <= n && fd[mid + 1] - fd[l] <= R) mid++;
			while (r <= n && fd[r] - fd[mid] <= R)r++;

			adj[r].push_back({ l, fv[r - 1] - fv[l - 1] });
		}

		FOR(i, 1, n)adj[0].push_back({ i, 0 });
	}
}

namespace travelGraph {
	ll f[(int)1e6 + 6];
	vi path;
	ll res = 0;

	void dfs(int u, int par) {
		path.push_back(u);

		res = max(res, f[u] - f[path[max(0LL, (ll)path.size() - k - 1)]]);

		for (auto to : adj[u]) {
			ll v = to.X;
			ll w = to.Y;

			if (v == par)continue;

			f[v] = f[u] + w;
			dfs(v, u);
		}

		path.pop_back();
	}

	void process() {
		dfs(n + 1, -1);
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

	cin >> n >> k >> R;
	FOR(i, 2, n)cin >> d[i];
	FOR(i, 1, n)cin >> v[i];

	buildGraph::process();
	travelGraph::process();

	// FOR(i, 1, n) {
	// 	cout << i << ": ";
	// 	for (auto v : adj[i])cout << v.X << ' ' << v.Y;
	// 	cout << endl;
	// }

	cout << travelGraph::res;
}
