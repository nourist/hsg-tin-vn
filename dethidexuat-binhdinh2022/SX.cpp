#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define X first 
#define Y second 

struct DSU {
	int par[(int)1e5 + 5];
	int sz[(int)1e5 + 5];

	DSU() {
		FOR(i, 1, 1e5) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	int find(int u) {
		if (par[u] == u)return par[u];

		return par[u] = find(par[u]);
	}

	void join(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v)return;

		if (sz[u] > sz[v]) {
			par[v] = u;
			sz[u] += sz[v];
		}
		else {
			par[u] = v;
			sz[v] += sz[u];
		}
	}
}dsu;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("SX.inp", "r")) {
		freopen("SX.inp", "r", stdin);
		freopen("SX.out", "w", stdout);
	}

	int n, m;
	cin >> n >> m;

	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		dsu.join(u, v);
	}

	map<int, int>mp;
	FOR(i, 1, n) {
		mp[dsu.find(i)] = dsu.sz[dsu.find(i)];
	}

	vector<pii>v;

	for (auto it : mp) {
		v.push_back({ it.Y, it.X });
	}

	sort(v.begin(), v.end(), greater<pii>());

	if (v.size() == 1) {
		cout << v[0].X;
	}
	else {
		cout << v[0].X + v[1].X;
	}
}
