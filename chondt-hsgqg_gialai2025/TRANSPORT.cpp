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
#define Name "TRANSPORT"

int n, m;
vi adj[(int)5e4 + 4];
int w[(int)5e4 + 4];
int f[(int)5e4 + 4][2];
bool visited[(int)5e4 + 4];
bool color[(int)5e4 + 4];

int dfs(int u) {
	f[u][color[u]] += w[u];
	visited[u] = 1;

	for (int v : adj[u]) {
		if (visited[v]) {
			if (color[v] == color[u]) {
				return -1;
			}
		}
		else {
			color[v] = !color[u];
			if (dfs(v) == -1)return -1;
			else {
				f[u][0] += f[v][0];
				f[u][1] += f[v][1];
			}
		}
	}
	return 0;
}

bitset <(int)2e6>bs;

void solve() {
	unordered_map<int, int>mp;

	memset(f, 0, sizeof f);
	memset(visited, 0, sizeof visited);
	memset(color, 0, sizeof color);

	FOR(i, 1, n)if (!visited[i]) {
		if (dfs(i) == -1) {
			cout << 0 << endl;
			return;
		}
		mp[(f[i][0] - f[i][1])]++;
	}

	vi v;
	for (auto it : mp) {
		int s = 0;
		for (int k = 1; s <= it.Y; k *= 2) {
			if (s + k <= it.Y) {
				v.pb(k * it.X);
			}
			else {
				v.pb((it.Y - s) * it.X);
			}
			s += k;
		}
	}

	bs = 0;
	bs[1e6] = 1;
	for (int x : v) {
		if (x >= 0)
			bs = bs | (bs << x);
		else
			bs = bs | (bs >> abs(x));
	}
	cout << (int)bs.count() << endl;
}

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
	while (t--) {
		cin >> n >> m;
		FOR(i, 1, n)adj[i].clear();
		FOR(i, 1, n)cin >> w[i];
		FOR(i, 1, m) {
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		solve();
	}
}