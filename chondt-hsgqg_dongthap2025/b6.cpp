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
#define Name "MKGRAPH"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n;
	cin >> n;

	set<pii, greater<pii>> st;
	FOR(i, 1, n) {
		int d;
		cin >> d;
		if (d > 0) st.insert({ d, i });
	}

	vii edges;

	while (!st.empty()) {
		auto u = *st.begin();
		st.erase(st.begin());

		if (u.X == 0) break;

		vii t;

		for (auto it = st.begin(); it != st.end();) {
			edges.pb({ u.Y, it->Y });
			u.X--;

			auto prev = *it;
			it = st.erase(it);

			if (prev.X > 1) t.pb({ prev.X - 1, prev.Y });

			if (u.X == 0) break;
		}

		for (auto it : t) st.insert(it);
	}

	vi par(n + 1);
	iota(all(par), 0);
	function<int(int)> find_set = [&](int v) {
		return v == par[v] ? v : par[v] = find_set(par[v]);
		};
	auto join_set = [&](int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) { par[b] = a; return true; }
		return false;
		};

	vi cycle_edges;
	FOR(i, 0, (int)edges.size() - 1) {
		if (!join_set(edges[i].X, edges[i].Y)) {
			cycle_edges.pb(i);
		}
	}

	vi rep_edge(n + 1, -1);
	FOR(i, 0, (int)edges.size() - 1) {
		int root = find_set(edges[i].X);
		if (rep_edge[root] == -1) {
			rep_edge[root] = i;
		}
	}

	vi valid_reps;
	FOR(i, 1, n) {
		if (par[i] == i && rep_edge[i] != -1) {
			valid_reps.pb(rep_edge[i]);
		}
	}

	for (int ce_idx : cycle_edges) {
		if (valid_reps.size() <= 1) break;

		int u = edges[ce_idx].X;
		int root_u = find_set(u);

		int swap_idx = -1;
		for (size_t i = 0; i < valid_reps.size(); i++) {
			int r_edge = valid_reps[i];
			if (find_set(edges[r_edge].X) != root_u) {
				swap_idx = r_edge;
				valid_reps[i] = valid_reps.back();
				valid_reps.pop_back();
				break;
			}
		}

		if (swap_idx != -1) {
			int v = edges[ce_idx].Y;
			int x = edges[swap_idx].X;
			int y = edges[swap_idx].Y;

			edges[ce_idx] = { u, x };
			edges[swap_idx] = { v, y };

			join_set(u, x);
		}
	}

	for (auto e : edges) {
		cout << e.X << ' ' << e.Y << endl;
	}

	return 0;
}