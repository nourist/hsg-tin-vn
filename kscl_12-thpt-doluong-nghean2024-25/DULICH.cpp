#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; ++i)
#define FOD(i,r,l) for (int i = r; i >= l; --i)
#define ll long long
#define ld long double
#define X first
#define Y second

int n, m;
vector<pair<int, int>> adj[(int)1e5 + 5];
ll dist[(int)1e5 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen("DULICH.inp", "r")) {
		freopen("DULICH.inp", "r", stdin);
		freopen("DULICH.out", "w", stdout);
	}

	cin >> n >> m;
	FOR(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	FOR(i, 2, n)dist[i] = 1e18;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();

		ll du = top.X;
		int u = top.Y;

		if (du != dist[u])continue;

		for (auto edge : adj[u]) {
			int v = edge.X;
			int w = edge.Y;

			if (dist[v] > du + w) {
				dist[v] = du + w;
				pq.push({ dist[v], v });
			}
		}
	}

	FOR(i, 1, n) {
		if (dist[i] == 1e18)cout << -1 << ' ';
		else cout << dist[i] << ' ';
	}
}
