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
#define pib pair<int,bool>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vib vector<pib>
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define TURNON(x, i) ((x) | (1LL << (i)))
#define TURNOFF(x, i) ((x) & ~(1LL << (i)))
#define TURN(x, i) ((x) ^ (1LL << (i)))
#define Name "XEBUYT"

int n, m, s, t, u, v;
vii adj[(int)1e5 + 5];
vii shortestPathAdj[(int)3e5 + 35];
ll dist1[(int)1e5 + 5];
ll dist2[(int)3e5 + 35];
bool visited[(int)1e5 + 5];

void dijkstra(vii adj[], int n, ll dist[], int s) {
	priority_queue<pll, vll, greater<pll>>q;
	FOR(i, 1, n)dist[i] = 1e18;

	dist[s] = 0;
	q.push({ 0, s });

	while (!q.empty()) {
		auto from = q.top();
		q.pop();

		ll d = from.X;
		ll u = from.Y;

		if (d > dist[u])continue;

		for (auto to : adj[u]) {
			ll v = to.X;
			ll w = to.Y;

			if (d + w < dist[v]) {
				dist[v] = d + w;
				q.push({ dist[v], v });
			}
		}
	}
}

void dfs(int u) {
	if (visited[u])return;
	visited[u] = 1;

	for (auto to : adj[u]) {
		ll v = to.X;
		ll w = to.Y;

		if (dist1[u] == dist1[v] + w) {
			shortestPathAdj[v + (int)1e5].push_back({ u + (int)1e5, 0 });
			// cout << u << ' ' << v << endl;
			dfs(v);
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

	cin >> n >> m >> s >> t >> u >> v;

	FOR(i, 1, m) {
		ll x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({ y, w });
		adj[y].push_back({ x, w });
	}

	dijkstra(adj, n, dist1, s);
	dfs(t);

	FOR(i, 1, n) {
		shortestPathAdj[i] = shortestPathAdj[i + (int)2e5] = adj[i];

		shortestPathAdj[i].push_back({ i + (int)1e5, 0 });
		shortestPathAdj[i + (int)1e5].push_back({ i + (int)2e5, 0 });
	}

	dijkstra(shortestPathAdj, 3e5, dist2, u);
	cout << dist2[v + (int)2e5];
}