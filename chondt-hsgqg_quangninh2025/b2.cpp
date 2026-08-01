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

vi adj[(int)1e5 + 5];
bool s[(int)1e5 + 5];
bool visited[(int)1e5 + 5];

vi path;

void dfs(int u) {
	visited[u] = 1;
	for (int v : adj[u])if (!visited[v]) {
		path.push_back(v);
		s[v] ^= 1;

		dfs(v);

		s[u] ^= 1;
		path.push_back(u);

		if (!s[v]) {
			s[v] ^= 1;
			path.push_back(v);
			s[u] ^= 1;
			path.push_back(u);
		}
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

	int n, m;
	cin >> n >> m;
	FOR(i, 1, n)cin >> s[i];
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	s[1] ^= 1;
	path.push_back(1);

	dfs(1);

	if (s[1] == 0) {
		int v = adj[1][0];
		path.push_back(v);
		path.push_back(1);
		path.push_back(v);
	}

	cout << path.size() << endl;
	for (int i : path)cout << i << ' ';
}
