#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double

int l, r;
int a[(int)1e6 + 6];

struct DSU {
	int par[(int)1e6 + 6];
	int sz[(int)1e6 + 6];

	DSU() {
		FOR(i, 0, 1e6) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	int find(int u) {
		if (par[u] == u)return u;

		return par[u] = find(par[u]);
	}

	void merge(int u, int v) { //v -> u
		u = find(u);
		v = find(v);

		par[v] = u;
		sz[u] += sz[v];
	}
}dsu;

void fold(int x) {
	x = dsu.find(x);

	if (x - l <= r - x) {
		FOD(i, x - 1, l) {
			int j = x + x - i;

			dsu.merge(j, i);
		}

		l = x;
	}
	else {
		FOR(j, x + 1, r) {
			int i = x + (x - j);

			dsu.merge(i, j);
		}

		r = x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("bando.inp", "r")) {
		freopen("bando.inp", "r", stdin);
		freopen("bando.out", "w", stdout);
	}

	int n, k;
	cin >> n >> k;

	l = 0, r = n;

	while (k--) {
		int x;
		cin >> x;

		fold(x);
	}

	cout << r - l + 1 << endl;
	FOR(i, l, r) {
		cout << dsu.sz[dsu.find(i)] << ' ';
	}
}
