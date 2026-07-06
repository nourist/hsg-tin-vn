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
#define Name "CANDY"

vi adj[(int)3e5 + 5];
int a[(int)3e5 + 5];

struct BIT {
	ll bit[(int)3e5 + 5];

	void update(int idx, ll v) {
		if (idx == 0)return;
		for (idx; idx <= 3e5; idx += (idx & (-idx)))bit[idx] += v;
	}

	ll query(int idx) {
		ll res = 0;
		for (idx; idx >= 1; idx -= (idx & (-idx)))res += bit[idx];
		return res;
	}

	ll querySum(int l, int r) {
		return query(r) - query(l - 1);
	}
}bit1, bit2;

int par[(int)3e5 + 5];
int depth[(int)3e5 + 5];
int sz[(int)3e5 + 5];

void dfs(int u) {
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v == par[u])continue;

		par[v] = u;
		depth[v] = depth[u] + 1;
		dfs(v);
		sz[u] += sz[v];
	}
}

int pos[(int)3e5 + 5];
int arr[(int)3e5 + 5];
int chainId[(int)3e5 + 5];
int chainHead[(int)3e5 + 5];
int curChain = 1, curPos = 1;

void hld(int u) {
	chainId[u] = curChain;
	if (!chainHead[curChain]) {
		chainHead[curChain] = u;
	}
	pos[u] = curPos;
	arr[curPos] = a[u];
	curPos++;

	int nx = 0;
	for (int v : adj[u]) {
		if (v == par[u])continue;
		if (sz[v] > sz[nx])nx = v;
	}

	if (nx)hld(nx);
	for (int v : adj[u]) {
		if (v == par[u] || v == nx)continue;

		curChain++;
		hld(v);
	}
}

int lca(int u, int v) {
	while (chainId[u] != chainId[v]) {
		if (depth[chainHead[chainId[u]]] < depth[chainHead[chainId[v]]]) {
			v = par[chainHead[chainId[v]]];
		}
		else {
			u = par[chainHead[chainId[u]]];
		}
	}
	if (depth[u] < depth[v])return u;
	return v;
}

void BITupdate(int u, int v, int val) {
	bit1.update(u, 1);
	bit1.update(v + 1, -1);
	bit2.update(u, val);
	bit2.update(v + 1, -val);
}

ll query(ll u) {
	return bit2.query(pos[u]) - bit1.query(pos[u]) * a[u];
}

void update(int u, int v, int val) {
	int g = lca(u, v);

	while (chainId[u] != chainId[g]) {
		BITupdate(pos[chainHead[chainId[u]]], pos[u], val);
		u = par[chainHead[chainId[u]]];
	}
	while (chainId[v] != chainId[g]) {
		BITupdate(pos[chainHead[chainId[v]]], pos[v], val);
		v = par[chainHead[chainId[v]]];
	}
	if (depth[u] < depth[v]) {
		BITupdate(pos[u], pos[v], val);
	}
	else {
		BITupdate(pos[v], pos[u], val);
	}
}

struct Query {
	int s, t, w;
}qr[(int)3e5 + 5];
int id[(int)3e5 + 5];
ll res[(int)3e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, m) {
		cin >> qr[i].s >> qr[i].t >> qr[i].w;
	}

	dfs(1);
	hld(1);

	sort(qr + 1, qr + m + 1, [&](Query x, Query y) {
		return x.w < y.w;
		});

	FOR(i, 1, n)id[i] = i;
	sort(id + 1, id + n + 1, [&](int x, int y) {
		return a[x] < a[y];
		});

	int cur = m + 1;
	FOD(i, n, 1) {
		while (cur - 1 >= 1 && qr[cur - 1].w >= a[id[i]]) {
			cur--;
			update(qr[cur].s, qr[cur].t, qr[cur].w);
		}
		res[id[i]] = query(id[i]);
	}

	FOR(i, 1, n)cout << res[i] << ' ';
}