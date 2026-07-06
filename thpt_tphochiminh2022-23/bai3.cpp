#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int inf = 1e9;
int n, m, k, s, t;
vector<pair<int, int>>Sedge[(int)1e6+4];
vector<pair<int, int>>Tedge[(int)1e6+4];
int from[(int)1e6 + 4], to[(int)1e6 + 4];

int dijkstra(int dist[],vector<pair<int,int>> adj[], int s) {
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
	dist[s] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({ 0,s });

	while (!q.empty()) {
		pair<int, int>top = q.top();
		q.pop();

		int u = top.second;

		if(top.first>dist[u])continue;

		for (auto it : adj[u]) {
			int w = it.second;
			int v = it.first;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				q.push({ dist[v], v });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if(fopen("bai3.inp", "r")) {
		freopen("bai3.inp", "r", stdin);
		freopen("bai3.out", "w", stdout);
	}

	cin >> n >> m >> k >> s >> t;
	for (int u,v,w, i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		Sedge[u].push_back({ v,w });
		Tedge[v].push_back({ u,w });
	}

	dijkstra(from, Tedge, t);
	dijkstra(to, Sedge, s);

	int res = to[t];
	int u, v, w;
	while (k--) {
		cin >> u >> v >> w;
		res = min({ res, from[u] + to[v] + w,from[v] + to[u] + w });
	}

	if (res == inf)cout << -1;
	else cout << res;
}
