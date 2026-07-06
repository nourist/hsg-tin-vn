#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = (l); i <= (r); i++)
#define FOD(i,r,l) for (int i = (r); i >= (l); i--)
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
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "electric"

vii steps = { {-1,0}, {1, 0}, {0, -1}, {0, 1} };

int n, m;
struct Node {
	int x, y, v;
}nodes[(int)1e6 + 6];

namespace dsu {
	int par[(int)1e6 + 6];
	int sz[(int)1e6 + 6];
	int used[(int)1e6 + 6];

	void clear() {
		FOR(i, 1, 1e6) {
			par[i] = i;
			sz[i] = 1;
			used[i] = 0;
		}
	}

	int getKey(int x, int y) {
		return (x - 1) * m + y;
	}

	int find(int u) {
		if (par[u] == u)return u;
		return par[u] = find(par[u]);
	}

	bool check(int x, int y, int u, int v) {
		int s = getKey(x, y);
		int t = getKey(u, v);

		return used[s] && used[t] && find(s) == find(t);
	}

	void merge(int x, int y, int s, int t) {
		int u = find(getKey(x, y));
		int v = find(getKey(s, t));

		if (u == v)return;

		if (sz[u] < sz[v])swap(u, v);
		par[v] = u;
		sz[u] += sz[v];
	}

	void add(int x, int y) {
		used[getKey(x, y)] = 1;

		for (auto step : steps) {
			int newx = x + step.X;
			int newy = y + step.Y;

			if (used[getKey(newx, newy)]) {
				merge(x, y, newx, newy);
			}
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

	cin >> n >> m;
	FOR(i, 1, n)FOR(j, 1, m) {
		int v;
		cin >> v;
		nodes[(i - 1) * m + j] = { i ,j ,v };
	}

	sort(nodes + 1, nodes + n * m + 1, [&](Node a, Node b) {
		return a.v < b.v;
		});

	vector<pair<int, pii>>blocks;
	FOR(i, 1, n * m) {
		if (blocks.empty() || blocks.back().X != nodes[i].v) {
			blocks.pb({ nodes[i].v, {i, i} });
		}
		else {
			blocks.back().Y.Y = i;
		}
	}

	int res = 1e9;
	FOR(r, 0, blocks.size() - 1) {
		dsu::clear();
		FOD(l, r, 0) {
			FOR(i, blocks[l].Y.X, blocks[l].Y.Y) {
				dsu::add(nodes[i].x, nodes[i].y);
			}
			if (dsu::check(1, 1, n, m)) {
				res = min(res, blocks[r].X - blocks[l].X);
			}
		}
	}
	cout << res;
}
