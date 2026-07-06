#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for (int i = l; i <= r; i++)
#define FOD(i,r,l) for (int i = r; i >= l; i--)
#define ll long long
#define ld long double
#define X first
#define Y second
#define Name "souv"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define X first 
#define Y second 

int n, m, k, p;
int a[102];
int c[102];
ll dist[102][(int)1e4 + 4];
vector<pii>adj[(int)1e4 + 4];

void dijkstra(int s, ll dist[]) {
	FOR(i, 1, n)dist[i] = 1e18;
	dist[s] = 0;

	priority_queue<pll, vector<pll>, greater<pll>>q;
	q.push({ 0, s });

	while (!q.empty()) {
		pll from = q.top();
		q.pop();

		ll d = from.X, u = from.Y;

		if (d > dist[u])
			continue;

		for (pll to : adj[u]) {
			int w = to.Y, v = to.X;

			if (dist[v] > d + w) {
				dist[v] = d + w;
				q.push({ dist[v],v });
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

	cin >> n >> m >> k >> p;
	FOR(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	FOR(i, 1, k) {
		cin >> a[i] >> c[i];
	}

	FOR(i, 1, k) {
		dijkstra(a[i], dist[i]);
	}

	FOR(i, 1, p) {
		int s, f;
		cin >> s >> f;

		ll res = 9e18;
		FOR(j, 1, k) {
			res = min(res, dist[j][s] + dist[j][f] + c[j]);
		}
		if (res == 9e18)cout << -1 << endl;
		else cout << res << endl;
	}
}