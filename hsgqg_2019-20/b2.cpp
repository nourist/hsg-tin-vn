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
#define Name "b2"

struct DsuRollback {
	int par[(int)5e4 + 4];
	int sz[(int)5e4 + 4];

	struct Change {
		int u, v, old_sz;
	};

	vector<Change>st;

	DsuRollback() {
		FOR(i, 1, 5e4) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	int find(int u) {
		if (par[u] == u)return u;
		return find(par[u]);
	}

	bool connect(int u, int v) {
		return find(u) == find(v);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v)return;

		if (sz[u] < sz[v])swap(u, v);

		st.push_back({ u, v, sz[u] });

		par[v] = u;
		sz[u] += sz[v];
	}

	int snapshot() {
		return st.size();
	}

	void rollback(int ver) {
		while (st.size() > ver) {
			Change c = st.back();
			st.pop_back();

			par[c.v] = c.v;
			sz[c.u] = c.old_sz;
		}
	}
}dsu;

int n, m, s, t;
vector<pair<pii, int>>A, B;
int res = 2e9;

void solve(int l, int r, int opt_l, int opt_r) {
	if (l > r) return;

	int mid = l + r >> 1;
	int ver = dsu.snapshot();
	FOR(i, l, mid) {
		dsu.merge(A[i].X.X, A[i].X.Y);
	}
	int ver2 = dsu.snapshot();

	int opt_mid = -1;
	FOR(i, opt_l, opt_r) {
		dsu.merge(B[i].X.X, B[i].X.Y);
		if (dsu.connect(s, t)) {
			res = min(res, A[mid].Y + B[i].Y);
			opt_mid = i;
			break;
		}
	}

	if (opt_mid == -1) {
		dsu.rollback(ver2);
		solve(mid + 1, r, opt_l, opt_r);
		dsu.rollback(ver);
		return;
	}

	dsu.rollback(ver);
	FOR(i, opt_l, opt_mid - 1)
		dsu.merge(B[i].X.X, B[i].X.Y);

	solve(l, mid - 1, opt_mid, opt_r);

	dsu.rollback(ver);
	FOR(i, l, mid)
		dsu.merge(A[i].X.X, A[i].X.Y);

	solve(mid + 1, r, opt_l, opt_mid);

	dsu.rollback(ver);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> m >> s >> t;

	FOR(i, 1, m) {
		int c, u, v, w;
		cin >> c >> u >> v >> w;
		if (c == 1)A.pb({ {u,v},w });
		else B.pb({ { u, v }, w });
	}

	sort(all(A), [&](auto x, auto y) {
		return x.Y < y.Y;
		});

	sort(all(B), [&](auto x, auto y) {
		return x.Y < y.Y;
		});

	A.insert(A.begin(), { {0, 0}, 0 });
	B.insert(B.begin(), { {0, 0}, 0 });

	solve(0, A.size() - 1, 0, B.size() - 1);
	if (res == 2e9)cout << -1;
	else cout << res;
}
