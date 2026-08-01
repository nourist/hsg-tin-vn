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
#define Name "b4"

int n, m;
vi adj[(int)1e5 + 5];

int timeDfs = 0;
int num[(int)1e5 + 5];
int low[(int)1e5 + 5];
int comp[(int)1e5 + 5];
int deg[(int)1e5 + 5];

void dfs(int u, int par) {
	num[u] = low[u] = ++timeDfs;

	int childs = 0;
	int cnt = 0;

	for (int v : adj[u]) {
		if (v == par)continue;

		if (!num[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			childs++;
			if (low[v] >= num[u])cnt++;
		}
		else {
			low[u] = min(low[u], num[v]);
		}
	}

	if (par == 0)comp[u] = childs - 1;
	else comp[u] = cnt;
}

void solve() {
	cin >> n >> m;
	memset(deg, 0, sizeof deg);
	FOR(i, 1, n)adj[i].clear();
	timeDfs = 0;
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		deg[u]++;
		deg[v]++;
	}

	memset(num, 0, sizeof num);
	memset(low, 0, sizeof low);
	memset(comp, 0, sizeof comp);

	int C = 0;
	FOR(i, 1, n)if (!num[i]) {
		dfs(i, 0);
		C++;
	}

	if (C == n - m) {
		cout << -1 << endl;
	}
	else {
		FOR(i, 1, n) {
			if (C + comp[i] == n - 1 - m + deg[i]) {
				cout << i << endl;
				return;
			}
		}
		cout << -1 << endl;
	}
}

/*
c = v - e
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int t;
	cin >> t;
	while (t--)	solve();
}
