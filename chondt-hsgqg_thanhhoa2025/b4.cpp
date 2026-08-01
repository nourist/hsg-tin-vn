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

int par[(int)3e5 + 5];
int sz[(int)3e5 + 5];
int type[(int)3e5 + 5];
int deg[(int)3e5 + 5];

int find(int u) {
	if (par[u] == u)return u;
	return par[u] = find(par[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (sz[u] < sz[v])swap(u, v);

	par[v] = u;
	sz[u] += sz[v];
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

	FOR(i, 1, n) {
		par[i] = i;
		sz[i] = 1;
	}

	int res = 0;
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		if (find(u) == find(v)) {
			if (type[find(u)] == 0 && deg[u] == 1 && deg[v] == 1) {
				res++;
				type[find(u)] = 1;
			}
			else if (type[find(u)] == 1) {
				res--;
				type[find(u)] = 2;
			}
		}
		else {
			if (type[find(u)] == 1) {
				res--;
			}
			if (type[find(v)] == 1) {
				res--;
			}
			if (type[find(u)] == 1 || type[find(v)] == 1) {
				merge(u, v);
				type[find(u)] = 2;
			}
			else if (deg[u] >= 2 || deg[v] >= 2) {
				merge(u, v);
				type[find(u)] = 2;
			}
			else {
				merge(u, v);
			}
		}
		deg[u]++;
		deg[v]++;
		cout << res << endl;
	}
}
