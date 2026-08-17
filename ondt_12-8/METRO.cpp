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
#define Name "METRO"

vii adj[(int)1e5 + 5];
unordered_map<int, int> dist[(int)1e5 + 5];

struct Node {
	int d, u, c;

	bool operator > (const Node& other) const {
		return d > other.d;
	}
};

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

	FOR(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}

	const int INF = 1e9;

	priority_queue<Node, vector<Node>, greater<Node>> pq;

	dist[1][-1] = 0;
	pq.push({ 0, 1, -1 });

	while (!pq.empty()) {
		auto [d, u, c] = pq.top();
		pq.pop();

		if (dist[u][c] != d)
			continue;

		for (auto [v, w] : adj[u]) {
			int nd = d + (c != w);

			auto it = dist[v].find(w);

			if (it == dist[v].end()) {
				dist[v][w] = nd;
				pq.push({ nd, v, w });
			}
			else if (it->second > nd) {
				it->second = nd;
				pq.push({ nd, v, w });
			}
		}
	}

	int res = INF;

	for (auto [color, d] : dist[n]) {
		res = min(res, d);
	}

	if (res == INF)
		cout << -1;
	else
		cout << res;

	return 0;
}