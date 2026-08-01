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

int n;
int a[(int)1e6 + 6];
int b[(int)1e6 + 6];
vi adj[(int)1e6 + 6];
int f[(int)1e6 + 6];
int g[(int)1e6 + 6];

const int mod = 1e9 + 7;

void dfs(int u, int par) {
	f[u] = a[u] + 1;
	for (int v : adj[u]) {
		if (v == par)continue;
		dfs(v, u);
		f[u] = 1LL * f[u] * f[v] % mod;
	}

	g[u] = (f[u] + mod - 1) % mod;

	for (int v : adj[u]) {
		if (v == par)continue;
		g[u] = (g[u] - (f[v] - 1) + mod) % mod;
	}

	g[u] = 1LL * g[u] * b[u] % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n;
	FOR(i, 1, n)cin >> a[i];
	FOR(i, 1, n)cin >> b[i];
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 0);
	ll res = 0;
	FOR(i, 1, n) { res += g[i]; res %= mod; }
	cout << res;
}