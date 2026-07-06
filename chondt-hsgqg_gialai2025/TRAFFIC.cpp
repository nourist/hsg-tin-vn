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
#define Name "TRAFFIC"

ll dist[404][404];
int a[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	if (fopen(Name".inp", "r")) {
		freopen(Name".inp", "r", stdin);
		freopen(Name".out", "w", stdout);
	}

	ll n, m, q, k, t;
	cin >> n >> m >> q >> k >> t;

	FOR(i, 1, n)FOR(j, 1, n)if (i != j)dist[i][j] = 1e18;
	FOR(i, 1, k)cin >> a[i];
	FOR(i, 1, k)FOR(j, 1, k) {
		dist[a[i]][a[j]] = min(dist[a[i]][a[j]], t);
	}
	FOR(i, 1, m) {
		ll u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = min(dist[v][u], w);
	}

	FOR(k, 1, n)FOR(i, 1, n)FOR(j, 1, n) {
		if (dist[i][k] + dist[k][j] < dist[i][j]) {
			dist[i][j] = dist[i][k] + dist[k][j];
		}
	}

	while (q--) {
		int T;
		cin >> T;
		if (T == 1) {
			ll u, v, w;
			cin >> u >> v >> w;
			FOR(i, 1, n)FOR(j, 1, n) {
				if (dist[i][u] + w + dist[v][j] < dist[i][j]) {
					dist[i][j] = dist[i][u] + w + dist[v][j];
				}
				if (dist[i][v] + w + dist[u][j] < dist[i][j]) {
					dist[i][j] = dist[i][v] + w + dist[u][j];
				}
			}
		}
		else if (T == 2) {
			int x;
			cin >> x;
			FOR(e, 1, k) {
				int u = x;
				int v = a[e];
				int w = t;
				if (t < dist[u][v]) {
					FOR(i, 1, n)FOR(j, 1, n) {
						if (dist[i][u] + w + dist[v][j] < dist[i][j]) {
							dist[i][j] = dist[i][u] + w + dist[v][j];
						}
						if (dist[i][v] + w + dist[u][j] < dist[i][j]) {
							dist[i][j] = dist[i][v] + w + dist[u][j];
						}
					}
				}
			}
			FOR(e, 1, k) {
				int u = a[e];
				int v = x;
				int w = t;
				if (t < dist[u][v]) {
					FOR(i, 1, n)FOR(j, 1, n) {
						if (dist[i][u] + w + dist[v][j] < dist[i][j]) {
							dist[i][j] = dist[i][u] + w + dist[v][j];
						}
						if (dist[i][v] + w + dist[u][j] < dist[i][j]) {
							dist[i][j] = dist[i][v] + w + dist[u][j];
						}
					}
				}
			}
			k++;
			a[k] = x;
		}
		else {
			ll res = 0;
			FOR(i, 1, n)FOR(j, 1, n)if (dist[i][j] != 1e18)res += dist[i][j];
			cout << res << endl;
		}
	}
}