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
#define Name "manage"

int t[1003];
int posOfMan[1003];// vị trí trên mảng của x
int manOfPos[1003];// người nào đang trên mảng
vi adj[1003];
bitset<1003> mask[1003];
vi parents[1003];
bool visited[1003];

void dfs(int u) {
	if (visited[u])return;
	visited[u] = 1;

	for (int v : adj[u]) {
		if (!visited[v])dfs(v);
		mask[u] = mask[u] | mask[v];
		mask[u].set(v, 1);
	}

	// sort(all(parents[u]));
	// parents[u].erase(unique(all(parents[u])), parents[u].end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m, q;
	cin >> n >> m >> q;

	FOR(i, 1, n)cin >> t[i];
	FOR(i, 1, n) {
		posOfMan[i] = i;
		manOfPos[i] = i;
	}
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[v].pb(u);
	}

	FOR(i, 1, n)dfs(i);
	FOR(i, 1, n)FOR(j, 1, n) {
		if (mask[i][j]) {
			parents[i].pb(j);
		}
	}

	while (q--) {
		int T;
		cin >> T;
		if (T == 1) {
			int u, v;
			cin >> u >> v;
			int oldU = posOfMan[u];
			int oldV = posOfMan[v];
			swap(manOfPos[oldU], manOfPos[oldV]);
			swap(posOfMan[u], posOfMan[v]);
		}
		else {
			int x;
			cin >> x;
			x = posOfMan[x];
			int res = 1e9;
			for (int v : parents[x]) {
				res = min(res, t[manOfPos[v]]);
			}
			cout << (res == 1e9 ? 0 : res) << endl;
		}
	}
}
