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
#define Name "b7"

int s[(int)1e5 + 5];
vii adj[(int)1e5 + 5];
ll dist[(int)1e5 + 5];
int root[(int)1e5 + 5];

vector<pair<pii, ll>>edges;
int par[(int)1e5 + 5];
int sz[(int)1e5 + 5];

int find(int u) {
	if (par[u] == u)return u;
	return par[u] = find(par[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)return;

	if (sz[u] < sz[v])swap(u, v);
	sz[u] += sz[v];
	par[v] = u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	FOR(i, 1, 1e5) {
		par[i] = i;
		sz[i] = 1;
	}

	int n, m, k;
	cin >> n >> m >> k;
	FOR(i, 1, k)cin >> s[i];
	FOR(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}

	FOR(i, 1, n)dist[i] = 1e18;
	priority_queue<pll, vll, greater<pll>>q;

	FOR(i, 1, k) {
		dist[s[i]] = 0;
		root[s[i]] = i;
		q.push({ 0, s[i] });
	}

	while (!q.empty()) {
		auto s = q.top();
		q.pop();

		ll d = s.X;
		ll u = s.Y;

		if (d != dist[u])continue;

		for (auto e : adj[u]) {
			int v = e.X;
			int w = e.Y;

			if (d + w < dist[v]) {
				dist[v] = d + w;
				root[v] = root[u];
				q.push({ dist[v], v });
			}
		}
	}

	FOR(u, 1, n) {
		for (auto e : adj[u]) {
			int v = e.X;
			int w = e.Y;

			if (root[u] != root[v]) {
				edges.pb({ {root[u],root[v]}, dist[v] + dist[u] + w });
			}
		}
	}

	sort(all(edges), [&](auto x, auto y) {
		return x.Y < y.Y;
		});

	ll res = 0;
	for (auto e : edges) {
		int u = e.X.X;
		int v = e.X.Y;
		ll w = e.Y;

		if (find(u) != find(v)) {
			res += w;
			merge(u, v);
		}
	}
	cout << res;
}
