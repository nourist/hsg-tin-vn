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
#define Name "caytao"

int n, k, q;
int a[(int)1e5 + 5];
int c[(int)1e5 + 5];
vi adj[(int)1e5 + 5];

vii factA[(int)1e5 + 5];
vii compFactA[(int)1e5 + 5];

int cnt = 1;
int tour[(int)2e5 + 5];
int st[(int)1e5 + 5];
int en[(int)1e5 + 5];
int depth[(int)1e5 + 5];
int up[(int)1e5 + 5][20];

void dfs(int u = 1) {
	st[u] = cnt;
	tour[cnt++] = u;

	for (int v : adj[u]) {
		if (v == up[u][0])continue;

		depth[v] = depth[u] + 1;
		up[v][0] = u;

		dfs(v);
	}

	en[u] = cnt;
	tour[cnt++] = u;
}

void preprocess() {
	FOR(k, 1, 16)FOR(i, 1, n)
		up[i][k] = up[up[i][k - 1]][k - 1];
}

int lca(int u, int v) {
	if (depth[u] > depth[v])swap(u, v);

	FOD(i, 16, 0)if (depth[v] - (1 << i) >= depth[u])
		v = up[v][i];

	if (u == v)return u;

	FOD(i, 16, 0)if (up[u][i] != up[v][i]) {
		u = up[u][i];
		v = up[v][i];
	}

	return up[u][0];
}

int p[(int)1e6 + 6];

void sieve() {
	FOR(i, 1, 1e6)p[i] = i;
	for (int i = 2; i * i <= 1e6; i++)if (p[i] == i)
		for (int j = i * i; j <= 1e6; j += i)if (p[j] == j)p[j] = i;
}

vii factorize(int n) {
	vii res;

	while (n != 1) {
		int cur = p[n];
		int cnt = 0;

		while (n % cur == 0) {
			cnt++;
			n /= cur;
		}

		if (cnt % k != 0)
			res.push_back({ cur, cnt % k });
	}
	return res;
}

vii comp(vii v) {
	FOR(i, 0, (int)v.size() - 1) {
		v[i].Y = k - v[i].Y;
	}
	return v;
}

void compress() {
	vector<vii>v;
	FOR(i, 1, n) {
		factA[i] = factorize(a[i]);
		compFactA[i] = comp(factA[i]);

		v.push_back(factA[i]);
		v.push_back(compFactA[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	FOR(i, 1, n) {
		a[i] = lower_bound(v.begin(), v.end(), factA[i]) - v.begin() + 1;
		c[i] = lower_bound(v.begin(), v.end(), compFactA[i]) - v.begin() + 1;
	}
}

struct Query {
	int id, u, v, l, r, a;
	ll res;
}qr[(int)1e5 + 5];

bool inPath[(int)2e5 + 5];
int f[(int)2e5 + 5];
ll res = 0;

void toggle(int x) {//node x
	if (!inPath[x]) {
		res += f[c[x]];
		f[a[x]]++;
	}
	else {
		f[a[x]]--;
		res -= f[c[x]];
	}

	inPath[x] ^= 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> k >> q;

	FOR(i, 1, n)cin >> a[i];

	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs();
	preprocess();
	sieve();
	compress();

	FOR(i, 1, q) {
		cin >> qr[i].u >> qr[i].v;
		qr[i].id = i;

		if (st[qr[i].u] > st[qr[i].v]) {
			swap(qr[i].u, qr[i].v);
		}

		if (en[qr[i].u] >= en[qr[i].v]) {
			qr[i].l = st[qr[i].u];
			qr[i].r = st[qr[i].v];
			qr[i].a = -1;
		}
		else {
			qr[i].l = en[qr[i].u];
			qr[i].r = st[qr[i].v];
			qr[i].a = lca(qr[i].u, qr[i].v);
		}
	}

	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		if (x.r / 450 == y.r / 450) {
			if ((x.r / 450) % 2 == 0)return x.l < y.l;
			else return x.l > y.l;
		}
		return x.r / 450 < y.r / 450;
		});

	int l = 1, r = 0;
	FOR(i, 1, q) {
		while (r < qr[i].r) {
			toggle(tour[++r]);
		}
		while (r > qr[i].r) {
			toggle(tour[r--]);
		}
		while (l > qr[i].l) {
			toggle(tour[--l]);
		}
		while (l < qr[i].l) {
			toggle(tour[l++]);
		}

		if (qr[i].a != -1)toggle(qr[i].a);

		qr[i].res = res;

		if (qr[i].a != -1)toggle(qr[i].a);
	}

	sort(qr + 1, qr + q + 1, [&](Query x, Query y) {
		return x.id < y.id;
		});

	FOR(i, 1, q)cout << qr[i].res << '\n';
}