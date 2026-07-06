#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
#define Name "MINPATH"

int n, m, p, l, k;
vii adj[(int)1e4 + 4];
vi teleport[(int)1e4 + 4];

namespace solveTeleportNodes {
	int dist[(int)1e4 + 4];

	void calc() {

		FOR(s, 1, n) {
			memset(dist, -1, sizeof dist);
			queue<int>q;

			dist[s] = 0;
			q.push(s);

			while (!q.empty()) {
				int u = q.front();
				q.pop();

				teleport[s].push_back(u);

				if (dist[u] != l) for (auto to : adj[u]) {
					int v = to.X;

					if (dist[v] == -1) {
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}
		}
	}
}

ll dist[(int)1e4 + 4][12];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	cin >> n >> m >> p >> l >> k;

	FOR(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}

	solveTeleportNodes::calc();

	FOR(i, 1, n)FOR(j, 0, 10)dist[i][j] = 1e18;
	dist[1][0] = 0;

	priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>>q;
	q.push({ 0, {1, 0} });

	while (!q.empty()) {
		auto from = q.top();
		q.pop();

		ll d = from.X;
		int u = from.Y.X;
		int used = from.Y.Y;

		if (d != dist[u][used]) continue;

		for (auto to : adj[u]) {
			int v = to.X;
			int w = to.Y;

			if (d + w < dist[v][used]) {
				dist[v][used] = d + w;
				q.push({ d + w,{v, used} });
			}
		}

		if (used != k)
			for (auto v : teleport[u]) {
				if (d + p < dist[v][used + 1]) {
					dist[v][used + 1] = d + p;
					q.push({ d + p, {v, used + 1} });
				}
			}
	}

	ll res = 1e18;
	FOR(i, 0, k)res = min(res, dist[n][i]);
	cout << res;
}
