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
#define Name "TINHPHI"

int n, m, k, s, t;
vii adj[(int)1e5 + 5];
ll dist[(int)1e5 + 5][12];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	int n, m, k, s, t;
	cin >> n >> m >> k >> s >> t;
	FOR(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({ v,w });
		adj[v].pb({ u,w });
	}

	FOR(i, 1, n)FOR(j, 0, k)dist[i][j] = 1e18;
	priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>>q;

	dist[s][0] = 0;
	q.push({ 0, {s, 0} });

	while (!q.empty()) {
		auto from = q.top();
		q.pop();

		ll d = from.X;
		int u = from.Y.X, j = from.Y.Y;

		if (d != dist[u][j])continue;

		for (auto to : adj[u]) {
			int v = to.X;
			int w = to.Y;

			if (d + w < dist[v][j]) {
				dist[v][j] = d + w;
				q.push({ dist[v][j], { v, j} });
			}
			if (j != k && d < dist[v][j + 1]) {
				dist[v][j + 1] = d;
				q.push({ dist[v][j + 1], { v, j + 1} });
			}
		}
	}
	ll res = 1e18;
	FOR(i, 0, k)res = min(res, dist[t][i]);
	cout << res;
}
