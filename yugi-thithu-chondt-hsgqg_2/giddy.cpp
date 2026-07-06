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
#define Name "giddy"

vii adj[(int)5e4 + 4];

void dijkstra(int dist[], priority_queue<pii, vii, greater<pii>>q) {
	while (!q.empty()) {
		auto from = q.top();
		q.pop();

		int d = from.X;
		int u = from.Y;

		if (d != dist[u])continue;

		for (auto to : adj[u]) {
			int v = to.X;
			int w = to.Y;

			if (d + w < dist[v]) {
				dist[v] = d + w;
				q.push({ dist[v], v });
			}
		}
	}
}

int dist1[(int)5e4 + 4];
int dist2[(int)5e4 + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m, k;
	cin >> n >> m >> k;
	FOR(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}

	FOR(i, 1, n)dist1[i] = 1e9;
	priority_queue<pii, vii, greater<pii>>q;

	dist1[n] = 0;
	q.push({ 0, n });

	dijkstra(dist1, q);

	while (!q.empty())q.pop();

	FOR(i, 1, n)dist2[i] = 1e9;
	FOR(i, 1, k) {
		int p, c;
		cin >> p >> c;
		dist2[p] = dist1[p] - c;
		q.push({ dist2[p], p });
	}

	dijkstra(dist2, q);
	FOR(i, 1, n - 1) {
		cout << (dist2[i] <= dist1[i]) << endl;
	}
}

/*
tk - tn <= ck
d[k][i] + d[k][n] - c[k] <= d[i][n]

*/