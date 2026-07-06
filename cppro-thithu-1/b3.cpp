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
#define Name "NUMBER"

int n, mod;
vii adj[(int)1e5 + 5];

int w[(int)1e5 + 5];
int sz[(int)1e5 + 5];
int depth[(int)1e5 + 5];
int par[(int)1e5 + 5];

void dfs(int u) {
	sz[u] = 1;

	for (auto e : adj[u]) {
		int v = e.X;

		if (v == par[u])continue;

		depth[v] = depth[u] + 1;
		w[v] = e.Y;
		par[v] = u;
		dfs(v);

		sz[u] += sz[v];
	}
}

int chainId[(int)1e5 + 5], chainHead[(int)1e5 + 5];
int pos[(int)1e5 + 5], arr[(int)1e5 + 5];
int curChain = 1, curPos = 1;

void hld(int u) {
	if (!chainHead[curChain]) {
		chainHead[curChain] = u;
	}
	chainId[u] = curChain;
	pos[u] = curPos;
	arr[curPos] = w[u];
	curPos++;

	int nxt = 0;
	for (auto e : adj[u]) {
		int v = e.X;

		if (v == par[u])continue;

		if (sz[v] > sz[nxt])nxt = v;
	}

	if (nxt != 0)hld(nxt);

	for (auto e : adj[u]) {
		int v = e.X;

		if (v == par[u] || v == nxt)continue;

		curChain++;
		hld(v);
	}
}

int lca(int u, int v) {
	while (chainId[u] != chainId[v]) {
		if (depth[chainHead[chainId[u]]] > depth[chainHead[chainId[v]]]) {
			u = par[chainHead[chainId[u]]];
		}
		else {
			v = par[chainHead[chainId[v]]];
		}
	}
	if (depth[u] < depth[v])return u;
	return v;
}

ll pow10[(int)1e5 + 5];

struct Node {
	int v1, v2, len;
};

Node operator + (const Node& a, const Node& b) {
	return { (1LL * a.v1 * pow10[b.len] % mod + b.v1) % mod, (1LL * b.v2 * pow10[a.len] % mod + a.v2) % mod ,a.len + b.len };
}

Node st[(int)4e5 + 5];

Node rev(Node x) {
	return { x.v2, x.v1, x.len };
}

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = { arr[l], arr[l], 1 };
		return;
	}

	int mid = l + r >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

Node stQuery(int id, int l, int r, int u, int v) {
	if (r<u || l>v)return { 0,0,0 };
	if (u <= l && v >= r)return st[id];

	int mid = l + r >> 1;
	return stQuery(id * 2, l, mid, u, v) + stQuery(id * 2 + 1, mid + 1, r, u, v);
}

int query(int u, int v) {
	int g = lca(u, v);

	vector<Node> L, R;

	while (chainId[u] != chainId[g]) {
		L.pb(stQuery(1, 1, n, pos[chainHead[chainId[u]]], pos[u]));
		u = par[chainHead[chainId[u]]];
	}

	while (chainId[v] != chainId[g]) {
		R.pb(stQuery(1, 1, n, pos[chainHead[chainId[v]]], pos[v]));
		v = par[chainHead[chainId[v]]];
	}

	if (depth[u] < depth[v]) {
		if (pos[u] + 1 <= pos[v])
			R.pb(stQuery(1, 1, n, pos[u] + 1, pos[v]));
	}
	else {
		if (pos[v] + 1 <= pos[u])
			L.pb(stQuery(1, 1, n, pos[v] + 1, pos[u]));
	}

	reverse(R.begin(), R.end());

	Node res = { 0 ,0,0 };
	for (auto it : L)res = res + rev(it);
	for (auto it : R)res = res + it;
	return res.v1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> mod;
	FOR(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}

	pow10[0] = 1;
	FOR(i, 1, 1e5)pow10[i] = pow10[i - 1] * 10 % mod;

	dfs(1);
	hld(1);

	build(1, 1, n);

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << query(u, v) << '\n';
	}
}
