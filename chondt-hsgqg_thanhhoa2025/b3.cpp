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
#define Name "b3"

vi adj[(int)3e5 + 5];
string s;
int nxt[(int)3e5 + 5][26];
int depth[(int)3e5 + 5];
int up[(int)3e5 + 5][20];

void dfs(int u) {
	FOR(i, 0, 25) {
		if (i == s[u - 1] - 'a') {
			nxt[u][i] = u;
		}
		else {
			nxt[u][i] = nxt[up[u][0]][i];
		}
	}
	for (int v : adj[u]) {
		if (v == up[u][0])continue;

		depth[v] = depth[u] + 1;
		up[v][0] = u;

		dfs(v);
	}
}

int lca(int u, int v) {
	if (depth[u] > depth[v])swap(u, v);

	FOD(i, 18, 0)if (depth[v] - (1 << i) >= depth[u])v = up[v][i];

	if (u == v)return u;

	FOD(i, 18, 0)if (up[v][i] != up[u][i]) {
		v = up[v][i];
		u = up[u][i];
	}

	return up[u][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, q;
	cin >> n >> q >> s;

	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	depth[1] = 1;
	dfs(1);

	FOR(k, 1, 18)FOR(i, 1, n)up[i][k] = up[up[i][k - 1]][k - 1];

	while (q--) {
		int u, v;
		string a, b;
		cin >> u >> v >> a;
		b = a;
		reverse(all(b));

		int g = lca(u, v);

		int l = 0;
		for (u = nxt[u][a[l] - 'a']; depth[u] > depth[g]; u = nxt[u][a[l] - 'a']) {
			l++;
			u = up[u][0];
			if (l == a.size())break;
		}

		int r = 0;
		for (v = nxt[v][b[r] - 'a']; depth[v] >= depth[g]; v = nxt[v][b[r] - 'a']) {
			r++;
			v = up[v][0];
			if (r == a.size())break;
		}

		// cout << l << ' ' << r << endl;

		if (l + r >= a.size())cout << "YES\n";
		else cout << "NO\n";
	}
}
