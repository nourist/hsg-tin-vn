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
#define Name "tour"

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());

ll dp[(int)2e5 + 5];
int s[(int)2e5 + 5];
bool p[(int)2e5 + 5];
vi adj[(int)2e5 + 5];

ll res = -1e18;

void dfs(int u, int par) {
	dp[u] = p[u] ? s[u] : -1e18;
	vl t;
	for (int v : adj[u]) {
		if (v == par)continue;

		dfs(v, u);
		dp[u] = max(dp[u], dp[v] + s[u]);
		t.pb(dp[v]);
	}

	sort(all(t));
	if (t.size() >= 2) {
		res = max(res, t.back() + t[t.size() - 2] + s[u]);
	}

	if (t.size() >= 1)
		if (p[u])res = max(res, s[u] + t.back());

	if (p[u])res = max(res, 1LL * s[u]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for (int i = 2; i * i <= 2e5; i++)if (p[i])for (int j = i * i; j <= 2e5; j += i)p[j] = 0;

	int n;
	cin >> n;
	FOR(i, 1, n)cin >> s[i];
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	cout << res;
}

