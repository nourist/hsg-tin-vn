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
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "DUNGEON"

int n, q;
int a[250025];
int id[250025];
vi adj[250025];

struct Query {
	int id, s, t, l = 1, r = 1e5, res = 1;
}qr[(int)4e5 + 5];

bool ok() {
	FOR(i, 1, q)if (qr[i].r >= qr[i].l)return 1;
	return 0;
}

namespace dsu {
	int par[250025];
	int sz[250025];
	bool used[250025];

	void clear() {
		FOR(i, 1, n * n) {
			par[i] = i;
			sz[i] = 1;
			used[i] = 0;
		}
	}

	int find(int u) {
		if (u == par[u])return u;
		return par[u] = find(par[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v)return;

		if (sz[u] < sz[v])swap(u, v);

		par[v] = u;
		sz[u] += sz[v];
	}

	bool check(int u, int v) {
		return used[u] && used[v] && find(u) == find(v);
	}

	void add(int u) {
		used[u] = 1;
		for (int v : adj[u])if (used[v])merge(u, v);
	}
}

vector<Query>bucket[(int)1e5 + 5];

void sortQuery() {
	FOR(i, 1, 1e5)bucket[i].clear();

	FOR(i, 1, q)bucket[(qr[i].l + qr[i].r) / 2].pb(qr[i]);

	int cur = 1;
	FOD(i, 1e5, 1)FOR(j, 0, (int)bucket[i].size() - 1) {
		qr[cur++] = bucket[i][j];
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
	FOR(i, 1, n * n)cin >> a[i];

	FOR(i, 1, n * n)id[i] = i;

	sort(id + 1, id + n * n + 1, [&](int x, int y) {
		return a[x] > a[y];
		});

	FOR(i, 1, n)FOR(j, 1, n) {
		int u = (i - 1) * n + j;
		if (i != 1)adj[u].pb((i - 2) * n + j);
		if (i != n)adj[u].pb(i * n + j);
		if (j != 1)adj[u].pb((i - 1) * n + j - 1);
		if (j != n)adj[u].pb((i - 1) * n + j + 1);
	}

	FOR(i, 1, q) {
		qr[i].id = i;
		int x, y, u, v;
		cin >> x >> y >> u >> v;

		qr[i].s = (x - 1) * n + y;
		qr[i].t = (u - 1) * n + v;
	}

	while (ok()) {
		sortQuery();

		dsu::clear();

		int cur = 0;
		FOR(i, 1, q) {
			if (qr[i].l > qr[i].r) continue;

			int mid = (qr[i].l + qr[i].r) / 2;
			while (cur + 1 <= n * n && a[id[cur + 1]] >= mid) {
				cur++;
				dsu::add(id[cur]);
			}
			if (dsu::check(qr[i].s, qr[i].t)) {
				qr[i].res = mid;
				qr[i].l = mid + 1;
			}
			else {
				qr[i].r = mid - 1;
			}
		}
	}

	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		return x.id < y.id;
		});

	FOR(i, 1, q)cout << qr[i].res << '\n';
}
