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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vi adj[(int)4e5 + 5];
int depth[(int)4e5 + 5];
int up[(int)4e5 + 5][19];
int f[(int)4e5 + 5];

void dfs(int u) {
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
	return up[v][0];
}

void final_dfs(int u) {
	for (int v : adj[u]) {
		if (v == up[u][0])continue;
		final_dfs(v);
		f[u] += f[v];
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

	cin >> n;
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);
	FOR(k, 1, 18)FOR(i, 1, n)up[i][k] = up[up[i][k - 1]][k - 1];
	FOR(v, 2, n) {
		int u = v - 1;
		int g = lca(u, v);
		f[u]++;
		f[v]++;
		f[g]--;
		f[up[g][0]]--;
	}
	final_dfs(1);
	FOR(i, 1, n)cout << f[i] << endl;
}
